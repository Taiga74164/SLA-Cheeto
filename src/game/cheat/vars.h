#pragma once

struct Vars
{
	bool b_PlayerSpeed = true;
	bool b_NoCooldown = true;
	bool b_GodMode = true;
	bool b_DamageHack = true;
	float f_DamageHackValue = 500.0f;
	bool b_DumbEnemies = true;
	bool b_MissionTime = true;
	int i_MissionTimeMs = 180000;
	bool b_TimeScale;
	float f_TimeScaleSpeed = 2.0f;
	bool b_FPSUnlock = true;
	int i_FPS = 120;
	bool b_FovChanger = false;
	float i_Fov = 60.0f;

	bool b_SkipIntroMovie = true;
};

extern Vars vars;