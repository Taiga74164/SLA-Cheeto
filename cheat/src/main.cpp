#include "main.h"
#include <Utils.h>
#include "ConfigManager.hpp"
#include "appdata/helpers.h"
#include "appdata/il2cpp-init.h"
#include "cheat/cheat.h"
#include "Render/Renderer.h"

void Run(HMODULE hModule)
{
	il2cppi_new_console();
	
	while (!GetModuleHandleA("GameAssembly.dll") && !FindWindowA("UnityWndClass", nullptr))
	{
		LOG("[SoloLevelling] game not found, waiting 3 seconds...");
		Sleep(3000);
	}
	
	Utils::SetCurrentPath(Utils::GetModulePath(hModule));
	ConfigManager::GetInstance().InitializeConfig((Utils::GetCurrentPath() / "config.json").string());
	
	Init(Renderer::DXVersion::D3D11);
	init_il2cpp();
	init_cheat();

	LOG("Config path is at %s", (Utils::GetCurrentPath() / "config.json").string().c_str());
}
