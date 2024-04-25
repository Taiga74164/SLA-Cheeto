#pragma once

#include <json.hpp>
#include <fstream>
#include <string>

#include "Singleton.h"
#include "Hotkey.h"
#include "HotkeyManager.hpp"
#include "Utils.h"

using json = nlohmann::json;

class ConfigManager : public Singleton<ConfigManager>
{
public:
	ConfigManager()
	{
	}

	Hotkey hotkey;
	
	void InitializeConfig(const std::string& path)
	{
		configPath_ = path;
		LoadConfig();
		if (config_.empty())
			SaveConfig();
	}
	
	template<typename T>
	T Get(const std::string& name, const T& defaultValue, bool affectConfig = false)
	{
		LoadConfig();
		if (!config_.contains(name) && affectConfig)
		{
			config_[name] = defaultValue;
			SaveConfig();
		}
		return config_.value(name, defaultValue);
	}

	template<typename T>
	void Set(const std::string& name, const T& value)
	{
		// If the value is the same, don't save it.
		if (config_[name] == value) return;

		config_[name] = value;
		SaveConfig();
	}

	Hotkey GetHotkey(const std::string& name, const Hotkey& defaultHotkey)
	{
		LoadConfig();
		if (!config_.contains(name))
		{
			SetHotkey(name, defaultHotkey);
			SaveConfig();
		}

		auto val = hotkey.FromString(config_.value(name, defaultHotkey.ToString()));
		// LOG("%s: %s", name.c_str(), val.ToString().c_str());
		return val;
	}

	void SetHotkey(const std::string& name, const Hotkey& hotkey)
	{
		// If the value is the same, don't save it.
		if (config_[name] == hotkey.ToString()) return;

		config_[name] = hotkey.ToString();
		SaveConfig();
	}

private:
	json config_;
	std::string configPath_;

	void LoadConfig()
	{
		std::ifstream file(configPath_);
		if (file.peek() == std::ifstream::traits_type::eof())
		{
			SaveConfig();
			return;
		}
		else
		{
			file >> config_;
		}

		file.close();
	}

	void SaveConfig()
	{
		std::ofstream file(configPath_);
		file << config_.dump(4);
		file.flush();
		file.close();
	}
};
