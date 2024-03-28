#include "Core.h"
#include <Exports/Exports.h>
#include <codecvt>
#include <psapi.h>
#include <Utils.h>
#include "Memory.h"

#include "appdata/il2cpp-init.h"
#include "Cheat/cheat.h"

#include "Render/Renderer.h"

void Core::Start()
{
	while (!GetModuleHandleA("GameAssembly.dll") && !FindWindowA("UnityWndClass", nullptr))
	{
		LOG("[SoloLevelling] game not found, waiting 3 seconds...");
		Sleep(3000);
	}

	// Init(Renderer::DXVersion::D3D11);

	init_il2cpp();
	init_cheat();

	while (true)
	{
		run_cheat();

		Sleep(50);
	}
}

#pragma region Initialization and DLL proxy stuff

void Core::Initialize(HINSTANCE hModule)
{
	if (Utils::GetCurrentProcessNameA().find("Solo_Leveling_ARISE") == std::string::npos) return;

	Utils::AttachConsole();

	LOG("[SoloLevelling] Initializing...");
	// Get execution path
	std::vector<char> pathBuf;
	DWORD copied = 0;
	do
	{
		pathBuf.resize(pathBuf.size() + MAX_PATH);
		copied = GetModuleFileNameA(nullptr, pathBuf.data(), static_cast<DWORD>(pathBuf.size()));
	} while (copied >= pathBuf.size());

	pathBuf.resize(copied);

	const std::filesystem::path filepath(pathBuf.begin(), pathBuf.end());

	// Get file path of proxy, to lowercase the file name
	const auto proxyFilepath = GetModuleFilePath(hModule);
	auto       proxyFilename = proxyFilepath.filename().wstring();
	std::transform(proxyFilename.begin(), proxyFilename.end(), proxyFilename.begin(), towlower);

	// Make proxy name list
	std::wstring names;
	bool         _1 = true;
	for (const auto name : Exports::CompatibleFileNames)
	{
		if (_1)
		{
			_1 = false;
			names += name;
		}
		else
		{
			names += L", ";
			names += name;
		}
	}

	// Check if is compatible proxy
	std::size_t index = -1;
	if (!Exports::IsFileNameCompatible(proxyFilename, &index))
	{
		Error(L"Proxy has an incompatible file name!\nValid names are: " + names + L"\n", true);
		return;
	}

	// Load original libs
	const HMODULE originalDll = LoadOriginalProxy(proxyFilepath, proxyFilepath.filename().stem().wstring());
	if (!originalDll)
	{
		Error(L"Failed to Load original " + proxyFilepath.wstring() + L"!", true);
		return;
	}

	// Load original lib exports
	Exports::Load(index, originalDll);

	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Start, hModule, 0, nullptr);

	LOG("[SoloLevelling] Created Thread.");
}

HMODULE Core::LoadOriginalProxy(const std::filesystem::path& proxyFilepath, const std::wstring& proxyFilepathNoExt)
{
	HMODULE originalDll = LoadLibraryW((proxyFilepathNoExt + L"_original.dll").c_str());

	if (!originalDll)
	{
		wchar_t system32_path[MAX_PATH];

		if (GetSystemDirectoryW(system32_path, MAX_PATH) == NULL)
		{
			Error("Failed to get System32 directory!");
			KillProcess();
			return nullptr;
		}

		const auto path = std::filesystem::path(system32_path);
		originalDll = LoadLibraryW((path / proxyFilepath.filename()).c_str());
	}

	return originalDll;
}

std::filesystem::path Core::GetModuleFilePath(HMODULE moduleHandle)
{
	wchar_t path[MAX_PATH];
	GetModuleFileNameW(moduleHandle, path, MAX_PATH);
	return path;
}

void Core::Error(const std::string& reason, const bool shouldKill)
{
	MessageBoxA(nullptr, (reason + " " + (shouldKill ? "Preventing Startup" : "Continuing without SoloLevelling") + "...").c_str(), "SoloLevelling",
		MB_ICONERROR | MB_OK);
	if (shouldKill) KillProcess();
}

void Core::Error(const std::wstring& reason, const bool shouldKill)
{
	MessageBoxW(nullptr, (reason + L" " + (shouldKill ? L"Preventing Startup" : L"Continuing without SoloLevelling") + L"...").c_str(), L"SoloLevelling",
		MB_ICONERROR | MB_OK);
	if (shouldKill) KillProcess();
}

void Core::KillProcess()
{
	const HANDLE current_process = GetCurrentProcess();
	TerminateProcess(current_process, NULL);
	CloseHandle(current_process);
}

#pragma endregion
