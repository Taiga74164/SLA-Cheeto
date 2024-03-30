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
            app::Application_set_targetFrameRate(vars.i_FPS, nullptr);
        }
    }
}
