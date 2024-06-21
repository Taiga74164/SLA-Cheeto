#include "FPSUnlock.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	FPSUnlock::FPSUnlock() : m_LastEnableStatus(false), m_OriginFPS(60)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(FPSUnlock::OnGameUpdate);
	}

	void FPSUnlock::OnGameUpdate()
	{
		auto& vars = Vars::GetInstance();

		if (m_LastEnableStatus && !vars.FPSUnlock.value())
		{
			app::Application_set_targetFrameRate(m_OriginFPS, nullptr);
		}
		else if (!m_LastEnableStatus && vars.FPSUnlock.value())
		{
			m_OriginFPS = app::Application_get_targetFrameRate(nullptr);
		}
		m_LastEnableStatus = vars.FPSUnlock.value();
		if (vars.FPSUnlock.value())
		{
			methods::Application::SetTargetFrameRate(vars.FPSValue.value());
			methods::QualitySettings::SetVSyncCount(0);
		}
	}
}
