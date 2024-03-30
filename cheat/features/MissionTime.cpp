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
		if (vars.b_MissionTime)
			__this->fields.FHMGDAMDBHG->fields.m_Timelimit = vars.i_InfiniteMissionTimeMs;

		auto battleSquadType = __this->fields.EIMKAHCHPGP;
		auto battleTeamType = __this->fields.AKIOKCBHJML;;
		auto someEnum = __this->fields.NJIPKOGOLMI;
		auto uiType = __this->fields._._.KDDJIEAFDBO;

		LOG("battleSquadType: %s", magic_enum::enum_name(battleSquadType).data());
		LOG("battleTeamType: %s", magic_enum::enum_name(battleTeamType).data());
		LOG("someEnum: %s", magic_enum::enum_name(someEnum).data());
		LOG("UI Type: %s", magic_enum::enum_name(uiType).data());
		if (__this->fields.FHMGDAMDBHG != nullptr)
		{
			LOG("Timelimit: %d", __this->fields.FHMGDAMDBHG->fields.m_Timelimit);
		}

		CALL_ORIGIN(StageReadyPage_EnterUI_Hook, __this, method);
	}
}
