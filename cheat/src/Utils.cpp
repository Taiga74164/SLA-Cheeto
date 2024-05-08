#include "Utils.h"
#include <iostream>
#include <TlHelp32.h>
#include <codecvt>
#include <cstdarg>
#include <fstream>
#include <psapi.h>
#include <mutex>
#include <random>

std::string logfilepath = "";
LogType logType = LogType::Console;
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

void LogToFile(std::string& filepath, std::string& msg)
{
	std::ofstream myfile;
	myfile.open(filepath, std::ios::out | std::ios::app | std::ios::binary);
	myfile << msg << std::endl;
	myfile.close();
}

void Utils::Log(const char* filepath, int line, LogLevel level, const char* fmt, ...)
{
	char buf[4096];
	const char* levelStr = "";
	WORD levelColor, filenameColor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY; // Lighter Blue
	WORD lineColor = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY; // Lighter Yellow

	// Determine log level string and corresponding color
	switch (level)
	{
	case Debug:
		levelStr = "Debug";
		levelColor = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY; // Magenta
		break;
	case Error:
		levelStr = "Error";
		levelColor = FOREGROUND_RED | FOREGROUND_INTENSITY; // Red
		break;
	case Warning:
		levelStr = "Warning";
		levelColor = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY; // Yellow
		break;
	}

	va_list va;
	va_start(va, fmt);
	vsprintf_s(buf, fmt, va);
	va_end(va);

	const std::lock_guard<std::mutex> lock(mutex);

	// Print with default color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD saved_attributes = consoleInfo.wAttributes;

	// Print '[' in default color
	std::cout << "[";

	auto filename = std::filesystem::path(filepath).filename().string();

	// Print filename in blue
	SetConsoleTextAttribute(hConsole, filenameColor);
	std::cout << filename;

	// Print ':' in default color
	SetConsoleTextAttribute(hConsole, saved_attributes);
	std::cout << ":";

	// Print line in lighter yellow
	SetConsoleTextAttribute(hConsole, lineColor);
	std::cout << line;

	// Reset to default color, print level in its color, and reset again
	SetConsoleTextAttribute(hConsole, saved_attributes);
	std::cout << "] [";
	SetConsoleTextAttribute(hConsole, levelColor);
	std::cout << levelStr;
	SetConsoleTextAttribute(hConsole, saved_attributes);
	std::cout << "] " << buf << std::endl;

	if (logType == LogType::File)
	{

		auto rawTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		struct tm gmtm;
		gmtime_s(&gmtm, &rawTime);
		auto logLineFile = string_format("[%02d:%02d:%02d] [%s] [%s:%d] %s", gmtm.tm_hour, gmtm.tm_min, gmtm.tm_sec,
			levelStr, filename.c_str(), line, buf);
		LogToFile(logfilepath, logLineFile);
	}
}



void Utils::PrepareFileLogging(std::string directory)
{
	auto rawTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm gmtm;
	gmtime_s(&gmtm, &rawTime);

	if (!std::filesystem::is_directory(directory))
		std::filesystem::create_directories(directory);

	logfilepath = string_format("%s\\log_%04d-%02d-%02d_%02d-%02d.txt", directory.c_str(),
		1900 + gmtm.tm_year, gmtm.tm_mon, gmtm.tm_mday, gmtm.tm_hour, gmtm.tm_min);

	logType = LogType::File;
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