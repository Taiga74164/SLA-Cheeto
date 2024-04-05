#include "DamageHack.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

#include "MobVacuum.h"

namespace Cheat::Features
{
	DamageHack::DamageHack()
	{
		HookManager::install(app::PIPHNBOBFEF_KBCIIEFLPGB, PIPHNBOBFEF_KBCIIEFLPGB_Hook);
	}

	void DamageHack::PIPHNBOBFEF_KBCIIEFLPGB_Hook(app::PIPHNBOBFEF* __this, app::ESpecialState__Enum specialState, int64_t someInt1, int64_t someInt2, int64_t someInt3, app::String* buffName, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		auto& vacuum = MobVacuum::GetInstance();

		if (__this->fields.IGFILCLEFHH->fields.EJBODHBGPMG != nullptr)
		{
			auto entity = __this->fields.IGFILCLEFHH->fields.EJBODHBGPMG;
			auto entityFields = entity->fields;
			//LOG("%s", magic_enum::enum_name(entity->fields.FHNGHHPLPGD).data());
			//LOG("resourceName %s", il2cppi_to_string(entity->fields.PEFKKKBMDKN->fields.m_ResourceName).c_str());
			//LOG("specialState %s", magic_enum::enum_name(specialState).data());
			//LOG("int1 %d", someInt1);
			//LOG("int2 %d", someInt2);
			//LOG("int3 %d", someInt3);
			//LOG("someStr %s", il2cppi_to_string(buffName).c_str());

			if (entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
			{
				// God Mode
				if (vars.GodMode.value())
				{
					if (specialState == app::ESpecialState__Enum::None ||
						specialState == app::ESpecialState__Enum::DotDamage)
						CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Invincible, someInt1, 3500i64, 4000i64, buffName, method);

					if (specialState == app::ESpecialState__Enum::HpRecovery ||
						specialState == app::ESpecialState__Enum::MpRecovery ||
						specialState == app::ESpecialState__Enum::PgRecovery)
						CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, 2i64, 99999999i64, 0i64, buffName, method);
				}

				vacuum.m_pPlayer = entity;
				vacuum.m_pPlayerGO = entity->fields.NKONPDBOBAG->fields.IALANALADIL->fields.HOAFECEANLC;
			}

			if (entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY)
			{
				if (vars.DamageHack.value())
					CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::FixDamage, static_cast<int64_t>(vars.DamageHackValue.value()), 0i64, 0i64, buffName, method);

				if (vars.KillAura.value())
				{
					CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::DotDamage, 2i64, 99999999i64, 0i64, buffName, method);
					CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Shield, 2i64, -99999999i64, 0i64, buffName, method);
					CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::DotBreak, 2i64, 99999999i64, 0i64, buffName, method);
				}

				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Crash, 2i64, 99999999i64, 0i64, buffName, method);
				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Stun, 2i64, 1000i64, 0i64, buffName, method);
				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::BodyStop, 2i64, 1000i64, 0i64, buffName, method);

				if (std::find(vacuum.m_pEnemiesVec.begin(), vacuum.m_pEnemiesVec.end(), entity) == vacuum.m_pEnemiesVec.end())
					vacuum.m_pEnemiesVec.push_back(entity);
			}
		}

		CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, someInt1, someInt2, someInt3, buffName, method);
	}
}
