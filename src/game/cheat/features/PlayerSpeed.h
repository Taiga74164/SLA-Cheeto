#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class PlayerSpeed : public Singleton<PlayerSpeed>
	{
	public:
		PlayerSpeed();

		void OnGameUpdate();

	private:
	};
}
