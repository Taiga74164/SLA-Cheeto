#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class PlayerSpeed : public Singleton<PlayerSpeed>
	{
	public:
		PlayerSpeed();

		void OnGameUpdate();

	private:
		static void JIBDAHKJHOG_KPDGECAFJKA_Hook(app::JIBDAHKJHOG * __this, MethodInfo * method);
		static void JIBDAHKJHOG_HLLNLMAECBD_Hook(app::JIBDAHKJHOG * __this, void * JONOLJGMLBE, void * BHMPNNCBFGN, MethodInfo * method);
		static void JIBDAHKJHOG_COLDHPFDOHG_Hook(app::JIBDAHKJHOG * __this, MethodInfo * method);
	};
}
