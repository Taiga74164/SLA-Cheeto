#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class MobVacuum;

	class EntityManager : public Singleton<EntityManager>
	{
		friend class MobVacuum;
	public:
		EntityManager();

		void OnGameUpdate();

	private:
		static void ENHPKNIEKMI_MIFDFEHDDDD_Hook(app::ENHPKNIEKMI* __this, MethodInfo* method);
		static app::ENHPKNIEKMI* ENNEJEPMJLJ_FIGHFBNIDJA_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method);

		app::ENNEJEPMJLJ* m_pPlayer;
		app::GameObject* m_pPlayerGO;
		std::vector<app::ENNEJEPMJLJ*> m_pEnemiesVec;
	};
}
