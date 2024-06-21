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
		auto& vars = Vars::GetInstance();
		
		if (vars.TimeScale.value() && !m_DidSpeed)
		{
			app::Time_3_set_timeScale(vars.TimeScaleSpeed.value(), nullptr);
			m_DidSpeed = true;
		}
		else
		{
			if (m_DidSpeed)
			{
				app::Time_3_set_timeScale(1.0f, nullptr);
				m_DidSpeed = false;
			}
		}
	}
}
