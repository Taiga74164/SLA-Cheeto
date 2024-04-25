#pragma once
//#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS
#define IMGUI_DEFINE_MATH_OPERATORS
//#define IMGUI_DEFINE_PLACEMENT_NEW
#include <Windows.h>
#include <algorithm>
#include <functional>
#include <deque>
#include <string>
#include <vector>
#include "color.hpp"
#include "ConfigEntry.hpp"
#include "Hotkey.h"
#include "HotkeyManager.hpp"

#pragma warning(disable: 26812 26815)

#define MAX_RGB 255.0
#define HELPMAKER(str) ImGui::SameLine(); ImGui::TextColored(ImColor(220, 10, 10, 255), "[?]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str);
// #define HOTKEYMAKER(key) ImGui::SameLine(); ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(100, 10, 220, 255)); ImGui::Hotkey("", key); ImGui::PopStyleColor() 
// ImGui::PushAllowKeyboardFocus(false); ImGui::PopAllowKeyboardFocus()

static ImVec4 active = ImVec4(0.40f, 0.04f, 0.04f, 1.00f);
static ImVec4 inactive = ImVec4(0.06f, 0.06f, 0.06f, 0.90f);
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

namespace ImGui
{
	bool HotkeyWidget(const char* label, Hotkey& hotkey, const ImVec2& size);
	// Slightly modified version function. All credits to Callow
	template<typename T>
	bool InputHotkey(const char* label, ConfigEntry<T>& configEntry, bool clearable = true)
	{
		Hotkey& hotkeyRef = configEntry.hotkey();
		bool& toggleVar = configEntry.value();

		char hotkeyBuffer[50];
		auto hotkeyString = std::string(hotkeyRef);
		memcpy(hotkeyBuffer, hotkeyString.c_str(), hotkeyString.size() + 1);

		bool changed = false;

		if (clearable)
		{
			char labelBuffer[128];
			std::snprintf(labelBuffer, sizeof(labelBuffer), "%s ## %s_1", "Clear", label);

			if (ImGui::Button(labelBuffer, ImVec2(75, 0)))
			{
				hotkeyRef = Hotkey();
				changed = true;
			}
			ImGui::SameLine();
		}

		changed = ImGui::HotkeyWidget(label, hotkeyRef, ImVec2(200, 0)) || changed;

		if (changed)
		{
			HotkeyManager::GetInstance().RegisterKey(hotkeyRef, &toggleVar);
			configEntry.SetHotkey(hotkeyRef);
		}

		return changed;
	}
	
	void TextURL(const char* label, const char* url);
	bool CheckboxFill(const char* label, bool* v);
    // Combo box helper allowing to pass an array of strings.
    bool Combo(const char* label, int* currIndex, std::vector<std::string>& values);
    bool BeginGroupBox(const char* name, const ImVec2& size_arg = ImVec2(0, 0));
    void EndGroupBox();
    bool ListBox(const char* label, int* current_item, std::string items[], int items_count, int height_items);
    bool ListBox(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items);
    bool Combo(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items);
    void Separator(const char* label);
    void RainbowSeparator(const char* label);
}

namespace GuiUtil
{
    float GetX();
    float GetY();
    void RainbowRectFilled(int x, int y, int width, int height, float flSpeed, float& flRainbow);
    void RainbowLine();
    void Line(int newId);
    void LineVertical();
    void LineHorizontal();
    void CenterText(const char* text, int lineId, bool separator);
    void CenterTextEx(const char* text, float width, int lineId, bool separator);
    void DrawTextImGui(ImVec2 position, ImColor color, const char* format, ...);
    void DrawTextOutlined(const char* text);
    ImVec4 ToVec4(float r, float g, float b, float a);
}