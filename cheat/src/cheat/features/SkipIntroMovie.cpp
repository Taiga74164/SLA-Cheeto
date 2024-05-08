#include "SkipIntroMovie.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	SkipIntroMovie::SkipIntroMovie()
	{
		HookManager::install(app::IntroMovie_Update, IntroMovie_Update_Hook);
	}

	//void SkipIntroMovie::GameMovie_Update_Hook(app::GameMovie* __this, MethodInfo* method)
	//{
	//	__this->fields.EGHCFMDLNAB = app::GameMovie_PHMCJCHPFEF__Enum::FINISH;
	//	CALL_ORIGIN(GameMovie_Update_Hook, __this, method);
	//}
	void SkipIntroMovie::IntroMovie_Update_Hook(app::IntroMovie* __this, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		
		if (vars.SkipIntroMovie.value())
			__this->fields.GFOGMEGIEJN = app::IntroMovie_MHCMCCIDDCE__Enum::FINISH;
		CALL_ORIGIN(IntroMovie_Update_Hook, __this, method);
	}
}
