#include "inject.h"

#include <iostream>
#include "util.h"

bool Inject(HANDLE hProcess, const std::string& dllPath)
{
	if (GetFileAttributesA(dllPath.c_str()) == INVALID_FILE_ATTRIBUTES)
	{
		std::cerr << "DLL file not found: " << dllPath << std::endl;
		return false;
	}

	auto pPath = VirtualAllocEx(hProcess, nullptr, dllPath.length() + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (pPath == nullptr)
	{
		std::cerr << "VirtualAllocEx failed: " << util::GetLastErrorAsString() << std::endl;
		return false;
	}
	
	if (!WriteProcessMemory(hProcess, pPath, dllPath.c_str(), dllPath.length() + 1, nullptr)) 
	{
		std::cerr << "WriteProcessMemory failed: " << util::GetLastErrorAsString() << std::endl;
		VirtualFreeEx(hProcess, pPath, 0, MEM_RELEASE);
		return false;
	}

	auto hThread = CreateRemoteThread(hProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, pPath, 0, nullptr);
	if (!hThread)
	{
		std::cerr << "CreateRemoteThread failed: " << util::GetLastErrorAsString() << std::endl;
		VirtualFreeEx(hProcess, pPath, 0, MEM_RELEASE);
		return false;
	}

	WaitForSingleObject(hThread, INFINITE);
	VirtualFreeEx(hProcess, pPath, 0, MEM_RELEASE);
	CloseHandle(hThread);

	return true;
}