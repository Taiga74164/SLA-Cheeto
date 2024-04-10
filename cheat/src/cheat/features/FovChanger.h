#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
    class FovChanger : public Singleton<FovChanger>
    {
    public:
        FovChanger();

    private:
		static void Camera_set_fieldOfView_Hook(void* __this, float value, MethodInfo* method);
    };
}
