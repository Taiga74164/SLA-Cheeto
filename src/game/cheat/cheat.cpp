#include "cheat.h"
#include "global.h"
#include "HookManager.h"
#include "events.h"

#include "features/PlayerSpeed.h"
#include "features/NoCooldown.h"
#include "features/DamageHack.h"
#include "features/GodMode.h"
#include "features/DumbEnemies.h"
#include "features/FovChanger.h"
#include "features/FPSUnlock.h"
#include "features/MissionTime.h"
#include "features/TimeScale.h"
#include "features/SkipIntroMovie.h"
#include "features/DisableWebView.h"

using namespace Cheat::Features;

static void GameFrameWork_Update_Hook(app::GameFrameWork* __this, MethodInfo* method);

void init_cheat()
{
#define INIT_FEATURE(feature) feature::GetInstance()
	INIT_FEATURE(PlayerSpeed);
	INIT_FEATURE(NoCooldown);
	INIT_FEATURE(DamageHack);
	INIT_FEATURE(GodMode);
	INIT_FEATURE(DumbEnemies);
	INIT_FEATURE(MissionTime);
	INIT_FEATURE(TimeScale);
	INIT_FEATURE(SkipIntroMovie);
	INIT_FEATURE(FPSUnlock);
	INIT_FEATURE(FovChanger);
	INIT_FEATURE(DisableWebView);
#undef INIT_FEATURE

	HookManager::install(app::GameFrameWork_Update, GameFrameWork_Update_Hook);
}

void GameFrameWork_Update_Hook(app::GameFrameWork* __this, MethodInfo* method)
{
	SAFE_BEGIN();
	events::GameUpdateEvent();
	SAFE_EEND();
	CALL_ORIGIN(GameFrameWork_Update_Hook, __this, method);
}