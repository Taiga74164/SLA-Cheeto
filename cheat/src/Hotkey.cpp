#include "global.h"
#include "Hotkey.h"
#include "imgui.h"
#include "events.h"

#define IM_VK_KEYPAD_ENTER      (VK_RETURN + 256)

// Slightly modified version. All credits to Callow
static ImGuiKey LegacyToInput(short key)
{
	switch (key)
	{
	case VK_TAB: return ImGuiKey_Tab;
	case VK_LEFT: return ImGuiKey_LeftArrow;
	case VK_RIGHT: return ImGuiKey_RightArrow;
	case VK_UP: return ImGuiKey_UpArrow;
	case VK_DOWN: return ImGuiKey_DownArrow;
	case VK_PRIOR: return ImGuiKey_PageUp;
	case VK_NEXT: return ImGuiKey_PageDown;
	case VK_HOME: return ImGuiKey_Home;
	case VK_END: return ImGuiKey_End;
	case VK_INSERT: return ImGuiKey_Insert;
	case VK_DELETE: return ImGuiKey_Delete;
	case VK_BACK: return ImGuiKey_Backspace;
	case VK_SPACE: return ImGuiKey_Space;
	case VK_RETURN: return ImGuiKey_Enter;
	case VK_ESCAPE: return ImGuiKey_Escape;
	case VK_OEM_7: return ImGuiKey_Apostrophe;
	case VK_OEM_COMMA: return ImGuiKey_Comma;
	case VK_OEM_MINUS: return ImGuiKey_Minus;
	case VK_OEM_PERIOD: return ImGuiKey_Period;
	case VK_OEM_2: return ImGuiKey_Slash;
	case VK_OEM_1: return ImGuiKey_Semicolon;
	case VK_OEM_PLUS: return ImGuiKey_Equal;
	case VK_OEM_4: return ImGuiKey_LeftBracket;
	case VK_OEM_5: return ImGuiKey_Backslash;
	case VK_OEM_6: return ImGuiKey_RightBracket;
	case VK_OEM_3: return ImGuiKey_GraveAccent;
	case VK_CAPITAL: return ImGuiKey_CapsLock;
	case VK_SCROLL: return ImGuiKey_ScrollLock;
	case VK_NUMLOCK: return ImGuiKey_NumLock;
	case VK_SNAPSHOT: return ImGuiKey_PrintScreen;
	case VK_PAUSE: return ImGuiKey_Pause;
	case VK_NUMPAD0: return ImGuiKey_Keypad0;
	case VK_NUMPAD1: return ImGuiKey_Keypad1;
	case VK_NUMPAD2: return ImGuiKey_Keypad2;
	case VK_NUMPAD3: return ImGuiKey_Keypad3;
	case VK_NUMPAD4: return ImGuiKey_Keypad4;
	case VK_NUMPAD5: return ImGuiKey_Keypad5;
	case VK_NUMPAD6: return ImGuiKey_Keypad6;
	case VK_NUMPAD7: return ImGuiKey_Keypad7;
	case VK_NUMPAD8: return ImGuiKey_Keypad8;
	case VK_NUMPAD9: return ImGuiKey_Keypad9;
	case VK_DECIMAL: return ImGuiKey_KeypadDecimal;
	case VK_DIVIDE: return ImGuiKey_KeypadDivide;
	case VK_MULTIPLY: return ImGuiKey_KeypadMultiply;
	case VK_SUBTRACT: return ImGuiKey_KeypadSubtract;
	case VK_ADD: return ImGuiKey_KeypadAdd;
	case IM_VK_KEYPAD_ENTER: return ImGuiKey_KeypadEnter;
	case VK_LSHIFT: return ImGuiKey_LeftShift;
	case VK_LCONTROL: return ImGuiKey_LeftCtrl;
	case VK_LMENU: return ImGuiKey_LeftAlt;
	case VK_LWIN: return ImGuiKey_LeftSuper;
	case VK_RSHIFT: return ImGuiKey_RightShift;
	case VK_RCONTROL: return ImGuiKey_RightCtrl;
	case VK_RMENU: return ImGuiKey_RightAlt;
	case VK_RWIN: return ImGuiKey_RightSuper;
	case VK_APPS: return ImGuiKey_Menu;
	case '0': return ImGuiKey_0;
	case '1': return ImGuiKey_1;
	case '2': return ImGuiKey_2;
	case '3': return ImGuiKey_3;
	case '4': return ImGuiKey_4;
	case '5': return ImGuiKey_5;
	case '6': return ImGuiKey_6;
	case '7': return ImGuiKey_7;
	case '8': return ImGuiKey_8;
	case '9': return ImGuiKey_9;
	case 'A': return ImGuiKey_A;
	case 'B': return ImGuiKey_B;
	case 'C': return ImGuiKey_C;
	case 'D': return ImGuiKey_D;
	case 'E': return ImGuiKey_E;
	case 'F': return ImGuiKey_F;
	case 'G': return ImGuiKey_G;
	case 'H': return ImGuiKey_H;
	case 'I': return ImGuiKey_I;
	case 'J': return ImGuiKey_J;
	case 'K': return ImGuiKey_K;
	case 'L': return ImGuiKey_L;
	case 'M': return ImGuiKey_M;
	case 'N': return ImGuiKey_N;
	case 'O': return ImGuiKey_O;
	case 'P': return ImGuiKey_P;
	case 'Q': return ImGuiKey_Q;
	case 'R': return ImGuiKey_R;
	case 'S': return ImGuiKey_S;
	case 'T': return ImGuiKey_T;
	case 'U': return ImGuiKey_U;
	case 'V': return ImGuiKey_V;
	case 'W': return ImGuiKey_W;
	case 'X': return ImGuiKey_X;
	case 'Y': return ImGuiKey_Y;
	case 'Z': return ImGuiKey_Z;
	case VK_F1: return ImGuiKey_F1;
	case VK_F2: return ImGuiKey_F2;
	case VK_F3: return ImGuiKey_F3;
	case VK_F4: return ImGuiKey_F4;
	case VK_F5: return ImGuiKey_F5;
	case VK_F6: return ImGuiKey_F6;
	case VK_F7: return ImGuiKey_F7;
	case VK_F8: return ImGuiKey_F8;
	case VK_F9: return ImGuiKey_F9;
	case VK_F10: return ImGuiKey_F10;
	case VK_F11: return ImGuiKey_F11;
	case VK_F12: return ImGuiKey_F12;
	case VK_LBUTTON: return ImGuiMouseButton_Left;
	case VK_RBUTTON: return ImGuiMouseButton_Right;
	case VK_MBUTTON: return ImGuiMouseButton_Middle;
	case VK_XBUTTON1: return 3;
	case VK_XBUTTON2: return 4;
	default: return ImGuiKey_None;
	}
}

