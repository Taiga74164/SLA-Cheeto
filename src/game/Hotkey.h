#pragma once

#include <string>
#include <unordered_set>

#include "events/event.hpp"

// Slightly modified version of Callow's Hotkey class
class Hotkey 
{
public:

    Hotkey();
    Hotkey(const Hotkey& other);
    Hotkey(short key);
    Hotkey(std::vector<short> keys);
    ~Hotkey();

	Hotkey& operator=(Hotkey& hotkey) noexcept;
	Hotkey& operator=(Hotkey&& hotkey) noexcept;
	Hotkey& operator=(const Hotkey& hotkey) noexcept;

	bool operator== (const Hotkey& c2) const;
	bool operator!= (const Hotkey& c2) const;
	bool operator-(const Hotkey& c2);

    bool IsPressed() const;
    bool IsPressed(short keyDown) const;
    bool IsReleased() const;

    bool IsEmpty() const;

    std::vector<short> GetKeys() const;
	void SetKey(short key);
	std::string ToString() const;
	Hotkey FromString(const std::string& str);

	void ListenForNextKeyPress(Hotkey* targetHotkey);
	void StopListening();
	bool IsListening() const;
	std::string GetKeyString() const;

    operator std::string() const;


    static Hotkey GetPressedHotkey();

    IEvent<>& PressedEvent;
private:
    TEvent<> m_PressedEvent;
    std::unordered_set<short> m_Keys;

	bool m_IsListeningForHotkey = false;
	Hotkey* m_CurrentListeningHotkey = nullptr;

    void OnKeyUp(short key, bool& canceled);
};

namespace std
{
	template<>
	struct hash<Hotkey>
	{
		std::size_t operator()(const Hotkey& k) const noexcept
		{
			std::size_t hashValue = 0;
			for (auto key : k.GetKeys())
			{
				hashValue ^= std::hash<short>{}(key)+0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
			}
			return hashValue;
		}
	};
}