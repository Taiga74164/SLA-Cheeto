#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class EntityManager : public Singleton<EntityManager>
	{
	public:
		EntityManager();

		void OnPlayerUpdate();
		void OnEnemyUpdate();

		app::ENNEJEPMJLJ* GetPlayer() const;
		app::GameObject* GetPlayerGO() const;
		std::vector<app::ENNEJEPMJLJ*> GetEnemies() const;

	private:
		static void ENHPKNIEKMI_MIFDFEHDDDD_Hook(app::ENHPKNIEKMI* __this, MethodInfo* method);
		static app::ENHPKNIEKMI* ENNEJEPMJLJ_FIGHFBNIDJA_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method);

		app::ENNEJEPMJLJ* m_pPlayer;
		app::GameObject* m_pPlayerGO;
		std::vector<app::ENNEJEPMJLJ*> m_pEnemiesVec;
	};
}
