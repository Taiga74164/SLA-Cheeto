#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class TimeScale : public Module
	{
	public:
		TimeScale() = default;

		void Load() override {}
		void Update() override;
	};
}
