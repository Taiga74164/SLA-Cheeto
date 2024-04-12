#pragma once

#include <Windows.h>
#include <filesystem>
#include <optional>
#include <string>

namespace util
{
	std::optional<std::string> SelectFile(const char* filter = "All Files (*.*)\0*.*\0", const char* title = "Select a File to Open");
	std::string GetLastErrorAsString(DWORD errorId = 0);

	std::string ShuffleDllName(const std::string& path);
}