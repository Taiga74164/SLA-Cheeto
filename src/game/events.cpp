#include "events.h"

namespace events
{
	TEvent<> GameUpdateEvent;
	TCancelableEvent<short> KeyUpEvent;
	TCancelableEvent<HWND, UINT, WPARAM, LPARAM> WndProcEvent{};
}