static short ImGuiKeyToLegacy(ImGuiKey inputKey)
{
	switch (inputKey)
	{
	case ImGuiKey_Tab: return VK_TAB;
	case ImGuiKey_LeftArrow: return VK_LEFT;
	case ImGuiKey_RightArrow: return VK_RIGHT;
	case ImGuiKey_UpArrow: return VK_UP;
	case ImGuiKey_DownArrow: return VK_DOWN;
	case ImGuiKey_PageUp: return VK_PRIOR;
	case ImGuiKey_PageDown: return VK_NEXT;
	case ImGuiKey_Home: return VK_HOME;
	case ImGuiKey_End: return VK_END;
	case ImGuiKey_Insert: return VK_INSERT;
	case ImGuiKey_Delete: return VK_DELETE;
	case ImGuiKey_Backspace: return VK_BACK;
	case ImGuiKey_Space: return VK_SPACE;
	case ImGuiKey_Enter: return VK_RETURN;
	case ImGuiKey_Escape: return VK_ESCAPE;
	case ImGuiKey_Apostrophe: return VK_OEM_7;
	case ImGuiKey_Comma: return VK_OEM_COMMA;
	case ImGuiKey_Minus: return VK_OEM_MINUS;
	case ImGuiKey_Period: return VK_OEM_PERIOD;
	case ImGuiKey_Slash: return VK_OEM_2;
	case ImGuiKey_Semicolon: return VK_OEM_1;
	case ImGuiKey_Equal: return VK_OEM_PLUS;
	case ImGuiKey_LeftBracket: return VK_OEM_4;
	case ImGuiKey_Backslash: return VK_OEM_5;
	case ImGuiKey_RightBracket: return VK_OEM_6;
	case ImGuiKey_GraveAccent: return VK_OEM_3;
	case ImGuiKey_CapsLock: return VK_CAPITAL;
	case ImGuiKey_ScrollLock: return VK_SCROLL;
	case ImGuiKey_NumLock: return VK_NUMLOCK;
	case ImGuiKey_PrintScreen: return VK_SNAPSHOT;
	case ImGuiKey_Pause: return VK_PAUSE;
	case ImGuiKey_Keypad0: return VK_NUMPAD0;
	case ImGuiKey_Keypad1: return VK_NUMPAD1;
	case ImGuiKey_Keypad2: return VK_NUMPAD2;
	case ImGuiKey_Keypad3: return VK_NUMPAD3;
	case ImGuiKey_Keypad4: return VK_NUMPAD4;
	case ImGuiKey_Keypad5: return VK_NUMPAD5;
	case ImGuiKey_Keypad6: return VK_NUMPAD6;
	case ImGuiKey_Keypad7: return VK_NUMPAD7;
	case ImGuiKey_Keypad8: return VK_NUMPAD8;
	case ImGuiKey_Keypad9: return VK_NUMPAD9;
	case ImGuiKey_KeypadDecimal: return VK_DECIMAL;
	case ImGuiKey_KeypadDivide: return VK_DIVIDE;
	case ImGuiKey_KeypadMultiply: return VK_MULTIPLY;
	case ImGuiKey_KeypadSubtract: return VK_SUBTRACT;
	case ImGuiKey_KeypadAdd: return VK_ADD;
	case ImGuiKey_KeypadEnter: return IM_VK_KEYPAD_ENTER;
	case ImGuiKey_LeftShift: return VK_LSHIFT;
	case ImGuiKey_LeftCtrl: return VK_LCONTROL;
	case ImGuiKey_LeftAlt: return VK_LMENU;
	case ImGuiKey_LeftSuper: return VK_LWIN;
	case ImGuiKey_RightShift: return VK_RSHIFT;
	case ImGuiKey_RightCtrl: return VK_RCONTROL;
	case ImGuiKey_RightAlt: return VK_RMENU;
	case ImGuiKey_RightSuper: return VK_RWIN;
	case ImGuiKey_Menu: return VK_APPS;
	case ImGuiKey_0: return '0';
	case ImGuiKey_1: return '1';
	case ImGuiKey_2: return '2';
	case ImGuiKey_3: return '3';
	case ImGuiKey_4: return '4';
	case ImGuiKey_5: return '5';
	case ImGuiKey_6: return '6';
	case ImGuiKey_7: return '7';
	case ImGuiKey_8: return '8';
	case ImGuiKey_9: return '9';
	case ImGuiKey_A: return 'A';
	case ImGuiKey_B: return 'B';
	case ImGuiKey_C: return 'C';
	case ImGuiKey_D: return 'D';
	case ImGuiKey_E: return 'E';
	case ImGuiKey_F: return 'F';
	case ImGuiKey_G: return 'G';
	case ImGuiKey_H: return 'H';
	case ImGuiKey_I: return 'I';
	case ImGuiKey_J: return 'J';
	case ImGuiKey_K: return 'K';
	case ImGuiKey_L: return 'L';
	case ImGuiKey_M: return 'M';
	case ImGuiKey_N: return 'N';
	case ImGuiKey_O: return 'O';
	case ImGuiKey_P: return 'P';
	case ImGuiKey_Q: return 'Q';
	case ImGuiKey_R: return 'R';
	case ImGuiKey_S: return 'S';
	case ImGuiKey_T: return 'T';
	case ImGuiKey_U: return 'U';
	case ImGuiKey_V: return 'V';
	case ImGuiKey_W: return 'W';
	case ImGuiKey_X: return 'X';
	case ImGuiKey_Y: return 'Y';
	case ImGuiKey_Z: return 'Z';
	case ImGuiKey_F1: return VK_F1;
	case ImGuiKey_F2: return VK_F2;
	case ImGuiKey_F3: return VK_F3;
	case ImGuiKey_F4: return VK_F4;
	case ImGuiKey_F5: return VK_F5;
	case ImGuiKey_F6: return VK_F6;
	case ImGuiKey_F7: return VK_F7;
	case ImGuiKey_F8: return VK_F8;
	case ImGuiKey_F9: return VK_F9;
	case ImGuiKey_F10: return VK_F10;
	case ImGuiKey_F11: return VK_F11;
	case ImGuiKey_F12: return VK_F12;
	case ImGuiMouseButton_Left: return VK_LBUTTON;
	case ImGuiMouseButton_Right: return VK_RBUTTON;
	case ImGuiMouseButton_Middle: return VK_MBUTTON;
	default: return 0;
	}
}

