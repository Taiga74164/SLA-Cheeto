#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class DamageHack;

	class MobVacuum : public Singleton<MobVacuum>
	{
		friend class DamageHack;
	public:
		MobVacuum();

		void OnPlayerUpdate();
		void OnEnemyUpdate();

	private:
		app::ENNEJEPMJLJ* m_pPlayer;
		app::GameObject* m_pPlayerGO;
		std::vector<app::ENNEJEPMJLJ*> m_pEnemiesVec;
	};
}
