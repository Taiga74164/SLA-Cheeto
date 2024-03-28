#include "Core/Core.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
	{
    	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
        Core::Initialize(hModule);
        break;
    }
    return TRUE;
}
