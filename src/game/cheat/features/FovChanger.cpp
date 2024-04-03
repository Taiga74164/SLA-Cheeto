#include "FovChanger.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
    FovChanger::FovChanger()
    {
		HookManager::install(app::Camera_set_fieldOfView, Camera_set_fieldOfView_Hook);
    }
	
    void FovChanger::Camera_set_fieldOfView_Hook(void* __this, float value, MethodInfo* method)
    {
    	auto& vars = Vars::GetInstance();
    	
    	if (vars.FovChanger.value())
    		value = vars.Fov.value();
    	
		CALL_ORIGIN(Camera_set_fieldOfView_Hook, __this, value, method);
    }
}
