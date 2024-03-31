#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class MissionTime : public Module
	{
	public:
		MissionTime();

		void Load() override {}
		void Update() override {}

	private:
		static void StageReadyPage_EnterUI_Hook(app::StageReadyPage* __this, MethodInfo* method);
	};
}
