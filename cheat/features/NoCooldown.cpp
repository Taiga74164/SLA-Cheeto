#include "NoCooldown.h"
#include "HookManager.h"

namespace Cheat::Features
{
	NoCooldown::NoCooldown()
	{
		HookManager::install(app::KAAIFMKPKAG_IOFMGMJCCFO, KAAIFMKPKAG_IOFMGMJCCFO_Hook);
	}

	void* NoCooldown::KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method)
	{
		__this->fields.HPHOOEPCBOJ = 0;
		__this->fields.JCJJDJGOBJL = 0;

		return CALL_ORIGIN(KAAIFMKPKAG_IOFMGMJCCFO_Hook, __this, DEJNILEHENL, method);
	}
}
