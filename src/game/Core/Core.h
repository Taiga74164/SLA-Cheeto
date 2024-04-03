#pragma once
#include <Windows.h>
#include <filesystem>

class Core
{
public:
	static void Initialize(HINSTANCE hModule);
	static void Start(HMODULE hModule);
	
private:
	static HMODULE LoadOriginalProxy(const std::filesystem::path& proxyFilepath, const std::wstring& proxyFilepathNoExt);
	static std::filesystem::path GetModuleFilePath(HMODULE moduleHandle);

	static void Error(const std::string& reason, bool shouldKill = false);
	static void Error(const std::wstring& reason, bool shouldKill = false);
	static void KillProcess();
};
