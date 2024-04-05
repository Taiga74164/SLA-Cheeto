#pragma once
#include <unordered_map>

#include "Hotkey.h"
#include "Singleton.h"

class HotkeyManager : public Singleton<HotkeyManager>
{
public:
	void RegisterKey(const Hotkey& hotkey, bool* target)
	{
		// LMAOOOOOOOOOOO SCUFFED AF
		for (auto it = m_Hotkeys.begin(); it != m_Hotkeys.end(); )
		{
			if (it->second == target)
				it = m_Hotkeys.erase(it);
			else
				++it;
		}

		m_Hotkeys[hotkey] = target;
	}

	void CheckForKeyPress() const
	{
		for (const auto& [hotkey, target] : m_Hotkeys)
		{
			if (hotkey.IsReleased())
				*target = !(*target);
		}
	}

private:
	std::unordered_map<Hotkey, bool*> m_Hotkeys;
};
