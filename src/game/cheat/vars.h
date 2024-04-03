#pragma once

#include "ConfigEntry.hpp"

class Vars final : public Singleton<Vars>
{
public:
	Vars() = default;
	
	CONFIG_ENTRY(bool, PlayerSpeed, true);
	CONFIG_ENTRY(bool, NoCooldown, true);
	CONFIG_ENTRY(bool, NoCooldownShadow, true);
	CONFIG_ENTRY(bool, GodMode, true);
	CONFIG_ENTRY(bool, DamageHack, true);
	CONFIG_ENTRY(float, DamageHackValue, 500.0f);
	CONFIG_ENTRY(bool, DumbEnemies, true);
	CONFIG_ENTRY(bool, MissionTime, true);
	CONFIG_ENTRY(int, MissionTimeMs, 180000);
	CONFIG_ENTRY(bool, TimeScale, false);
	CONFIG_ENTRY(float, TimeScaleSpeed, 2.0f);
	CONFIG_ENTRY(bool, FPSUnlock, true);
	CONFIG_ENTRY(int, FPSValue, 120);
	CONFIG_ENTRY(bool, FovChanger, false);
	CONFIG_ENTRY(float, Fov, 60.0f);
	CONFIG_ENTRY(bool, SkipIntroMovie, true);
	CONFIG_ENTRY(bool, DisableWebView, true);
};