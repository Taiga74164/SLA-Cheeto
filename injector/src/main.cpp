#include <iostream>
#include <filesystem>
#include "config.hpp"
#include "util.h"
#include "inject.h"

static Config config;

bool OpenGame(HANDLE* phProcess, HANDLE* phThread)
{
	STARTUPINFOA si{};
	PROCESS_INFORMATION pi{};
	
	auto procName = config.GamePath.substr(config.GamePath.find_last_of("\\") + 1);
	auto cmdLine = config.GamePath + " " + config.LaunchOptions;

	if (!CreateProcess(config.GamePath.c_str(), (LPSTR)cmdLine.c_str(),
		nullptr, nullptr, FALSE,
		CREATE_SUSPENDED, nullptr, nullptr, &si, &pi))
	{
		std::cerr << "CreateProcess failed: " << util::GetLastErrorAsString() << std::endl;
		return false;
	}

	*phProcess = pi.hProcess;
	*phThread = pi.hThread;

	return true;
}

int main()
{
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	
	std::string configPath = "config.ini";
	if (!std::filesystem::exists(configPath) || !config.Load(configPath.c_str()))
	{
		auto gamePathOpt = util::SelectFile("Executable Files (*.exe)\0*.exe\0", "Select the game executable");
		if (gamePathOpt)
		{
			config.GamePath = gamePathOpt.value();
			std::cout << "Game Path Selected: " << config.GamePath << std::endl;
		}

		auto dllPathOpt = util::SelectFile("DLL Files (*.dll)\0*.dll\0", "Select the first DLL to inject");
		if (dllPathOpt)
		{
			config.DLLPath_1 = dllPathOpt.value();
			std::cout << "DLL Path 1 Selected: " << config.DLLPath_1 << std::endl;
		}

		config.Save(configPath.c_str());
	}
	else
	{
		std::cout << "Config loaded successfully" << std::endl;
		std::cout << "Path to game: " << config.GamePath << std::endl;
	}

	CoUninitialize();

	HANDLE hProcess, hThread;
	if (!OpenGame(&hProcess, &hThread))
	{
		std::cerr << "Failed to open process" << std::endl;
		system("pause");
		return 1;
	}

	if (!config.DLLPath_1.empty())
	{
		if (!Inject(hProcess, config.DLLPath_1))
			std::cerr << "Failed to inject DLL 1" << std::endl;
	}

	if (!config.DLLPath_2.empty())
	{
		if (!Inject(hProcess, config.DLLPath_2))
			std::cerr << "Failed to inject DLL 2" << std::endl;
	}

	if (!config.DLLPath_3.empty())
	{
		if (!Inject(hProcess, config.DLLPath_3))
			std::cerr << "Failed to inject DLL 3" << std::endl;
	}
	
	Sleep(2000);
	ResumeThread(hThread);
	CloseHandle(hProcess);
	return 0;
}