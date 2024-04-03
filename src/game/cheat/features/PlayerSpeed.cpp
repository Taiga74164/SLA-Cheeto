#include "PlayerSpeed.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	PlayerSpeed::PlayerSpeed()
	{
		//events::GameUpdateEvent += MY_METHOD_HANDLER(PlayerSpeed::OnGameUpdate);
		//HookManager::install(app::JIBDAHKJHOG_KPDGECAFJKA, JIBDAHKJHOG_KPDGECAFJKA_Hook);
		//HookManager::install(app::JIBDAHKJHOG_HLLNLMAECBD, JIBDAHKJHOG_HLLNLMAECBD_Hook);
		//HookManager::install(app::JIBDAHKJHOG_COLDHPFDOHG, JIBDAHKJHOG_COLDHPFDOHG_Hook);
	}


	void PlayerSpeed::OnGameUpdate()
	{
		// auto instance = GET_SINGLETON_1(JIBDAHKJHOG);
		// if (instance == nullptr)
		// {
		// 	LOG("Instance JIBDAHKJHOG is null");
		// 	return;
		// }
	}
	
	void PlayerSpeed::JIBDAHKJHOG_KPDGECAFJKA_Hook(app::JIBDAHKJHOG * __this, MethodInfo * method)
	{
		LOG("JIBDAHKJHOG_KPDGECAFJKA_Hook");

		CALL_ORIGIN(JIBDAHKJHOG_KPDGECAFJKA_Hook, __this, method);
	}
	void PlayerSpeed::JIBDAHKJHOG_HLLNLMAECBD_Hook(app::JIBDAHKJHOG * __this, void * JONOLJGMLBE, void * BHMPNNCBFGN, MethodInfo * method)
	{
		LOG("JIBDAHKJHOG_HLLNLMAECBD_Hook: %s", magic_enum::enum_name(__this->fields.ODBFJKNANFA).data());
		app::JIBDAHKJHOG_EJLDBPGJGPN(__this, nullptr);
		__this->fields.ODBFJKNANFA = app::EGLGAPIAANF__Enum::CompleteBattle;
		CALL_ORIGIN(JIBDAHKJHOG_HLLNLMAECBD_Hook, __this, JONOLJGMLBE, BHMPNNCBFGN, method);
	}
	void PlayerSpeed::JIBDAHKJHOG_COLDHPFDOHG_Hook(app::JIBDAHKJHOG * __this, MethodInfo * method)
	{
		LOG("JIBDAHKJHOG_COLDHPFDOHG_Hook: %s", magic_enum::enum_name(__this->fields.ODBFJKNANFA).data());
		app::JIBDAHKJHOG_EJLDBPGJGPN(__this, nullptr);
		__this->fields.ODBFJKNANFA = app::EGLGAPIAANF__Enum::CompleteBattle;
		CALL_ORIGIN(JIBDAHKJHOG_COLDHPFDOHG_Hook, __this, method);
	}

}