static short InputToLegacy(ImGuiKey inputkey)
{
	auto& io = ImGui::GetIO();
	if (inputkey > 4)
		return io.KeyMap[inputkey];

	switch (inputkey)
	{
	case ImGuiMouseButton_Left:
		return VK_LBUTTON;
	case ImGuiMouseButton_Right:
		return VK_RBUTTON;
	case ImGuiMouseButton_Middle:
		return VK_MBUTTON;
	case 3:
		return VK_XBUTTON1;
	case 4:
		return VK_XBUTTON2;
	}

	LOG(xorstr("Failed to find legacy input"));
	return -1;
}

static bool IsKeyDown(ImGuiKey key)
{
	if (key > 6)
		return ImGui::IsKeyDown(key);
	
	switch (key)
	{
	case 1:
	case 2:
		return ImGui::IsMouseDown(key - 1);
	case 4:
	case 5:
	case 6:
		return ImGui::IsMouseDown(key - 2);
	}
	return false;
}

static bool IsKeyReleased(ImGuiKey key)
{
	if (key > 6)
		return ImGui::IsKeyReleased(key);

	switch (key)
	{
	case 1:
	case 2:
		return ImGui::IsMouseReleased(key - 1);
	case 4:
	case 5:
	case 6:
		return ImGui::IsMouseReleased(key - 2);
	}
	return false;
}

