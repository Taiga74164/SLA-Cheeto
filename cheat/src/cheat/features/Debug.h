#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class Debug : public Singleton<Debug>
	{
	public:
		Debug();

		void OnGameUpdate();

	private:
		static void ENHPKNIEKMI_MIFDFEHDDDD_Hook(app::ENHPKNIEKMI* __this, MethodInfo* method);
		static app::ENHPKNIEKMI* ENNEJEPMJLJ_FIGHFBNIDJA_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method);
	};
}
