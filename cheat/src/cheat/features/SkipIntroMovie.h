#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class SkipIntroMovie : public Singleton<SkipIntroMovie>
	{
	public:
		SkipIntroMovie();

	private:
		static void IntroMovie_Update_Hook(app::IntroMovie* __this, MethodInfo* method);
	};
}