void FixModKey(short& legacyKey)
{
	// Can cause incorrect input when both keys pressed, need to fix!
	switch (legacyKey)
	{

	case VK_CONTROL:
	{
		if (IsKeyDown(ImGuiKey_LeftCtrl))
			legacyKey = VK_LCONTROL;
		else if (IsKeyDown(ImGuiKey_RightCtrl))
			legacyKey = VK_RCONTROL;

		return;
	}
	case VK_SHIFT:
	{
		if (IsKeyDown(ImGuiKey_LeftShift))
			legacyKey = VK_LSHIFT;
		else if (IsKeyDown(ImGuiKey_RightShift))
			legacyKey = VK_RSHIFT;

		return;
	}

	}
}

Hotkey::Hotkey() : PressedEvent(m_PressedEvent), m_PressedEvent()
{
	events::KeyUpEvent += MY_METHOD_HANDLER(Hotkey::OnKeyUp);
	//events::GlobalKeyUpEvent += MY_METHOD_HANDLER(Hotkey::OnGlobalKeyUp);
}

Hotkey::Hotkey(std::vector<short> legacyKeys) : Hotkey()
{
    for (short legacyKey : legacyKeys)
    {
        this->m_Keys.insert(legacyKey);
    }
}

Hotkey::Hotkey(short key) : Hotkey()
{
    this->m_Keys.insert(key);
}

