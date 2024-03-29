#include "TimeScale.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	static bool didSpeed = false;
	void TimeScale::Update()
	{
		if (vars.b_TimeScale)
		{
			app::Time_set_timeScale(vars.f_TimeScaleSpeed, nullptr);
			didSpeed = true;
		}
		else
		{
			if (didSpeed)
			{
				app::Time_set_timeScale(1.0f, nullptr);
				didSpeed = false;
			}
		}
	}
}
