#include "NoCooldown.h"
#include "HookManager.h"

namespace Cheat::Features
{
	NoCooldown::NoCooldown()
	{
		HookManager::install(app::KAAIFMKPKAG_IOFMGMJCCFO, KAAIFMKPKAG_IOFMGMJCCFO_Hook);
		HookManager::install(app::JLLMICINIDA__LFCGJLAFFOM, JLLMICINIDA__LFCGJLAFFOM_Hook);
	}

	void NoCooldown::JLLMICINIDA__LFCGJLAFFOM_Hook(app::JLLMICINIDA* __this, MethodInfo* method)
	{
		if (vars.b_NoCooldown && __this)
		{
			__this->fields.DGPHADJBCDJ = 0.0f;
			__this->fields.KKEDBBAMIJL = 1;
		}
		return CALL_ORIGIN(JLLMICINIDA__LFCGJLAFFOM_Hook, __this, method);
	}

	void* NoCooldown::KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method)
	{
		if (vars.b_NoCooldown)
		{
			__this->fields.HPHOOEPCBOJ = 0;
			__this->fields.JCJJDJGOBJL = 0;
		}

		return CALL_ORIGIN(KAAIFMKPKAG_IOFMGMJCCFO_Hook, __this, DEJNILEHENL, method);
	}
}
