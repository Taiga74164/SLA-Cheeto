#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class MissionTime : public Singleton<MissionTime>
	{
	public:
		MissionTime();
		
	private:
		static void StageReadyPage_EnterUI_Hook(app::StageReadyPage* __this, MethodInfo* method);
	};
}
