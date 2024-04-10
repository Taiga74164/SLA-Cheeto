#pragma once

#include "ConfigManager.hpp"
#include <string>

using json = nlohmann::json;

#define CONFIG_ENTRY(Type, Name, DefaultValue) ConfigEntry<Type> Name = ConfigEntry<Type>(#Name, DefaultValue);
#define CONFIG_ENTRY_HOTKEY(Type, Name, DefaultValue, DefaultHotkey) ConfigEntry<Type> Name = ConfigEntry<Type>(#Name, DefaultValue, DefaultHotkey);

template<typename T>
class ConfigEntry
{
public:
	ConfigEntry(const std::string& name, const T& defaultValue, const Hotkey& defaultHotkey = Hotkey())
		: name_(name), value_(defaultValue), hotkey_(defaultHotkey)
	{
		value_ = ConfigManager::GetInstance().Get<T>(name, defaultValue, true);
		hotkey_ = ConfigManager::GetInstance().GetHotkey(name + "Hotkey", defaultHotkey);
	}

	T& value()
	{
		// Goofy ahhhhh.
		// Bad code, don't look at this.
		ConfigManager::GetInstance().Set(name_, value_);
		return value_;
	}

	void SetValue(const T& value)
	{
		if (value_ == value) return;
		
		value_ = value;
		ConfigManager::GetInstance().Set(name_, value);
	}

	Hotkey& hotkey()
	{
		// Goofy ahhhhh.
		// Bad code, don't look at this.
		ConfigManager::GetInstance().SetHotkey(name_ + "Hotkey", hotkey_);
		return hotkey_;
	}

	void SetHotkey(const Hotkey& newHotkey)
	{
		if (hotkey_ == newHotkey) return;

		hotkey_ = newHotkey;
		ConfigManager::GetInstance().SetHotkey(name_ + "Hotkey", hotkey_);
	}

	ConfigEntry& operator=(const T& newValue)
	{
		SetValue(newValue);
		return *this;
	}

private:
	std::string name_;
	T value_;
	Hotkey hotkey_;
};