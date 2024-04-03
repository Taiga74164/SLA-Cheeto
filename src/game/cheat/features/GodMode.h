#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class GodMode : public Singleton<GodMode>
	{
	public:
		GodMode();

	private:
		static int32_t GHINOEFFMPN_EKHGIHBHEPL_Hook(app::SkillIdentity* skillIdentity, void* FKJDKGJBGOD, app::TargetHitData* targetHitData, MethodInfo* method);
	};
}
