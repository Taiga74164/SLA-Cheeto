#include "TimeScale.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	TimeScale::TimeScale() : m_DidSpeed(false)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(TimeScale::OnGameUpdate);
	}
	
	void TimeScale::OnGameUpdate()
	{
		if (vars.b_TimeScale)
		{
			app::Time_set_timeScale(vars.f_TimeScaleSpeed, nullptr);
			m_DidSpeed = true;
		}
		else
		{
			if (m_DidSpeed)
			{
				app::Time_set_timeScale(1.0f, nullptr);
				m_DidSpeed = false;
			}
		}
	}
}
