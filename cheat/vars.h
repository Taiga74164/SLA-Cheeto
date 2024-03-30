#pragma once

struct Vars
{
	bool b_NoCooldown = true;
	bool b_GodMode = true;
	bool b_DamageHack = true;
	float f_DamageHackValue = 500.0f;
	bool b_DumbEnemies = true;
	bool b_MissionTime = true;
	int i_InfiniteMissionTimeMs = 180000;
	bool b_TimeScale;
	float f_TimeScaleSpeed = 2.0f;
	bool b_FPSUnlock;
	int i_FPS = 60;

	bool b_SkipIntroMovie = true;
};

extern Vars vars;