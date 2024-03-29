#include "TimeScale.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	void TimeScale::Update()
	{
		app::Time_set_timeScale(vars.f_TimeScale, nullptr);
	}
}
