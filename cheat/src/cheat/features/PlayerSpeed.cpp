#include "PlayerSpeed.h"

#include "EntityManager.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	PlayerSpeed::PlayerSpeed() : m_pAnimator(nullptr), m_InitialSpeed(-1.0f), m_DidSpeed(false)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(PlayerSpeed::OnGameUpdate);
	}

	void PlayerSpeed::OnGameUpdate()
	{
		//auto& em = EntityManager::GetInstance();
		//auto& vars = Vars::GetInstance();

		//auto player = em.GetPlayer();
		//if (player == nullptr)
		//{
		//	m_pAnimator = nullptr;
		//	m_DidSpeed = false;
		//	return;
		//}

		//auto resourceData = player->fields.PEFKKKBMDKN;
		//if (resourceData == nullptr)
		//	return;

		//auto battleInfoData = player->fields.KFIFBINFDPB->fields.m_pCharBattleInfo;
		//if (battleInfoData == nullptr)
		//	return;

		//auto modelContainer = player->fields.NKONPDBOBAG->fields.JOJBJOHCOAI; //player->fields.NKONPDBOBAG->fields.BLHAMCDGFPB->fields.m_pkAnimator;
		//if (modelContainer == nullptr)
		//{
		//	LOG(xorstr("PlayerSpeed::OnGameUpdate: modelContainer is null");
		//	return;
		//}

		//auto animator = app::ModelContainer_get_animator(modelContainer, nullptr);
		//if (animator == nullptr)
		//{
		//	LOG(xorstr("PlayerSpeed::OnGameUpdate: animator is null");
		//	return;
		//}

		//if (m_InitialSpeed == -1.0f)
		//	m_InitialSpeed = app::Animator_get_speed(animator, nullptr);

		//m_pAnimator = animator;

		//if (vars.PlayerSpeed.value())
		//{
			//app::Animator_set_speed(animator, vars.PlayerSpeedValue.value(), nullptr);
			//m_DidSpeed = true;
			//resourceData->fields.m_WalkSpeed = vars.PlayerSpeedValue.value();
			//resourceData->fields.m_MoveSpd = vars.PlayerSpeedValue.value();
			//resourceData->fields.m_SidewalkSpeed = vars.PlayerSpeedValue.value();
			//resourceData->fields.m_BackwalkSpeed = vars.PlayerSpeedValue.value();

			//battleInfoData->fields.m_SidewalkMinTime = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_SidewalkMaxTime = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_BackwalkMinTime = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_BackwalkMaxTime = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_DetectingRange = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_BattleDistance = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_WalkDistance = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_CloseRangeJudgment = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityCloseRangeAttack = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityCloseRangeWander = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityCloseRangeBackWalk = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ImpossibleWanderCloseRange = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityLongRangeAttack = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityLongRangeWander = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ProbabilityLongRangeBackWalk = vars.PlayerSpeedValue.value();
			//battleInfoData->fields.m_ImpossibleWanderLongRange = vars.PlayerSpeedValue.value();
		//}
		//else
		//{
			//if (m_DidSpeed)
			//{
			//	app::Animator_set_speed(animator, m_InitialSpeed, nullptr);
			//	m_DidSpeed = false;
			//}
		//}
	}
}
