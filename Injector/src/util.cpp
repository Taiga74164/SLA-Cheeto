#include "util.h"

#include <commdlg.h>

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