Hotkey::Hotkey(const Hotkey& other) : Hotkey()
{
	m_Keys = {other.m_Keys};
}

Hotkey::~Hotkey()
{
	events::KeyUpEvent -= MY_METHOD_HANDLER(Hotkey::OnKeyUp);
}

Hotkey& Hotkey::operator=(Hotkey&& hotkey) noexcept
{
	m_Keys = std::move(hotkey.m_Keys);
	return *this;
}

Hotkey& Hotkey::operator=(const Hotkey& hotkey) noexcept
{
	if (this == &hotkey) return *this;
	m_Keys = hotkey.m_Keys;
	return *this;
}

Hotkey& Hotkey::operator=(Hotkey& hotkey) noexcept
{
	m_Keys = hotkey.m_Keys;
	return *this;
}

bool Hotkey::operator-(const Hotkey& c2)
{
	for (short key : m_Keys)
	{
		if (c2.m_Keys.count(key) == 0)
			return true;
	}
	return false;
}

bool Hotkey::operator!=(const Hotkey& c2) const
{
	return !(*this == c2);
}

bool Hotkey::operator==(const Hotkey& c2) const
{
	return m_Keys == c2.m_Keys;
}

std::string GetKeyName(short key)
{
    if (key > 5)
		return ImGui::GetKeyName(key);
    
    switch (key)
    {
    case ImGuiMouseButton_Left:
        return "LMB";
    case ImGuiMouseButton_Right:
        return "RMB";
    case ImGuiMouseButton_Middle:
        return "MMB";
    case 3:
        return "Mouse X1";
    case 4:
        return "Mouse X2";
    }

    return "Unknown";
}

Hotkey::operator std::string() const 
{
    if (IsEmpty())
        return "None";

    std::stringstream hotkeyNameStream;

    for (auto it = m_Keys.begin(); it != m_Keys.end(); it++)
    {
        if (it != m_Keys.begin())
            hotkeyNameStream << " + ";

        hotkeyNameStream << GetKeyName(LegacyToInput(*it));
    }
    return hotkeyNameStream.str();
}

bool Hotkey::IsPressed() const
{
	for (short key : m_Keys)
	{
		if (!IsKeyDown(key))
			return false;
	}

	return true;
}

bool Hotkey::IsPressed(short legacyKey) const
{
	FixModKey(legacyKey);

    if (m_Keys.count(legacyKey) == 0)
        return false;

    std::unordered_set<short> keysClone = m_Keys;
    keysClone.erase(legacyKey);

    for (short key : keysClone)
    {
		bool result = IsKeyDown(key);
        if (!result)
            return false;
    }

    return true;
}

bool Hotkey::IsReleased() const
{
	bool released = false;
	for (short key : m_Keys)
	{
		if (IsKeyReleased(key))
		{
			released = true;
			continue;
		}

		if (!IsKeyDown(key))
			return false;
	}

	return released;
}

bool Hotkey::IsEmpty() const
{
    return m_Keys.size() == 0;
}

std::vector<short> Hotkey::GetKeys() const
{
    return std::vector(m_Keys.begin(), m_Keys.end());
}

void Hotkey::SetKey(short key)
{
	m_Keys.clear();
	m_Keys.insert(key);
}

std::string Hotkey::ToString() const
{
	if (m_Keys.empty()) return "None";

	std::stringstream hotkeyNameStream;
	for (auto it = m_Keys.begin(); it != m_Keys.end(); ++it)
	{
		if (it != m_Keys.begin())
			hotkeyNameStream << " + ";
		hotkeyNameStream << GetKeyName(LegacyToInput(*it));
	}
	return hotkeyNameStream.str();
}

