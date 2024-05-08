#include "main.h"
#include <Utils.h>
#include "ConfigManager.hpp"
#include "UnityResolve.hpp"
#include "appdata/helpers.h"
#include "appdata/il2cpp-init.h"
#include "cheat/cheat.h"
#include "Render/Renderer.h"

void Run(HMODULE hModule)
{
	il2cppi_new_console();
	
	while (!GetModuleHandleA(xorstr("GameAssembly.dll")) && !FindWindowA(xorstr("UnityWndClass"), nullptr))
	{
		LOG(xorstr("[SoloLevelling] game not found, waiting 3 seconds..."));
		Sleep(3000);
	}

	Utils::SetCurrentPath(Utils::GetModulePath(hModule));
	ConfigManager::GetInstance().InitializeConfig((Utils::GetCurrentPath() / "config.json").string());
	
	Init(Renderer::DXVersion::D3D11);

	UnityResolve::Init(GetModuleHandleA(xorstr("GameAssembly.dll")), UnityResolve::Mode::Il2Cpp);

	init_il2cpp();
	init_cheat();

	LOG(xorstr("Config path is at %s"), (Utils::GetCurrentPath() / xorstr("config.json")).string().c_str());
}
