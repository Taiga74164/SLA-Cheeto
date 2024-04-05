#pragma once

#include "Windows.h"
#include "events/event.hpp"

namespace events
{
	extern TEvent<> GameUpdateEvent;
	extern TCancelableEvent<short> KeyUpEvent;
	extern TCancelableEvent<HWND, UINT, WPARAM, LPARAM> WndProcEvent;
}