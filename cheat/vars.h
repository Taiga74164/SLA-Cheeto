#pragma once

struct Vars
{
	bool b_NoCooldown = true;
	bool b_GodMode = true;
	bool b_DamageHack = true;
	float f_DamageHackValue = 500.0f;
	bool b_DumbEnemies = true;
	bool b_InfiniteMissionTime = true;
	bool b_TimeScale;
	float f_TimeScaleSpeed = 2.0f;
};

extern Vars vars;