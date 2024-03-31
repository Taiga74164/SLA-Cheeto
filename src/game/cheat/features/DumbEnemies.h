#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class DumbEnemies : public Module
	{
	public:
		DumbEnemies();

		void Load() override {}
		void Update() override {}

	private:
		static void EvadeProxy_Init_Hook(app::EvadeProxy* __this, app::ENNEJEPMJLJ* character, app::EvadePenetration* DHPMEMDBDMC, MethodInfo* method);
	};
}
