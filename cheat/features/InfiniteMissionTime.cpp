#include "InfiniteMissionTime.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	InfiniteMissionTime::InfiniteMissionTime()
	{
		HookManager::install(app::DungeonStageData_DoAfterLoad, DungeonStageData_DoAfterLoad_Hook);
	}

	bool InfiniteMissionTime::DungeonStageData_DoAfterLoad_Hook(app::DungeonStageData* __this, MethodInfo* method)
	{
		if (vars.b_InfiniteMissionTime)
			__this->fields.m_Timelimit = 9999999;

		return CALL_ORIGIN(DungeonStageData_DoAfterLoad_Hook, __this, method);
	}
}
