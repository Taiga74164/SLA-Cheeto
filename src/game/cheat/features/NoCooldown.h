#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class NoCooldown : public Singleton<NoCooldown>
	{
	public:
		NoCooldown();

	private:
		static void* KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method);
	};
}
