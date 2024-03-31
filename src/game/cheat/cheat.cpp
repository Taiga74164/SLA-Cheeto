#include "cheat.h"
#include "ModuleManager.h"
#include "global.h"
#include "HookManager.h"

#include "features/PlayerSpeed.h"
#include "features/NoCooldown.h"
#include "features/DamageHack.h"
#include "features/DumbEnemies.h"
#include "features/FPSUnlock.h"
#include "features/MissionTime.h"
#include "features/TimeScale.h"
#include "features/SkipIntroMovie.h"

using namespace Cheat::Features;

static void GameFrameWork_Update_Hook(app::GameFrameWork* __this, MethodInfo* method);

void init_cheat()
{
	auto& manager = ModuleManager::GetInstance();

#define REGISTER(Class) ModuleManager::GetInstance().RegisterModule(std::make_unique<Class>());
	REGISTER(PlayerSpeed);
	REGISTER(NoCooldown);
	REGISTER(DamageHack);
	REGISTER(DumbEnemies);
	REGISTER(MissionTime);
	REGISTER(TimeScale);
	REGISTER(SkipIntroMovie);
	REGISTER(FPSUnlock);
#undef REGISTER

	manager.LoadAllModules();

	HookManager::install(app::GameFrameWork_Update, GameFrameWork_Update_Hook);
}

// TODO: Replace this later with event system
void run_cheat()
{
	SAFE_BEGIN();
	//ModuleManager::GetInstance().UpdateAllModules();
	SAFE_EEND();
}

// Event Handler
void GameFrameWork_Update_Hook(app::GameFrameWork* __this, MethodInfo* method)
{
	SAFE_BEGIN();
	//LOG("GameFrameWork::Update");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	//LOG("ITS LOGGING GOOD JOB WOW !!!!!!!!!!");
	SAFE_EEND();
	CALL_ORIGIN(GameFrameWork_Update_Hook, __this, method);
}