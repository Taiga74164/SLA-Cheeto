#include "inject.h"

#include <iostream>
#include "util.h"

void Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type)
{
	switch (type)
	{
	case InjectionType::LoadLibraryDLL:
		if (!LoadLibraryDLL(hProcess, dllPath))
			std::cerr << "Failed to inject DLL using LoadLibrary." << std::endl;
		break;
#ifdef USE_MANUAL_MAP
	case InjectionType::ManualMap:
		if (!ManualMapDLL(hProcess, dllPath))
			std::cerr << "Failed to inject DLL using ManualMap." << std::endl;
		break;
#endif
	default:
		if (!LoadLibraryDLL(hProcess, dllPath))
			std::cerr << "Failed to inject DLL using LoadLibrary." << std::endl;
		break;
	}
}