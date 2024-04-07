#include "EntityManager.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	EntityManager::EntityManager() : m_pPlayer(nullptr), m_pPlayerGO(nullptr), m_pEnemiesVec(NULL)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(EntityManager::OnGameUpdate);

		//HookManager::install(app::ENHPKNIEKMI_MIFDFEHDDDD, ENHPKNIEKMI_MIFDFEHDDDD_Hook);
		HookManager::install(app::ENNEJEPMJLJ_FIGHFBNIDJA, ENNEJEPMJLJ_FIGHFBNIDJA_Hook);
	}

	void EntityManager::OnGameUpdate()
	{
		if (m_pPlayer == nullptr)
			return;

		if (!app::PCILGJOEPJM_PPAKPBOJLIP(m_pPlayer, nullptr))
		{
			LOG("PCILGJOEPJM_PPAKPBOJLIP failed");
			m_pPlayer = nullptr;
			m_pPlayerGO = nullptr;
			return;
		}
	}

	void EntityManager::ENHPKNIEKMI_MIFDFEHDDDD_Hook(app::ENHPKNIEKMI* __this, MethodInfo* method)
	{
		LOG("ENHPKNIEKMI_MIFDFEHDDDD_Hook");

		CALL_ORIGIN(ENHPKNIEKMI_MIFDFEHDDDD_Hook, __this, method);
	}

	app::ENHPKNIEKMI* EntityManager::ENNEJEPMJLJ_FIGHFBNIDJA_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method)
	{
		auto& em = EntityManager::GetInstance();
		auto ret = CALL_ORIGIN(ENNEJEPMJLJ_FIGHFBNIDJA_Hook, __this, method);

		if (__this != nullptr &&
			__this->fields.NKONPDBOBAG->fields.IALANALADIL->fields.HOAFECEANLC->fields._.m_CachedPtr != nullptr)
		{
			//LOG("resourceName %s", il2cppi_to_string(__this->fields.PEFKKKBMDKN->fields.m_ResourceName).c_str());
			//LOG("CharType %s", magic_enum::enum_name(__this->fields.AJEHLIOMMJN).data());

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
