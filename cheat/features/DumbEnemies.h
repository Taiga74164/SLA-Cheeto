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
		void Update() override;

	private:
		static void Char3DIdentity_Init_Hook(app::Char3DIdentity* __this, app::ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method);
	};
}
