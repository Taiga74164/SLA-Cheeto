#include "Memory.h"

std::unordered_map<void*, Memory::PatchInfo> Memory::patches;

void Memory::PatchBytes(void* address, const char* bytes, size_t len)
{
	auto it = patches.find(address);
	if (it == patches.end())
	{
		// If a patch doesn't exist, create a new one.
		PatchInfo info;
		info.address = address;
		info.originalBytes.resize(len);
		memcpy(info.originalBytes.data(), address, len);
		// Store the patch info.
		patches[address] = info;
	}

	// Patch the bytes.
	DWORD oldProtect;
	VirtualProtect(address, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(address, bytes, len);
	VirtualProtect(address, len, oldProtect, &oldProtect);
}

void Memory::PatchBytes(uintptr_t address, const char* bytes)
{
	PatchBytes(reinterpret_cast<void*>(address), bytes, strlen(bytes));
}

template <size_t N>
void Memory::PatchBytes(uintptr_t address, const BYTE(&bytes)[N])
{
	PatchBytes(reinterpret_cast<void*>(address), bytes, N);
}

void Memory::NopBytes(uintptr_t address, const size_t len)
{
	std::vector<char> nops(len, 0x90);
	PatchBytes(reinterpret_cast<void*>(address), nops.data(), len);
}

void Memory::RestoreBytes(uintptr_t address)
{
	auto it = patches.find(reinterpret_cast<void*>(address));
	if (it != patches.end())
	{
		// Restore the original bytes.
		const auto& info = it->second;
		DWORD oldProtect;
		VirtualProtect(info.address, info.originalBytes.size(), PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(info.address, info.originalBytes.data(), info.originalBytes.size());
		VirtualProtect(info.address, info.originalBytes.size(), oldProtect, &oldProtect);

		// Remove the patch info.
		patches.erase(it);
	}
}

void Memory::RestoreBytes(std::initializer_list<uintptr_t> address)
{
	for (const auto addr : address)
		RestoreBytes(addr);
}

uintptr_t Memory::PatternScan(uintptr_t module, const char* signature)
{
	static auto patternToByte = [](const char* pattern)
	{
		auto       bytes = std::vector<int>{};
		const auto start = const_cast<char*>(pattern);
		const auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(-1);
			}
			else
			{
				bytes.push_back(strtoul(current, &current, 16));
			}
		}
		return bytes;
	};

	const auto dosHeader = (PIMAGE_DOS_HEADER)module;
	const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)module + dosHeader->e_lfanew);

	const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto       patternBytes = patternToByte(signature);
	const auto scanBytes = reinterpret_cast<std::uint8_t*>(module);

	const auto s = patternBytes.size();
	const auto d = patternBytes.data();

	for (auto i = 0ul; i < sizeOfImage - s; ++i)
	{
		bool found = true;
		for (auto j = 0ul; j < s; ++j)
		{
			if (scanBytes[i + j] != d[j] && d[j] != -1)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			// return reinterpret_cast<uintptr_t>(&scanBytes[i]);
			// Return the address of the pattern.
			return module + i;
		}
	}
	return NULL;
}

void* Memory::AllocateNearbyMemory(uintptr_t address, size_t size)
{
	// Get the system allocation granularity.
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	// Calculate the start and end addresses.
	auto start = (address > si.dwAllocationGranularity) ? (address - si.dwAllocationGranularity) : 0;
	auto end = address + si.dwAllocationGranularity;

	// Iterate through the memory range and find a suitable location.
	MEMORY_BASIC_INFORMATION mbi;
	while (start < end && VirtualQuery((LPCVOID)start, &mbi, sizeof(mbi)))
	{
		// If the memory is free and large enough, allocate it.
		if (mbi.State == MEM_FREE && mbi.RegionSize >= size)
		{
			auto ptr = VirtualAlloc((LPVOID)start, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (ptr)
				return ptr;
		}

		// Move to the next memory region.
		start += si.dwAllocationGranularity;
	}

	// If we couldn't find a suitable location, just allocate the memory anywhere.
	return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
}

void Memory::CreateTrampoline(uintptr_t address, void* destination, size_t length)
{
	// Check if the length is at least 14 bytes.
	if (length < 14) return;

	// Create a byte array based on the length.
	std::vector<BYTE> trampoline(length, 0x90);

	// Set the jmp [rip] opcode.
	trampoline[0] = 0xFF;
	trampoline[1] = 0x25;
	memset(&trampoline[2], 0, 4);

	// Copy the destination address to the place holder of the trampoline.
	memcpy(&trampoline[6], &destination, 8);

	auto it = patches.find(reinterpret_cast<void*>(address));
	if (it != patches.end())
	{
		// If a patch already exists, update the info with the new trampoline.
		it->second.hasTrampoline = true;
		it->second.trampolineDestination = destination;
	}
	else
	{
		// If a patch doesn't exist, create a new one.
		PatchInfo info;
		info.address = reinterpret_cast<void*>(address);
		info.originalBytes.resize(length);
		memcpy(info.originalBytes.data(), reinterpret_cast<void*>(address), length);
		info.hasTrampoline = true;
		info.trampolineDestination = destination;
		// Store the patch info.
		patches[reinterpret_cast<void*>(address)] = info;
	}

	// Patch the original function with the trampoline.
	PatchBytes(reinterpret_cast<void*>(address), reinterpret_cast<const char*>(trampoline.data()), trampoline.size());
}

void Memory::RemoveTrampoline(uintptr_t address)
{
	auto it = patches.find(reinterpret_cast<void*>(address));
	if (it != patches.end())
	{
		if (!it->second.hasTrampoline) return;

		// Free the allocated memory for the trampoline.
		VirtualFree(it->second.trampolineDestination, 0, MEM_RELEASE);

		// Restore the original bytes.
		RestoreBytes(reinterpret_cast<uintptr_t>(it->second.address));
	}
}

void Memory::WriteInstructions(void* destination, const BYTE instructions[], size_t instructionLen, uintptr_t retAddress)
{
	// Calculate the length of the instructions plus the far jump.
	auto length = instructionLen + 14;

	// Create a buffer to store the instructions and the far jump.
	std::vector<BYTE> buffer(length, 0x00);

	// Copy the instructions to the buffer.
	memcpy(buffer.data(), instructions, instructionLen);

	// Set the far jump.
	buffer[instructionLen] = 0xFF;
	buffer[instructionLen + 1] = 0x25;
	memset(&buffer[instructionLen + 2], 0, 4);

	// Copy the return address to the place holder of the far jump.
	memcpy(&buffer[instructionLen + 6], &retAddress, 8);

	// Write the buffer to the trampoline.
	memcpy(destination, buffer.data(), length);
}

void Memory::RestoreAllPatches()
{
	// Iterate through all the patches and restore them.
	for (auto& patch : patches)
	{
		if (patch.second.hasTrampoline)
			RemoveTrampoline(reinterpret_cast<uintptr_t>(patch.second.address));
		else 
			RestoreBytes(reinterpret_cast<uintptr_t>(patch.second.address));
	}
}
