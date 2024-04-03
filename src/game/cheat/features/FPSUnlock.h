#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
    class FPSUnlock : public Singleton<FPSUnlock>
    {
    public:
		FPSUnlock();

		void OnGameUpdate();

    private:
		bool m_LastEnableStatus = false;
		int m_OriginFPS = 60;
    };
}
