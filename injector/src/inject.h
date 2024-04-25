#pragma once
#define USE_MANUAL_MAP

#include <Windows.h>
#include <string>
#include "load-library.h"
#ifdef USE_MANUAL_MAP
#include "manual-map.h"
#else
#error "USE_MANUAL_MAP is defined but manual-map.h is not included. Uncomment the "#define USE_MANUAL_MAP" line in inject.h and remove manual-map from the project."
#endif

enum class InjectionType
{
	LoadLibraryDLL,
	ManualMap
};

void Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type = InjectionType::LoadLibraryDLL);