std::string Trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

// Temporary. IDK why magic_enum::enum_cast is returning 0
ImGuiKey StringToImGuiKey_1(const std::string& keyName)
{
	static std::unordered_map<std::string, ImGuiKey> keyMap =
	{
		{ "ImGuiKey_Tab", ImGuiKey_Tab },
		{ "ImGuiKey_LeftArrow", ImGuiKey_LeftArrow },
		{ "ImGuiKey_RightArrow", ImGuiKey_RightArrow },
		{ "ImGuiKey_UpArrow", ImGuiKey_UpArrow },
		{ "ImGuiKey_DownArrow", ImGuiKey_DownArrow },
		{ "ImGuiKey_PageUp", ImGuiKey_PageUp },
		{ "ImGuiKey_PageDown", ImGuiKey_PageDown },
		{ "ImGuiKey_Home", ImGuiKey_Home },
		{ "ImGuiKey_End", ImGuiKey_End },
		{ "ImGuiKey_Insert", ImGuiKey_Insert },
		{ "ImGuiKey_Delete", ImGuiKey_Delete },
		{ "ImGuiKey_Backspace", ImGuiKey_Backspace },
		{ "ImGuiKey_Space", ImGuiKey_Space },
		{ "ImGuiKey_Enter", ImGuiKey_Enter },
		{ "ImGuiKey_Escape", ImGuiKey_Escape },
		{ "ImGuiKey_Apostrophe", ImGuiKey_Apostrophe },
		{ "ImGuiKey_Comma", ImGuiKey_Comma },
		{ "ImGuiKey_Minus", ImGuiKey_Minus },
		{ "ImGuiKey_Period", ImGuiKey_Period },
		{ "ImGuiKey_Slash", ImGuiKey_Slash },
		{ "ImGuiKey_Semicolon", ImGuiKey_Semicolon },
		{ "ImGuiKey_Equal", ImGuiKey_Equal },
		{ "ImGuiKey_LeftBracket", ImGuiKey_LeftBracket },
		{ "ImGuiKey_Backslash", ImGuiKey_Backslash },
		{ "ImGuiKey_RightBracket", ImGuiKey_RightBracket },
		{ "ImGuiKey_GraveAccent", ImGuiKey_GraveAccent },
		{ "ImGuiKey_CapsLock", ImGuiKey_CapsLock },
		{ "ImGuiKey_ScrollLock", ImGuiKey_ScrollLock },
		{ "ImGuiKey_NumLock", ImGuiKey_NumLock },
		{ "ImGuiKey_PrintScreen", ImGuiKey_PrintScreen },
		{ "ImGuiKey_Pause", ImGuiKey_Pause },
		{ "ImGuiKey_Keypad0", ImGuiKey_Keypad0 },
		{ "ImGuiKey_Keypad1", ImGuiKey_Keypad1 },
		{ "ImGuiKey_Keypad2", ImGuiKey_Keypad2 },
		{ "ImGuiKey_Keypad3", ImGuiKey_Keypad3 },
		{ "ImGuiKey_Keypad4", ImGuiKey_Keypad4 },
		{ "ImGuiKey_Keypad5", ImGuiKey_Keypad5 },
		{ "ImGuiKey_Keypad6", ImGuiKey_Keypad6 },
		{ "ImGuiKey_Keypad7", ImGuiKey_Keypad7 },
		{ "ImGuiKey_Keypad8", ImGuiKey_Keypad8 },
		{ "ImGuiKey_Keypad9", ImGuiKey_Keypad9 },
		{ "ImGuiKey_KeypadDecimal", ImGuiKey_KeypadDecimal },
		{ "ImGuiKey_KeypadDivide", ImGuiKey_KeypadDivide },
		{ "ImGuiKey_KeypadMultiply", ImGuiKey_KeypadMultiply },
		{ "ImGuiKey_KeypadSubtract", ImGuiKey_KeypadSubtract },
		{ "ImGuiKey_KeypadAdd", ImGuiKey_KeypadAdd },
		{ "ImGuiKey_KeypadEnter", ImGuiKey_KeypadEnter },
		{ "ImGuiKey_LeftShift", ImGuiKey_LeftShift },
		{ "ImGuiKey_LeftCtrl", ImGuiKey_LeftCtrl },
		{ "ImGuiKey_LeftAlt", ImGuiKey_LeftAlt },
		{ "ImGuiKey_LeftSuper", ImGuiKey_LeftSuper },
		{ "ImGuiKey_RightShift", ImGuiKey_RightShift },
		{ "ImGuiKey_RightCtrl", ImGuiKey_RightCtrl },
		{ "ImGuiKey_RightAlt", ImGuiKey_RightAlt },
		{ "ImGuiKey_RightSuper", ImGuiKey_RightSuper },
		{ "ImGuiKey_Menu", ImGuiKey_Menu },
		{ "ImGuiKey_0", ImGuiKey_0 },
		{ "ImGuiKey_1", ImGuiKey_1 },
		{ "ImGuiKey_2", ImGuiKey_2 },
		{ "ImGuiKey_3", ImGuiKey_3 },
		{ "ImGuiKey_4", ImGuiKey_4 },
		{ "ImGuiKey_5", ImGuiKey_5 },
		{ "ImGuiKey_6", ImGuiKey_6 },
		{ "ImGuiKey_7", ImGuiKey_7 },
		{ "ImGuiKey_8", ImGuiKey_8 },
		{ "ImGuiKey_9", ImGuiKey_9 },
		{ "ImGuiKey_A", ImGuiKey_A },
		{ "ImGuiKey_B", ImGuiKey_B },
		{ "ImGuiKey_C", ImGuiKey_C },
		{ "ImGuiKey_D", ImGuiKey_D },
		{ "ImGuiKey_E", ImGuiKey_E },
		{ "ImGuiKey_F", ImGuiKey_F },
		{ "ImGuiKey_G", ImGuiKey_G },
		{ "ImGuiKey_H", ImGuiKey_H },
		{ "ImGuiKey_I", ImGuiKey_I },
		{ "ImGuiKey_J", ImGuiKey_J },
		{ "ImGuiKey_K", ImGuiKey_K },
		{ "ImGuiKey_L", ImGuiKey_L },
		{ "ImGuiKey_M", ImGuiKey_M },
		{ "ImGuiKey_N", ImGuiKey_N },
		{ "ImGuiKey_O", ImGuiKey_O },
		{ "ImGuiKey_P", ImGuiKey_P },
		{ "ImGuiKey_Q", ImGuiKey_Q },
		{ "ImGuiKey_R", ImGuiKey_R },
		{ "ImGuiKey_S", ImGuiKey_S },
		{ "ImGuiKey_T", ImGuiKey_T },
		{ "ImGuiKey_U", ImGuiKey_U },
		{ "ImGuiKey_V", ImGuiKey_V },
		{ "ImGuiKey_W", ImGuiKey_W },
		{ "ImGuiKey_X", ImGuiKey_X },
		{ "ImGuiKey_Y", ImGuiKey_Y },
		{ "ImGuiKey_Z", ImGuiKey_Z },
		{ "ImGuiKey_F1", ImGuiKey_F1 },
		{ "ImGuiKey_F2", ImGuiKey_F2 },
		{ "ImGuiKey_F3", ImGuiKey_F3 },
		{ "ImGuiKey_F4", ImGuiKey_F4 },
		{ "ImGuiKey_F5", ImGuiKey_F5 },
		{ "ImGuiKey_F6", ImGuiKey_F6 },
		{ "ImGuiKey_F7", ImGuiKey_F7 },
		{ "ImGuiKey_F8", ImGuiKey_F8 },
		{ "ImGuiKey_F9", ImGuiKey_F9 },
		{ "ImGuiKey_F10", ImGuiKey_F10 },
		{ "ImGuiKey_F11", ImGuiKey_F11 },
		{ "ImGuiKey_F12", ImGuiKey_F12 },
		{ "ImGuiMouseButton_Left", ImGuiMouseButton_Left },
		{ "ImGuiMouseButton_Right", ImGuiMouseButton_Right },
		{ "ImGuiMouseButton_Middle", ImGuiMouseButton_Middle },
	};

	auto it = keyMap.find(keyName);
	if (it != keyMap.end())
		return it->second;

	return ImGuiKey_None;
}

