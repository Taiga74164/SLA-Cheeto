#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class NoCooldown : public Module
	{
	public:
		NoCooldown();

		void Load() override {}
		void Update() override {}

	private:
		static void* KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method);
	};
}
