#include "PlayerSpeed.h"
#include "HookManager.h"
#include "Utils.h"

namespace Cheat::Features
{
	void* PlayerSpeed::ENNEJEPMJLJ_GNAPBJPBKIO_Hook(app::ENNEJEPMJLJ* __this, MethodInfo* method)
	{
		__this->fields.PEFKKKBMDKN->fields.m_WalkSpeed = 100000;
		__this->fields.PEFKKKBMDKN->fields.m_MoveSpd = 100000;

		return CALL_ORIGIN(ENNEJEPMJLJ_GNAPBJPBKIO_Hook, __this, method);
	}

	PlayerSpeed::PlayerSpeed()
	{
		// HookManager::install(app::ENNEJEPMJLJ_GNAPBJPBKIO, ENNEJEPMJLJ_GNAPBJPBKIO_Hook);
	}

	void PlayerSpeed::Update()
	{
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			auto manager = GET_SINGLETON(PJKMAOEINNH);
			if (manager == nullptr)
			{
				LOG("manager is null!");
				return;
			}

			auto someList = TO_UNI_LIST(manager->fields.IHKJAIGPJGK, app::ENNEJEPMJLJ*);
			if (someList == nullptr)
			{
				LOG("someList is null!");
				return;
			}

			for (auto& entity : *someList)
			{
				if (entity == nullptr)
				{
					LOG("entity is null!");
					continue;
				}
			}

			//auto list = TO_UNI_LIST(app::PJKMAOEINNH_BGEJLBHLGJP(manager, nullptr), app::ENNEJEPMJLJ*);
			//if (list == nullptr)
			//{
			//	LOG("list is null!");
			//	return;
			//}

			//for (auto& entity : *list)
			//{
			//	if (entity == nullptr)
			//	{
			//		LOG("entity is null!");
			//		continue;
			//	}


			//	auto player = entity->fields.KFIFBINFDPB;
			//	if (player == nullptr)
			//	{
			//		LOG("player is null!");
			//		continue;
			//	}

			//	LOG("player: %s", il2cppi_to_string(player->fields.m_CharacterNameStringID));

			//	//player->fields.m_WalkSpeed = 100000;
			//	//player->fields.m_MoveSpd = 100000;
			//}
		}
	}
}