ImGuiKey StringToImGuiKey(const std::string& keyName)
{
	LOG(xorstr("StringToImGuiKey: %s"), keyName.c_str());
	auto keyEnum = magic_enum::enum_cast<ImGuiKey_>(keyName);
	auto ret = keyEnum.has_value() ? keyEnum.value() : ImGuiKey_None;
	LOG(xorstr("StringToImGuiKey ret: %s"), magic_enum::enum_name(ret).data());
	return ret;
}

Hotkey Hotkey::FromString(const std::string& hotkeyString)
{
	//LOG(xorstr("Hotkey::FromString: %s"), hotkeyString.c_str());
	if (hotkeyString == "None")
		return Hotkey();

	Hotkey hotkey;
	std::istringstream stream(hotkeyString);
	std::string keyName;

	while (std::getline(stream, keyName, '+'))
	{
		std::string trimmedKey = Trim(keyName);
		trimmedKey = (trimmedKey.find("ImGuiKey_") == std::string::npos) ? "ImGuiKey_" + trimmedKey : trimmedKey;
		ImGuiKey imguiKey = StringToImGuiKey_1(trimmedKey);
		short legacyKey = ImGuiKeyToLegacy(imguiKey);

		//LOG("Parsed key: %s, ImGuiKey: %d, LegacyKey: %d", trimmedKey.c_str(), imguiKey, legacyKey);

		if (legacyKey != -1)
			hotkey.m_Keys.insert(legacyKey);
	}

	//if (hotkey.IsEmpty())
	//	LOG("Hotkey parsed is empty.");
	//else
	//	LOG("Hotkey parsed successfully: %s", hotkey.ToString().c_str());

	return hotkey;
}

