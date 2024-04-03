#include "NoCooldown.h"
#include "HookManager.h"

namespace Cheat::Features
{
	NoCooldown::NoCooldown()
	{
		HookManager::install(app::KAAIFMKPKAG_IOFMGMJCCFO, KAAIFMKPKAG_IOFMGMJCCFO_Hook);
		HookManager::install(app::JLLMICINIDA_LFCGJLAFFOM, JLLMICINIDA_LFCGJLAFFOM_Hook);
	}

	void NoCooldown::JLLMICINIDA_LFCGJLAFFOM_Hook(app::JLLMICINIDA* __this, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();

		if (vars.NoCooldownShadow.value() && __this)
		{
			__this->fields.DGPHADJBCDJ = 0.0f;
			__this->fields.KKEDBBAMIJL = 1;
		}

		return CALL_ORIGIN(JLLMICINIDA_LFCGJLAFFOM_Hook, __this, method);
	}

	void* NoCooldown::KAAIFMKPKAG_IOFMGMJCCFO_Hook(app::KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		
		if (vars.NoCooldown.value())
		{
			__this->fields.HPHOOEPCBOJ = 0;
			__this->fields.JCJJDJGOBJL = 0;
		}

		return CALL_ORIGIN(KAAIFMKPKAG_IOFMGMJCCFO_Hook, __this, DEJNILEHENL, method);
	}
}
