#include "MobVacuum.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

#include "EntityManager.h"

namespace Cheat::Features
{
	MobVacuum::MobVacuum()
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(MobVacuum::OnGameUpdate);
	}

	void MobVacuum::OnGameUpdate()
	{
		auto& em = EntityManager::GetInstance();
		auto& vars = Vars::GetInstance();

		if (em.m_pEnemiesVec.empty())
			return;

		if (em.m_pPlayer == nullptr || em.m_pPlayerGO == nullptr)
			return;

		auto targetPosition = CalcMobOffset();
		if (IsVectorZero(targetPosition))
			return;

		for (auto& enemy : em.m_pEnemiesVec)
		{
			if (!app::PCILGJOEPJM_PPAKPBOJLIP(enemy, nullptr))
			{
				em.m_pEnemiesVec.erase(std::remove(em.m_pEnemiesVec.begin(), em.m_pEnemiesVec.end(), enemy), em.m_pEnemiesVec.end());
				continue;
			}

			if (vars.MobVacuum.value())
			{
				auto someBaseClass = enemy->fields.NKONPDBOBAG;
				if (someBaseClass == nullptr)
					continue;

				auto enemyObj = someBaseClass->fields.IALANALADIL->fields.HOAFECEANLC;
				if (enemyObj == nullptr)
					continue;

				auto enemyTransform = app::GameObject_get_transform(enemyObj, nullptr);
				if (enemyTransform == nullptr)
					continue;
				
				auto playerTransform = app::GameObject_get_transform(em.m_pPlayerGO, nullptr);
				if (IsMobInRange(enemyTransform, playerTransform, vars.VacuumRange.value()))
					app::Transform_set_position(enemyTransform, targetPosition, nullptr);
			}
		}
	}

	bool MobVacuum::IsMobInRange(app::Transform* enemyTransform, app::Transform* playerTransform, float offset)
	{
		if (enemyTransform == nullptr || playerTransform == nullptr)
			return false;

		auto enemyPosition = app::Transform_get_position(enemyTransform, nullptr);
		auto playerPosition = app::Transform_get_position(playerTransform, nullptr);
		auto distance = app::Vector3_Distance(enemyPosition, playerPosition, nullptr);

		return distance <= offset;
	}

	app::Vector3 MobVacuum::CalcMobOffset()
	{
		auto& em = EntityManager::GetInstance();
		auto& vars = Vars::GetInstance();

		auto playerTransform = app::GameObject_get_transform(em.m_pPlayerGO, nullptr);
		if (playerTransform == nullptr)
			return {};

		auto playerPosition = app::Transform_get_position(playerTransform, nullptr);
		auto playerForward = app::Transform_get_forward(playerTransform, nullptr);

		return playerPosition + playerForward * vars.VacuumDistance.value();
	}
}
