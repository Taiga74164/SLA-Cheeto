#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
    class FPSUnlock : public Module
    {
    public:
        FPSUnlock() = default;

        void Load() override {}
        void Update() override;
    };
}
