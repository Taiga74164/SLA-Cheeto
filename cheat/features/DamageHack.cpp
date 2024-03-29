#include "DamageHack.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "limits.h"

namespace Cheat::Features
{
	DamageHack::DamageHack()
	{
		HookManager::install(app::PIPHNBOBFEF_KBCIIEFLPGB, PIPHNBOBFEF_KBCIIEFLPGB_Hook);
		HookManager::install(app::GHINOEFFMPN_EKHGIHBHEPL, GHINOEFFMPN_EKHGIHBHEPL_Hook);
	}

	void DamageHack::PIPHNBOBFEF_KBCIIEFLPGB_Hook(app::PIPHNBOBFEF* __this, app::ESpecialState__Enum specialState, int64_t someInt1, int64_t someInt2, int64_t someInt3, app::String* buffName, MethodInfo* method)
	{
		if (__this->fields.IGFILCLEFHH->fields.EJBODHBGPMG != nullptr)
		{
			auto entity = __this->fields.IGFILCLEFHH->fields.EJBODHBGPMG;
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
				if (vars.v_GodMode)
				{
					if (specialState == app::ESpecialState__Enum::None ||
						specialState == app::ESpecialState__Enum::DotDamage)
						CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Invincible, someInt1, 3500i64, 4000i64, buffName, method);

					if (specialState == app::ESpecialState__Enum::HpRecovery ||
						specialState == app::ESpecialState__Enum::MpRecovery ||
						specialState == app::ESpecialState__Enum::PgRecovery)
						CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, 2i64, 99999999i64, 0i64, buffName, method);
				}
			}

			if (entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY)
			{
				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Crash, 2i64, 99999999i64, 0i64, buffName, method);
				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::Stun, 2i64, 1000i64, 0i64, buffName, method);
				// CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, app::ESpecialState__Enum::BodyStop, 2i64, 1000i64, 0i64, buffName, method);
			}
		}

		CALL_ORIGIN(PIPHNBOBFEF_KBCIIEFLPGB_Hook, __this, specialState, someInt1, someInt2, someInt3, buffName, method);
	}

	int32_t DamageHack::GHINOEFFMPN_EKHGIHBHEPL_Hook(app::SkillIdentity* skillIdentity, void* FKJDKGJBGOD, app::TargetHitData* targetHitData, MethodInfo* method)
	{
		if (skillIdentity->fields.entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
		{
			//auto skillRange = skillIdentity->fields.SkillRange;
			//auto skillMinRange = skillIdentity->fields.SkillMinRange;
			//auto reaction = targetHitData->fields._reaction;
			//auto preventSkillCancel = targetHitData->fields.PreventSkillCancel;
			//auto damageRatio = targetHitData->fields.damageRatio;
			//auto damageRatioTotalValue = targetHitData->fields.damageRatioTotalValue;

			//LOG("Player:");
			//LOG("skillRange %f", skillRange);
			//LOG("skillMinRange %f", skillMinRange);
			//LOG("reaction %s", magic_enum::enum_name(reaction).data());
			//LOG("preventSkillCancel %s", preventSkillCancel ? "true" : "false");
			//LOG("damageRatio %f", damageRatio);
			//LOG("damageRatioTotalValue %f", damageRatioTotalValue);

			if (vars.v_DamageHack)
			{
				skillIdentity->fields.SkillRange = 500.0f;
				skillIdentity->fields.SkillMinRange = 500.0f;
				targetHitData->fields._reaction = app::eReactionType__Enum::Max;
				targetHitData->fields.PreventSkillCancel = true;
				targetHitData->fields.damageRatio = 500.0f;
				targetHitData->fields.damageRatioTotalValue = 500.0f;
			}
		}

		if (skillIdentity->fields.entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY || 
			skillIdentity->fields.entity->fields.AJEHLIOMMJN == app::ECharacterType__Enum::Monster)
		{
			//auto skillRange = skillIdentity->fields.SkillRange;
			//auto skillMinRange = skillIdentity->fields.SkillMinRange;
			//auto reaction = targetHitData->fields._reaction;
			//auto preventSkillCancel = targetHitData->fields.PreventSkillCancel;
			//auto damageRatio = targetHitData->fields.damageRatio;
			//auto damageRatioTotalValue = targetHitData->fields.damageRatioTotalValue;

			//LOG("Enemy:");
			//LOG("skillRange %f", skillRange);
			//LOG("skillMinRange %f", skillMinRange);
			//LOG("reaction %s", magic_enum::enum_name(reaction).data());
			//LOG("preventSkillCancel %s", preventSkillCancel ? "true" : "false");
			//LOG("damageRatio %f", damageRatio);
			//LOG("damageRatioTotalValue %f", damageRatioTotalValue);

			if (vars.v_GodMode)
			{
				skillIdentity->fields.SkillRange = -1.0f;
				skillIdentity->fields.SkillMinRange = -1.0f;
				targetHitData->fields._reaction = app::eReactionType__Enum::None;
				targetHitData->fields.damageRatio = std::numeric_limits<float>::infinity() * -1.0f;
				targetHitData->fields.damageRatioTotalValue = std::numeric_limits<float>::infinity() * -1.0f;
			}
		}

		return CALL_ORIGIN(GHINOEFFMPN_EKHGIHBHEPL_Hook, skillIdentity, FKJDKGJBGOD, targetHitData, method);
	}
}
