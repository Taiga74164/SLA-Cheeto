#pragma once
#include <Windows.h>
#include <string>
#include "Resources.h"

extern "C" FARPROC OriginalFuncs_psapi[27];
extern "C" FARPROC OriginalFuncs_version[17];
extern "C" FARPROC OriginalFuncs_winhttp[65];
extern "C" FARPROC OriginalFuncs_winmm[181];

namespace Exports
{
	inline constexpr std::array<const wchar_t*, 4> CompatibleFileNames =
	{
		L"psapi.dll",
		L"version.dll",
		L"winhttp.dll",
		L"winmm.dll"
	};

	void Load(HMODULE originalDll, const char* const* exportNames, FARPROC* originalFuncs, std::size_t arraySize);

	inline void Load_psapi(const HMODULE originalDll) { Load(originalDll, ExportNames_psapi.data(), OriginalFuncs_psapi, ExportNames_psapi.size()); }
	inline void Load_version(const HMODULE originalDll) { Load(originalDll, ExportNames_version.data(), OriginalFuncs_version, ExportNames_version.size()); }
	inline void Load_winhttp(const HMODULE originalDll) { Load(originalDll, ExportNames_winhttp.data(), OriginalFuncs_winhttp, ExportNames_winhttp.size()); }
	inline void Load_winmm(const HMODULE originalDll) { Load(originalDll, ExportNames_winmm.data(), OriginalFuncs_winmm, ExportNames_winmm.size()); }

	using load_exports_func = decltype(&Load_psapi);
	inline constexpr std::array<load_exports_func, 4> load_funcs =
	{
		Load_psapi,
		Load_version,
		Load_winhttp,
		Load_winmm
	};

	constexpr void Load(const std::size_t index, const HMODULE originalDll) { load_funcs[index](originalDll); }
	bool IsFileNameCompatible(const std::wstring& proxyFilename, std::size_t* index);
};
