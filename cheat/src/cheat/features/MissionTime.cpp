#include "MissionTime.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	MissionTime::MissionTime()
	{
		HookManager::install(app::StageReadyPage_EnterUI, StageReadyPage_EnterUI_Hook);
	}

	void MissionTime::StageReadyPage_EnterUI_Hook(app::StageReadyPage* __this, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		
		if (vars.MissionTime.value())
			__this->fields.FHMGDAMDBHG->fields.m_Timelimit = vars.MissionTimeMs.value();

		CALL_ORIGIN(StageReadyPage_EnterUI_Hook, __this, method);
	}
}
