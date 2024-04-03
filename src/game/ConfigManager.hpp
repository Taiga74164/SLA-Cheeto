#pragma once

#include <json.hpp>
#include <Windows.h>
#include <fstream>
#include <string>

#include "Singleton.h"

using json = nlohmann::json;

class ConfigManager : public Singleton<ConfigManager>
{
public:
	ConfigManager()
	{
	}
	
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
		// json newConfig;
		// newConfig[name] = value;
		// SaveConfig(newConfig);
		config_[name] = value;
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
		// for (auto& it : newConfig.items())
		// 	config_[it.key()] = it.value();
		//
		// std::ofstream o(configPath_);
		// o << config_.dump(4);
		std::ofstream file(configPath_);
		file << config_.dump(4);
		file.flush();
		file.close();
	}
};
