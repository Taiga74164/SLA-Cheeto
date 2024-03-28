#pragma once
#include <string>
#include <filesystem>

#define LOG(fmt, ...)   Utils::ConsolePrint(__FILE__, __LINE__, fmt, __VA_ARGS__)

namespace Utils
{
    void AttachConsole();
    void DetachConsole();
	void ConsolePrint(const char* filepath, int line, const char* fmt, ...);
	void ConsolePrint(const char* filepath, int line, const wchar_t* fmt, ...);
	void ClearConsole();
    char ConsoleReadKey();

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

	template<typename T>
	void SetToHex(T value, uint8_t* hexPtr)
	{
		memcpy(hexPtr, &value, sizeof(T));
	}
}