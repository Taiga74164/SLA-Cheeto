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
        if (m_LastEnableStatus && !vars.b_FPSUnlock)
        {
            app::Application_set_targetFrameRate(m_OriginFPS, nullptr);
        }
        else if (!m_LastEnableStatus && vars.b_FPSUnlock)
        {
            m_OriginFPS = app::Application_get_targetFrameRate(nullptr);
        }
        m_LastEnableStatus = vars.b_FPSUnlock;
        if (vars.b_FPSUnlock)
        {
            app::Application_set_targetFrameRate(vars.i_FPS, nullptr);
            app::QualitySettings_set_vSyncCount(0, nullptr);
        }
    }
}
