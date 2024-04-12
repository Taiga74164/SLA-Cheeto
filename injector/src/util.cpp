#include "util.h"

#include <commdlg.h>
#include <random>

std::optional<std::string> util::SelectFile(const char* filter, const char* title)
{
	auto currPath = std::filesystem::current_path();

	OPENFILENAME ofn;
	char szFile[260] = { 0 };
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = filter;
	ofn.lpstrTitle = title;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	std::optional<std::string> result = {};
	if (GetOpenFileName(&ofn) == TRUE)
		result = std::string(szFile);

	current_path(currPath);
	return result;
}

std::string util::GetLastErrorAsString(DWORD errorId)
{
	auto errorMessageID = errorId == 0 ? GetLastError() : errorId;
	if (errorMessageID == 0)
		return std::string();
	
	LPSTR messageBuffer = nullptr;
	auto size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
	
	std::string message(messageBuffer, size);
	LocalFree(messageBuffer);
	return message;
}

std::string util::ShuffleDllName(const std::string& path)
{
	size_t lastSlash = path.find_last_of("\\");
	size_t lastDot = path.find_last_of(".");

	if (lastSlash == std::string::npos || lastDot == std::string::npos || lastDot <= lastSlash)
		return path;

	std::string directory = path.substr(0, lastSlash + 1);
	std::string filename = path.substr(lastSlash + 1, lastDot - lastSlash - 1);
	std::string extension = path.substr(lastDot);

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(filename.begin(), filename.end(), g);

	return directory + filename + extension;
}