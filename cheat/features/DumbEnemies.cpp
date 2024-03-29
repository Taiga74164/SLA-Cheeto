#include "DumbEnemies.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{
	void DumbEnemies::Char3DIdentity_Init_Hook(app::Char3DIdentity* __this, app::ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method)
	{
		CALL_ORIGIN(Char3DIdentity_Init_Hook, __this, IGBKKNODEGM, method);

		if (__this != nullptr && IGBKKNODEGM != nullptr && IGBKKNODEGM->fields.KFIFBINFDPB != nullptr)
		{
			if (IGBKKNODEGM->fields.FHNGHHPLPGD == app::eCharGroup__Enum::PLAYER)
			{
				// if (Config.MovementSpeed)
				if (GetAsyncKeyState(VK_F1) & 1)
				{
					LOG("BALLS");
					IGBKKNODEGM->fields.PEFKKKBMDKN->fields.m_WalkSpeed *= 100000;
					IGBKKNODEGM->fields.PEFKKKBMDKN->fields.m_MoveSpd *= 100000;
				}
			}
		}
	}

	DumbEnemies::DumbEnemies()
	{
		// HookManager::install(app::Char3DIdentity_Init, Char3DIdentity_Init_Hook);
	}

	void DumbEnemies::Update()
	{
		//if (GetAsyncKeyState(VK_F1) & 1)
		//{
		//	LOG("BALLS");

		//	auto char3dType = GetUnityType("NGame.Char3DIdentity");
		//	auto objs = app::Object_1_FindObjectsOfType_1(char3dType, true, nullptr);
		//	if (objs == nullptr)
		//	{
		//		LOG("objs is null");
		//		return;
		//	}

		//	for (auto& obj : *TO_UNI_ARRAY(objs, app::Object_1*))
		//	{
		//		auto char3dIdentity = reinterpret_cast<app::Char3DIdentity*>(obj);
		//		if (char3dIdentity == nullptr)
		//		{
		//			LOG("char3dIdentity is null");
		//			continue;
		//		}

		//		auto entity = char3dIdentity->fields.EJBODHBGPMG;
		//		if (entity == nullptr)
		//		{
		//			LOG("Entity is null");
		//			continue;
		//		}

		//		if (entity->fields.FHNGHHPLPGD != app::eCharGroup__Enum::PLAYER)
		//		{
		//			LOG("Entity is not a player");
		//			continue;
		//		}

		//		entity->fields.PEFKKKBMDKN->fields.m_WalkSpeed = 100000;
		//		entity->fields.PEFKKKBMDKN->fields.m_MoveSpd = 100000;
		//	}
		//}
	}
}
