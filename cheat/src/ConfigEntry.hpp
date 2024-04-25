#pragma once

#include "ConfigManager.hpp"
#include <string>
#include "Utils.h"

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

		if constexpr (std::is_same_v<T, bool>)
			RegisterHotkey();
	}

	T& value()
	{
		// Goofy ahhhhh.
		// Bad code, don't look at this.
		// LOG("Getting value for %s", name_.c_str());
		ConfigManager::GetInstance().Set(name_, value_);
		return value_;
	}

	void SetValue(const T& value)
	{
		if (value_ == value) return;
		
		value_ = value;
		// LOG("Setting value for %s", name_.c_str());
		ConfigManager::GetInstance().Set(name_, value);
	}

	Hotkey& hotkey()
	{
		// Goofy ahhhhh.
		// Bad code, don't look at this.
		// LOG("Getting hotkey for %s", hotkey_.GetKeyString().c_str());
		ConfigManager::GetInstance().SetHotkey(name_ + "Hotkey", hotkey_);
		return hotkey_;
	}

	void SetHotkey(const Hotkey& newHotkey)
	{
		if (hotkey_ == newHotkey) return;

		hotkey_ = newHotkey;
		// LOG("Setting hotkey for %s", hotkey_.GetKeyString().c_str());
		ConfigManager::GetInstance().SetHotkey(name_ + "Hotkey", hotkey_);
	}

    void RegisterHotkey()
    {
		if constexpr (std::is_same_v<T, bool>)
			HotkeyManager::GetInstance().RegisterKey(hotkey_, &value_);
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