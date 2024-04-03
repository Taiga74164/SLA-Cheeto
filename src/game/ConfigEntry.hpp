#pragma once

#include "ConfigManager.hpp"
#include <string>

using json = nlohmann::json;

#define CONFIG_ENTRY(Type, Name, DefaultValue) ConfigEntry<Type> Name = { #Name, DefaultValue }

template<typename T>
class ConfigEntry
{
public:
	ConfigEntry(const std::string& name, const T& defaultValue)
		: name_(name), value_(defaultValue)
	{
		value_ = ConfigManager::GetInstance().Get<T>(name, defaultValue, true);
	}

	T& value()
	{
		// Goofy ahhhhh.
		ConfigManager::GetInstance().Set(name_, value_);
		return value_;
	}

	void SetValue(const T& value)
	{
		if (value_ == value) return;
		
		value_ = value;
		ConfigManager::GetInstance().Set(name_, value);
	}

	ConfigEntry& operator=(const T& newValue)
	{
		SetValue(newValue);
		return *this;
	}

private:
	std::string name_;
	T value_;
};