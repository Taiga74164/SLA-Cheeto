#pragma once

#include "ConfigEntry.hpp"

class Vars final : public Singleton<Vars>
{
public:
	Vars() = default;

	// Features
	CONFIG_ENTRY(bool, PlayerSpeed, true);
	CONFIG_ENTRY(bool, NoCooldown, true);
	CONFIG_ENTRY(bool, NoCooldownShadow, false);
	CONFIG_ENTRY(bool, GodMode, true);
	CONFIG_ENTRY(bool, KillAura, true);
	CONFIG_ENTRY(bool, DamageHack, true);
	//CONFIG_ENTRY(bool, DamagePercentage, false);
	//CONFIG_ENTRY(bool, DamageFixed, true);
	CONFIG_ENTRY(int, DamageHackValue, 20000);
	CONFIG_ENTRY(bool, MobVacuum, true);
	CONFIG_ENTRY(bool, DumbEnemies, true);
	CONFIG_ENTRY(bool, MissionTime, true);
	CONFIG_ENTRY(int, MissionTimeMs, 180000);
	CONFIG_ENTRY(bool, TimeScale, false);
	CONFIG_ENTRY(float, TimeScaleSpeed, 2.0f);


	// Misc
	CONFIG_ENTRY(bool, FPSUnlock, true);
	CONFIG_ENTRY(int, FPSValue, 240);
	CONFIG_ENTRY(bool, FovChanger, false);
	CONFIG_ENTRY(float, Fov, 60.0f);
	CONFIG_ENTRY(bool, SkipIntroMovie, true);
	CONFIG_ENTRY(bool, DisableWebView, true);
	
};