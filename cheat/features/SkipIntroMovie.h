#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class SkipIntroMovie : public Module
	{
	public:
		SkipIntroMovie();

		void Load() override {}
		void Update() override {}

	private:
		static void GameMovie_Update_Hook(app::GameMovie* __this, MethodInfo* method);
		static void IntroMovie_Update_Hook(app::IntroMovie* __this, MethodInfo* method);
	};
}
