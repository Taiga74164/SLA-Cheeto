#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class TimeScale : public Singleton<TimeScale>
	{
	public:
		TimeScale();

		void OnGameUpdate();
		
	private:
		bool m_DidSpeed;
	};
}
