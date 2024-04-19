#include "DumbEnemies.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	DumbEnemies::DumbEnemies()
	{
		HookManager::install(app::EvadeProxy_Init, EvadeProxy_Init_Hook);
	}

	void DumbEnemies::EvadeProxy_Init_Hook(app::EvadeProxy* __this, app::ENNEJEPMJLJ* character, app::EvadePenetration* DHPMEMDBDMC, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		
		// Dumb Enemies
		if (character->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY ||
			character->fields.AJEHLIOMMJN == app::ECharacterType__Enum::Monster)
		{
			if (vars.DumbEnemies.value())
			{
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_SidewalkMinTime = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_SidewalkMaxTime = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_BackwalkMinTime = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_BackwalkMaxTime = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_DetectingRange = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_BattleDistance = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_WalkDistance = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_CloseRangeJudgment = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityCloseRangeAttack = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityCloseRangeWander = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityCloseRangeBackWalk = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ImpossibleWanderCloseRange = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityLongRangeAttack = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityLongRangeWander = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ProbabilityLongRangeBackWalk = std::numeric_limits<float>::infinity() * -1.0f;
				character->fields.KFIFBINFDPB->fields.m_pCharBattleInfo->fields.m_ImpossibleWanderLongRange = std::numeric_limits<float>::infinity() * -1.0f;
			}
		}

		// LOG(xorstr("resourceName %s"), il2cppi_to_string(character->fields.PEFKKKBMDKN->fields.m_ResourceName).c_str());

		CALL_ORIGIN(EvadeProxy_Init_Hook, __this, character, DHPMEMDBDMC, method);
	}
}
