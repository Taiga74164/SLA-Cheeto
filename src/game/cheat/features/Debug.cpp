#include "Debug.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	Debug::Debug()
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(Debug::OnGameUpdate);

		//HookManager::install(app::Char3DIdentity_NAMCAOAHPKA, Char3DIdentity_NAMCAOAHPKA_Hook);
		HookManager::install(app::Char3DIdentity_OEEGAAAOHIO, Char3DIdentity_OEEGAAAOHIO_Hook);
		//HookManager::install(app::Char3DIdentity_OPILBOAEJJO, Char3DIdentity_OPILBOAEJJO_Hook);
	}

	void Debug::OnGameUpdate()
	{
	}

	void Debug::Char3DIdentity_NAMCAOAHPKA_Hook(app::Char3DIdentity* __this, MethodInfo* method)
	{
		if (__this->fields._._._._.m_CachedPtr != nullptr)
		{
			if (__this->fields.EJBODHBGPMG != nullptr)
				LOG("Char3DIdentity_NAMCAOAHPKA_Hook\n");
		}
		CALL_ORIGIN(Char3DIdentity_NAMCAOAHPKA_Hook, __this, method);
	}
	void Debug::Char3DIdentity_OEEGAAAOHIO_Hook(app::Char3DIdentity* __this, MethodInfo* method)
	{
		if (__this->fields._._._._.m_CachedPtr != nullptr)
		{
			if (__this->fields.EJBODHBGPMG != nullptr)
				LOG("Char3DIdentity_OPILBOAEJJO_Hook");
		}
		CALL_ORIGIN(Char3DIdentity_OEEGAAAOHIO_Hook, __this, method);
	}
	bool Debug::Char3DIdentity_OPILBOAEJJO_Hook(app::Char3DIdentity* __this, app::AHPHDBJOAGF__Enum FMDEPBPIEMC, MethodInfo* method)
	{
		if (__this->fields._._._._.m_CachedPtr != nullptr)
		{
			if (__this->fields.EJBODHBGPMG != nullptr)
				LOG("Char3DIdentity_OPILBOAEJJO_Hook");
		}
		
		return CALL_ORIGIN(Char3DIdentity_OPILBOAEJJO_Hook, __this, FMDEPBPIEMC, method);
	}
}
