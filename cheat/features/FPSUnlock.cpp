#include "FPSUnlock.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
    void FPSUnlock::Update()
    {
        if (vars.b_FPSUnlock)
        {
            // LOG("fps: %d", app::Application_get_targetFrameRate(nullptr));
            app::Application_set_targetFrameRate(vars.i_FPS, nullptr);
            app::QualitySettings_set_vSyncCount(0, nullptr);
        }
    }
}
