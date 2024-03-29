#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class InfiniteMissionTime : public Module
	{
	public:
		InfiniteMissionTime();

		void Load() override {}
		void Update() override {}

	private:
		static bool DungeonStageData_DoAfterLoad_Hook(app::DungeonStageData* __this, MethodInfo* method);
	};
}
