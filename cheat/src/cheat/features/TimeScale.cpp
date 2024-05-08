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
		
		if (vars.TimeScale.value())
		{
			UnityResolve::UnityType::Time::SetTimeScale(vars.TimeScaleSpeed.value());
			m_DidSpeed = true;
		}
		else
		{
			if (m_DidSpeed)
			{
				UnityResolve::UnityType::Time::SetTimeScale(1.0f);
				m_DidSpeed = false;
			}
		}
	}
}
