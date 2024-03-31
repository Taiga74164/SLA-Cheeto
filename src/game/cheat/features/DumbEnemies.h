#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class DumbEnemies : public Singleton<DumbEnemies>
	{
	public:
		DumbEnemies();

	private:
		static void EvadeProxy_Init_Hook(app::EvadeProxy* __this, app::ENNEJEPMJLJ* character, app::EvadePenetration* DHPMEMDBDMC, MethodInfo* method);
	};
}
