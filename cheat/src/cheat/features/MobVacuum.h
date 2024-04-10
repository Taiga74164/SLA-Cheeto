#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class MobVacuum : public Singleton<MobVacuum>
	{
	public:
		MobVacuum();
		
		void OnGameUpdate();

		bool IsMobInRange(app::Transform* enemyTransform, app::Transform* playerTransform, float offset);
		app::Vector3 CalcMobOffset();
	};
}
