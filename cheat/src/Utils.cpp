#include "Utils.h"
#include <iostream>
#include <TlHelp32.h>
#include <codecvt>
#include <cstdarg>
#include <psapi.h>
#include <mutex>
#include <random>

std::mutex mutex;

void Utils::AttachConsole()
{
	AllocConsole();
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
	SetConsoleOutputCP(CP_UTF8);
}

void Utils::DetachConsole()
{
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
	FreeConsole();
}

void Utils::ConsolePrint(const char* filepath, int line, const char* fmt, ...)
{
	char buf[4096];

	va_list va;
	va_start(va, fmt);
	vsprintf_s(buf, fmt, va);
	va_end(va);

	const std::lock_guard<std::mutex> lock(mutex);

	auto filename = std::filesystem::path(filepath).filename().string();
	auto logLineConsole = string_format("[%s:%d] %s", filename.c_str(), line, buf);
	auto str = (logLineConsole + std::string(fmt)).c_str();

	std::cout << logLineConsole << std::endl;
}

void Utils::ConsolePrint(const char* filepath, int line, const wchar_t* fmt, ...)
{
	wchar_t buf[4096];

	va_list va;
	va_start(va, fmt);
	vswprintf_s(buf, fmt, va);
	va_end(va);

	const std::lock_guard<std::mutex> lock(mutex);

	auto filename = std::filesystem::path(filepath).filename().string();
	auto logLineConsole = string_format("[%s:%d] %s", filename.c_str(), line, buf);
	auto str = (logLineConsole + to_string(std::wstring(fmt))).c_str();

	std::cout << logLineConsole << std::endl;
}

void Utils::ClearConsole()
{
	DWORD n;                         /* Number of characters written */
	DWORD size;                      /* number of visible characters */
	COORD coord = { 0 };               /* Top left screen position */
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	/* Get a handle to the console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	/* Find the number of characters to overwrite */
	size = csbi.dwSize.X * csbi.dwSize.Y;

	/* Overwrite the screen buffer with whitespace */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	/* Reset the cursor to the top left position */
	SetConsoleCursorPosition(h, coord);
}

char Utils::ConsoleReadKey()
{
	auto key = char{ 0 };
	auto keysread = DWORD{ 0 };

	//ReadConsoleA(_in, &key, 1, &keysread, nullptr);
	return std::cin.get();
}

std::string Utils::GetAddressModuleName(uintptr_t address)
{
	std::vector<MODULEENTRY32> Modules{};

	static DWORD pid = GetCurrentProcessId();
	MODULEENTRY32 mod{};
	mod.dwSize = sizeof(mod);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	for (Module32First(snap, &mod); Module32Next(snap, &mod);)
	{
		if (mod.th32ProcessID != pid)
			continue;

		Modules.emplace_back(mod);
	}
	CloseHandle(snap);

	for (const auto& it : Modules)
	{
		if (address >= (uintptr_t)it.modBaseAddr && address <= (uintptr_t)it.modBaseAddr + it.modBaseSize)
			return it.szModule;
	}

	return "unknown";
}

std::wstring Utils::GetCurrentProcessNameW()
{
	DWORD processID = GetCurrentProcessId();
	HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	if (processHandle != NULL)
	{
		WCHAR processName[MAX_PATH] = L"<unknown>";
		GetModuleBaseNameW(processHandle, NULL, processName, MAX_PATH);
		CloseHandle(processHandle);
		return std::wstring(processName);
	}

	// In case the handle could not be opened, return an error message.
	return L"Unable to retrieve process name.";
}

std::string Utils::GetCurrentProcessNameA()
{
	return to_string(GetCurrentProcessNameW());
}

std::string Utils::to_string(const std::wstring& wstr)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> strconverter;
	return strconverter.to_bytes(wstr);
}

std::wstring Utils::to_wstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> strconverter;
	return strconverter.from_bytes(str);
}

bool Utils::KeyDown(std::uint16_t vk)
{
	const auto hWindow = FindWindowA("UnityWndClass", nullptr);
	if (GetForegroundWindow() != hWindow)
		return false;

	return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

bool Utils::KeyPressed(std::uint16_t vk)
{
	const auto hWindow = FindWindowA("UnityWndClass", nullptr);
	if (GetForegroundWindow() != hWindow)
		return false;

	return (GetAsyncKeyState(vk) & 1) != 0;
}

void Utils::OpenURL(const std::string& url)
{
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

std::string Utils::GetModulePath(HMODULE hModule /*= nullptr*/)
{
	char pathOut[MAX_PATH] = {};
	GetModuleFileNameA(hModule, pathOut, MAX_PATH);

	return std::filesystem::path(pathOut).parent_path().string();
}

static std::filesystem::path _currentPath;
void Utils::SetCurrentPath(const std::filesystem::path& current_path)
{
	_currentPath = current_path;
}

std::filesystem::path Utils::GetCurrentPath()
{
	return _currentPath;
}

std::string Utils::GenerateRandomString(size_t length)
{
	const std::vector charset = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	};

	std::random_device rd;
	std::mt19937 generator(rd());

	std::uniform_int_distribution<size_t> distribution(0, charset.size() - 1);

	std::string randomString;
	for (size_t i = 0; i < length; ++i)
		randomString += charset[distribution(generator)];

	return randomString;
}