#pragma once
#include "Singleton.h"
#include <imgui.h>

class Gui : public Singleton<Gui>
{
public:
	void Render();
	void SetFont(ImFont* font) { m_DefaultFont = font; }
	void Toggle() { m_IsOpen = !m_IsOpen; }
	[[nodiscard]] bool IsOpen() const { return m_IsOpen; }

private:
	int m_MenuTab = 0;
	ImFont* m_DefaultFont = nullptr;
	bool m_IsOpen = true;
};