#include "EntityManager.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	EntityManager::EntityManager() : m_pPlayer(nullptr), m_pPlayerGO(nullptr), m_pEnemiesVec(NULL)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(EntityManager::OnPlayerUpdate);
		events::GameUpdateEvent += MY_METHOD_HANDLER(EntityManager::OnEnemyUpdate);

		//HookManager::install(app::ENHPKNIEKMI_MIFDFEHDDDD, ENHPKNIEKMI_MIFDFEHDDDD_Hook);
		HookManager::install(app::ENNEJEPMJLJ_FIGHFBNIDJA, ENNEJEPMJLJ_FIGHFBNIDJA_Hook);
	}

	void EntityManager::OnPlayerUpdate()
	{
		if (m_pPlayer == nullptr)
			return;

		if (!IsCharacterAlive(m_pPlayer))
		{
			LOG(xorstr("IsCharacterAlive returned false, Player is probably not in battle"));
			m_pPlayer = nullptr;
			m_pPlayerGO = nullptr;
			m_pEnemiesVec.clear();
			return;
		}
	}

	void EntityManager::OnEnemyUpdate()
	{
		if (m_pPlayer && m_pEnemiesVec.empty())
			return;

		for (auto& enemy : m_pEnemiesVec)
		{
			if (enemy == nullptr)
				continue;

			auto name = enemy->fields.PEFKKKBMDKN->fields.m_ResourceName;
			if (name == nullptr)
				continue;

			if (!IsCharacterAlive(enemy))
			{
				LOG(xorstr("IsCharacterAlive returned false, Enemy: %s probably died or some shit"), il2cppi_to_string(name).c_str());
				m_pEnemiesVec.erase(std::remove(m_pEnemiesVec.begin(), m_pEnemiesVec.end(), enemy), m_pEnemiesVec.end());
				continue;
			}
		}
	}

	bool EntityManager::IsCharacterAlive(app::ENNEJEPMJLJ* character)
	{
		return app::PCILGJOEPJM_PPAKPBOJLIP(character, nullptr);
	}

	void EntityManager::ENHPKNIEKMI_MIFDFEHDDDD_Hook(app::ENHPKNIEKMI* __this, MethodInfo* method)
	{
		LOG(xorstr("ENHPKNIEKMI_MIFDFEHDDDD_Hook"));

		CALL_ORIGIN(ENHPKNIEKMI_MIFDFEHDDDD_Hook, __this, method);
	}

	app::ENNEJEPMJLJ* EntityManager::GetPlayer() const
	{
		return m_pPlayer;
	}

	app::GameObject* EntityManager::GetPlayerGO() const
	{
		return m_pPlayerGO;
	}

	std::vector<app::ENNEJEPMJLJ*> EntityManager::GetEnemies() const
	{
		return m_pEnemiesVec;
	}

	app::ENHPKNIEKMI* EntityManager::ENNEJEPMJLJ_FIGHFBNIDJA_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method)
	{
		auto& em = EntityManager::GetInstance();
		auto ret = CALL_ORIGIN(ENNEJEPMJLJ_FIGHFBNIDJA_Hook, __this, method);

		if (__this != nullptr &&
			__this->fields.NKONPDBOBAG->fields.IALANALADIL->fields.HOAFECEANLC->fields._.m_CachedPtr != nullptr)
		{
			//LOG(xorstr("resourceName %s"), il2cppi_to_string(__this->fields.PEFKKKBMDKN->fields.m_ResourceName).c_str());
			//LOG(xorstr("CharType %s"), magic_enum::enum_name(__this->fields.AJEHLIOMMJN).data());

			if (__this->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
			{
				em.m_pPlayer = __this;
				em.m_pPlayerGO = __this->fields.NKONPDBOBAG->fields.IALANALADIL->fields.HOAFECEANLC;
			}

			if (__this->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY)
			{
				if (std::find(em.m_pEnemiesVec.begin(), em.m_pEnemiesVec.end(), __this) == em.m_pEnemiesVec.end())
					em.m_pEnemiesVec.push_back(__this);
			}
		}

		return ret;
	}
}
