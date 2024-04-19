#include "GodMode.h"
#include "events.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "limits.h"

namespace Cheat::Features
{
	GodMode::GodMode()
	{
		HookManager::install(app::GHINOEFFMPN_EKHGIHBHEPL, GHINOEFFMPN_EKHGIHBHEPL_Hook);
	}

	int32_t GodMode::GHINOEFFMPN_EKHGIHBHEPL_Hook(app::SkillIdentity* skillIdentity, void* FKJDKGJBGOD, app::TargetHitData* targetHitData, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();

		auto entity = skillIdentity->fields.entity;
		//auto skillRange = skillIdentity->fields.SkillRange;
		//auto skillMinRange = skillIdentity->fields.SkillMinRange;
		//auto reaction = targetHitData->fields._reaction;
		//auto preventSkillCancel = targetHitData->fields.PreventSkillCancel;
		//auto damageRatio = targetHitData->fields.damageRatio;
		//auto damageRatioTotalValue = targetHitData->fields.damageRatioTotalValue;

		//LOG(xorstr("%s", magic_enum::enum_name(skillIdentity->fields.entity->fields.FHNGHHPLPGD).data());
		//LOG(xorstr("skillRange %f", skillRange);
		//LOG(xorstr("skillMinRange %f", skillMinRange);
		//LOG(xorstr("reaction %s", magic_enum::enum_name(reaction).data());
		//LOG(xorstr("preventSkillCancel %s", preventSkillCancel ? "true" : "false");
		//LOG(xorstr("damageRatio %f", damageRatio);
		//LOG(xorstr("damageRatioTotalValue %f", damageRatioTotalValue);

		if (skillIdentity->fields.entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
		{
			//if (vars.DamageHack.value())
			//{
			//	skillIdentity->fields.SkillRange = static_cast<float>(vars.DamageHackValue.value());
			//	skillIdentity->fields.SkillMinRange = static_cast<float>(vars.DamageHackValue.value());
			//	targetHitData->fields._reaction = app::eReactionType__Enum::Float;
			//	targetHitData->fields.PreventSkillCancel = true;
			//	targetHitData->fields.damageRatio = static_cast<float>(vars.DamageHackValue.value());
			//	targetHitData->fields.damageRatioTotalValue = static_cast<float>(vars.DamageHackValue.value());
			//}
		}

		if (skillIdentity->fields.entity->fields.FHNGHHPLPGD == app::eCharGroup__Enum::ENEMY || 
			skillIdentity->fields.entity->fields.AJEHLIOMMJN == app::ECharacterType__Enum::Monster)
		{
			if (vars.GodMode.value())
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
