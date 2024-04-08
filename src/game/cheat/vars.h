#pragma once

#include "ConfigEntry.hpp"
#include "Hotkey.h"

class Vars final : public Singleton<Vars>
{
public:
	Vars() = default;

	// Features
	CONFIG_ENTRY_HOTKEY(bool, PlayerSpeed, true, Hotkey());
	CONFIG_ENTRY(float, PlayerSpeedValue, 5.0f);
	CONFIG_ENTRY_HOTKEY(bool, NoCooldown, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, NoCooldownShadow, false, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, GodMode, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, KillAura, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, DamageHack, true, Hotkey());
	//CONFIG_ENTRY_HOTKEY(bool, DamagePercentage, false, Hotkey());
	//CONFIG_ENTRY_HOTKEY(bool, DamageFixed, true, Hotkey());
	CONFIG_ENTRY(int, DamageHackValue, 20000);
	CONFIG_ENTRY_HOTKEY(bool, MobVacuum, true, Hotkey());
	CONFIG_ENTRY(float, VacuumRange, 5.0f);
	CONFIG_ENTRY(float, VacuumDistance, 3.0f);
	CONFIG_ENTRY_HOTKEY(bool, DumbEnemies, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, MissionTime, true, Hotkey());
	CONFIG_ENTRY(int, MissionTimeMs, 180000);
	CONFIG_ENTRY_HOTKEY(bool, TimeScale, false, Hotkey());
	CONFIG_ENTRY(float, TimeScaleSpeed, 2.0f);

	// Misc
	CONFIG_ENTRY_HOTKEY(bool, FPSUnlock, true, Hotkey());
	CONFIG_ENTRY(int, FPSValue, 240);
	CONFIG_ENTRY_HOTKEY(bool, FovChanger, false, Hotkey());
	CONFIG_ENTRY(float, Fov, 60.0f);
	CONFIG_ENTRY_HOTKEY(bool, SkipIntroMovie, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, DisableWebView, true, Hotkey());
};
