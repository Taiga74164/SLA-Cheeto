#pragma once
#include <Windows.h>
#include <string>

bool LoadLibraryDLL(HANDLE hProc, const std::string& dllpath);