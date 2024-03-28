#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class PlayerSpeed : public Module
	{
	public:
		PlayerSpeed();

		void Load() override {}
		void Update() override;

	private:
		static void* ENNEJEPMJLJ_GNAPBJPBKIO_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method);
	};
}
