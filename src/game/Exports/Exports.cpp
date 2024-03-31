#include "Exports.h"

FARPROC OriginalFuncs_psapi[27];
FARPROC OriginalFuncs_version[17];
FARPROC OriginalFuncs_winhttp[65];
FARPROC OriginalFuncs_winmm[181];

bool Exports::IsFileNameCompatible(const std::wstring& proxyFilename, std::size_t* index)
{
	for (std::size_t i = 0; i < CompatibleFileNames.size(); ++i)
	{
		if (proxyFilename == CompatibleFileNames[i])
		{
			*index = i;
			return true;
		}
	}

	return false;
}

void Exports::Load(HMODULE originalDll, const char* const* exportNames, FARPROC* originalFuncs, std::size_t arraySize)
{
	for (std::size_t i = 0; i < arraySize; i++) originalFuncs[i] = GetProcAddress(originalDll, exportNames[i]);
}