void Hotkey::ListenForNextKeyPress(Hotkey* targetHotkey)
{
	m_IsListeningForHotkey = true;
	m_CurrentListeningHotkey = targetHotkey;
}

void Hotkey::StopListening()
{
	m_IsListeningForHotkey = false;
	m_CurrentListeningHotkey = nullptr;
}

bool Hotkey::IsListening() const
{
	return m_IsListeningForHotkey;
}

std::string Hotkey::GetKeyString() const
{
	if (m_Keys.empty()) return "";
	return ToString();
}

Hotkey Hotkey::GetPressedHotkey()
{
    Hotkey hotkey{};

    auto& io = ImGui::GetIO();

    for (ImGuiKey i = ImGuiKey_NamedKey_BEGIN; i < ImGuiKey_NamedKey_END - 4; i++)
    {
        bool isKeyDown = io.KeysDown[i];
        if (isKeyDown)
            hotkey.m_Keys.insert(InputToLegacy(i));
    }

    for (ImGuiKey i = 0; i < ImGuiMouseButton_COUNT; i++)
    {
        bool isMouseButtonDown = io.MouseDown[i];
        if (isMouseButtonDown)
            hotkey.m_Keys.insert(InputToLegacy(i));
    }
    return hotkey;
}

void Hotkey::OnKeyUp(short key, bool& canceled)
{
	if (m_IsListeningForHotkey && m_CurrentListeningHotkey != nullptr)
	{
		m_CurrentListeningHotkey->SetKey(key);
		StopListening();
	}
}