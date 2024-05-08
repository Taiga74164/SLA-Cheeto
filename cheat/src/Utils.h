#pragma once

#include <Windows.h>
#include <string>
#include <filesystem>
#include "xorstr.h"

enum LogLevel
{
	Debug,
	Error,
	Warning
};

enum LogType
{
	Console,
	File
};

#define LOG(fmt, ...)   Utils::ConsolePrint(__FILE__, __LINE__, fmt, __VA_ARGS__)
#define LOG_DEBUG(fmt, ...)   Utils::Log(__FILE__, __LINE__, LogLevel::Debug, fmt, __VA_ARGS__)
#define LOG_ERROR(fmt, ...)   Utils::Log(__FILE__, __LINE__, LogLevel::Error, fmt, __VA_ARGS__)
#define LOG_WARNING(fmt, ...) Utils::Log(__FILE__, __LINE__, LogLevel::Warning, fmt, __VA_ARGS__)

namespace Utils
{
    void AttachConsole();
    void DetachConsole();
	void ConsolePrint(const char* filepath, int line, const char* fmt, ...);
	void ConsolePrint(const char* filepath, int line, const wchar_t* fmt, ...);
	void ClearConsole();
    char ConsoleReadKey();
	void Log(const char* filepath, int line, LogLevel level, const char* fmt, ...);
	void PrepareFileLogging(std::string directory);

	template<typename ... Args>
	std::string string_format(const std::string& format, Args ... args)
	{
		int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
		if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
		auto size = static_cast<size_t>(size_s);
		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format.c_str(), args ...);
		return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
	}

    std::string GetAddressModuleName(uintptr_t address);

	std::wstring GetCurrentProcessNameW();
	std::string GetCurrentProcessNameA();

	std::string to_string(const std::wstring& wstr);
	std::wstring to_wstring(const std::string& str);

	bool KeyDown(std::uint16_t vk);
	bool KeyPressed(std::uint16_t vk);

	void OpenURL(const std::string& url);

	template<typename T>
	void SetToHex(T value, uint8_t* hexPtr)
	{
		memcpy(hexPtr, &value, sizeof(T));
	}

	std::string GetModulePath(HMODULE hModule = nullptr);

	void SetCurrentPath(const std::filesystem::path& curren_path);
	std::filesystem::path GetCurrentPath();

	std::string GenerateRandomString(size_t length);
}