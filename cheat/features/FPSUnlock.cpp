#include "FPSUnlock.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
    static bool _lastEnabledStatus = false;
    static int _originFPS = 30;
    
    void FPSUnlock::Update()
    {
        if (_lastEnabledStatus && !vars.b_FPSUnlock)
        {
            app::Application_set_targetFrameRate(_originFPS, nullptr);
        }
        else if (!_lastEnabledStatus && vars.b_FPSUnlock)
        {
            _originFPS = app::Application_get_targetFrameRate(nullptr);
        }
        _lastEnabledStatus = vars.b_FPSUnlock;
        if (vars.b_FPSUnlock)
        {
            app::Application_set_targetFrameRate(vars.i_FPS, nullptr);
            app::QualitySettings_set_vSyncCount(0, nullptr);
        }
    }
}
