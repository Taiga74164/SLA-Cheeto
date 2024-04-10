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
	}

	void Debug::OnGameUpdate()
	{
	}

}
