#include "MobVacuum.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	MobVacuum::MobVacuum() :
		m_pPlayer(nullptr), m_pPlayerGO(nullptr)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(MobVacuum::OnPlayerUpdate);
		events::GameUpdateEvent += MY_METHOD_HANDLER(MobVacuum::OnEnemyUpdate);
	}

	void MobVacuum::OnPlayerUpdate()
	{
		if (m_pPlayer == nullptr)
			return;

		if (!app::PCILGJOEPJM_PPAKPBOJLIP(m_pPlayer, nullptr))
		{
			m_pPlayer = nullptr;
			m_pPlayerGO = nullptr;
			return;
		}

		//auto someBaseClass = m_pPlayer->fields.NKONPDBOBAG;
		//auto char3d = someBaseClass->fields.KCGPELIKJKK;
		//auto charResourceContainer = someBaseClass->fields.BLHAMCDGFPB;
		//auto playerObj = someBaseClass->fields.IALANALADIL->fields.HOAFECEANLC;

		// LOG("Obj name: %s", GetName(playerObj).c_str());
	}

	void MobVacuum::OnEnemyUpdate()
	{
		if (m_pEnemiesVec.empty())
			return;

		if (m_pPlayer == nullptr || m_pPlayerGO == nullptr)
			return;

		auto& vars = Vars::GetInstance();

		for (auto& enemy : m_pEnemiesVec)
		{
			if (!app::PCILGJOEPJM_PPAKPBOJLIP(enemy, nullptr))
			{
				m_pEnemiesVec.erase(std::remove(m_pEnemiesVec.begin(), m_pEnemiesVec.end(), enemy), m_pEnemiesVec.end());
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

				auto enemyPosition = app::Transform_get_position(enemyTransform, nullptr);
				auto playerTransform = app::GameObject_get_transform(m_pPlayerGO, nullptr);
				auto playerPosition = app::Transform_get_position(playerTransform, nullptr);
				auto playerForward = app::Transform_get_forward(playerTransform, nullptr);

				// TODO:
				// Add distance check.
				// Add offset to the player position.
				auto distance = app::Vector3_Distance(enemyPosition, playerPosition, nullptr);

				// Set the enemy position to the player position + the forward vector
				app::Transform_set_position(enemyTransform, playerPosition + (playerForward * 1.5f), nullptr);
			}
		}
	}
}
