#pragma once

#include "SimpleIni.h"
#include <string>

class Config
{
public:
	std::string GamePath;
	std::string LaunchOptions;
	std::string DLLPath_1;
	std::string DLLPath_2;
	std::string DLLPath_3;

	Config() : GamePath(""), LaunchOptions(""), DLLPath_1(""), DLLPath_2(""), DLLPath_3("") {}

	bool Load(const char* path)
	{
		CSimpleIniA ini;
		ini.SetUnicode();
		auto rc = ini.LoadFile(path);
		if (rc < 0)
		{
			std::cout << "Failed to load config file: " << path << " creating new one." << std::endl;
			return Save(path);
		}

		GamePath = ini.GetValue("Config", "GamePath", "");
		LaunchOptions = ini.GetValue("Config", "LaunchOptions", "");
		DLLPath_1 = ini.GetValue("Config", "DLLPath_1", "");
		DLLPath_2 = ini.GetValue("Config", "DLLPath_2", "");
		DLLPath_3 = ini.GetValue("Config", "DLLPath_3", "");

		return true;
	}

	bool Save(const char* path)
	{
		CSimpleIniA ini;
		ini.SetUnicode();

		ini.SetValue("Config", "GamePath", GamePath.c_str());
		ini.SetValue("Config", "LaunchOptions", LaunchOptions.c_str());
		ini.SetValue("Config", "DLLPath_1", DLLPath_1.c_str());
		ini.SetValue("Config", "DLLPath_2", DLLPath_2.c_str());
		ini.SetValue("Config", "DLLPath_3", DLLPath_3.c_str());
		
		auto rc = ini.SaveFile(path);
		return rc >= 0;
	}
};