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
		static void Char3DIdentity_NAMCAOAHPKA_Hook(app::Char3DIdentity* __this, MethodInfo* method);
		static void Char3DIdentity_OEEGAAAOHIO_Hook(app::Char3DIdentity* __this, MethodInfo* method);
		static bool Char3DIdentity_OPILBOAEJJO_Hook(app::Char3DIdentity* __this, app::AHPHDBJOAGF__Enum FMDEPBPIEMC, MethodInfo* method);
	};
}
