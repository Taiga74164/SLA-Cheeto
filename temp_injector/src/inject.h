#pragma once

#include <Windows.h>
#include <string>

bool Inject(HANDLE hProcess, const std::string& dllPath);