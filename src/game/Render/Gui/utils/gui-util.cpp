#include "gui-util.hpp"

#include "Utils.h"

//bool ImGui::InputHotkey(const char* label, Hotkey* hotkey, bool& toggleVar, bool clearable)
//{
//	char hotkeyBuffer[50];
//
//	auto hotkeyString = std::string(*hotkey);
//	memcpy(hotkeyBuffer, hotkeyString.c_str(), hotkeyString.size() + 1);
//
//	bool changed = false;
//
//	if (clearable)
//	{
//		char labelBuffer[128];
//		std::snprintf(labelBuffer, 128, "%s ## %s_1", "Clear", label);
//
//		if (ImGui::Button(labelBuffer, ImVec2(75, 0)))
//		{
//			*hotkey = Hotkey();
//			changed = true;
//		}
//		ImGui::SameLine();
//	}
//
//	changed = ImGui::HotkeyWidget(label, *hotkey, ImVec2(200, 0)) || changed;
//	HotkeyManager::GetInstance().RegisterKey(*hotkey, &toggleVar);
//
//	return changed;
//}

// Modified version of: https://github.com/spirthack/CSGOSimple/blob/master/CSGOSimple/UI.cpp#L287 
bool ImGui::HotkeyWidget(const char* label, Hotkey& hotkey, const ImVec2& size)
{
	// Init ImGui
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	ImGuiIO& io = g.IO;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);

	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	const ImVec2 item_size = ImGui::CalcItemSize(size, ImGui::CalcItemWidth(), label_size.y + style.FramePadding.y * 2.0f);

	const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + item_size);
	const ImRect total_bb(window->DC.CursorPos, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

	ImGui::ItemSize(total_bb, style.FramePadding.y);
	if (!ImGui::ItemAdd(total_bb, id))
		return false;


	const bool focus_requested = (ImGui::GetItemStatusFlags() & ImGuiItemStatusFlags_FocusedByTabbing) != 0 || g.NavActivateInputId == id;
	const bool hovered = ImGui::ItemHoverable(frame_bb, id);
	if (hovered)
	{
		ImGui::SetHoveredID(id);
		g.MouseCursor = ImGuiMouseCursor_TextInput;
	}

	static Hotkey _initHotkey;
	static Hotkey _currHotkey;
	static Hotkey _prevHotkey;

	const bool user_clicked = hovered && io.MouseClicked[0];
	if (focus_requested || user_clicked)
	{
		if (g.ActiveId != id)
		{
			memset(io.MouseDown, 0, sizeof(io.MouseDown));
			memset(io.KeysDown, 0, sizeof(io.KeysDown));

			_initHotkey = hotkey;
			_currHotkey = Hotkey();
			_prevHotkey = Hotkey();
		}

		ImGui::SetActiveID(id, window);
		ImGui::FocusWindow(window);
	}
	else if (io.MouseClicked[0] && g.ActiveId == id)
	{
		ImGui::ClearActiveID();
	}

	bool valueChanged = false;

	if (g.ActiveId == id)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Escape))
		{
			ImGui::ClearActiveID();
			if (hotkey != _initHotkey)
			{
				hotkey = _initHotkey;
				valueChanged = true;
			}
		}
		else
		{
			ImGui::NavMoveRequestCancel();

			auto newHotkey = Hotkey::GetPressedHotkey();

			if (newHotkey.IsEmpty() && !_currHotkey.IsEmpty())
			{
				ImGui::ClearActiveID();
				valueChanged = false;
			}
			else if (newHotkey - _prevHotkey)
			{
				_currHotkey = newHotkey;
				hotkey = newHotkey;
				valueChanged = true;
			}

			_prevHotkey = newHotkey;
		}

	}

	// Render
	// Select which buffer we are going to display. When ImGuiInputTextFlags_NoLiveEdit is Set 'buf' might still be the old value. We Set buf to NULL to prevent accidental usage from now on.

	char buf_display[128] = "Empty";

	const ImU32 frame_col = ImGui::GetColorU32(g.ActiveId == id ? ImGuiCol_FrameBgActive : hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg);
	ImGui::RenderFrame(frame_bb.Min, frame_bb.Max, frame_col, true, style.FrameRounding);

	if ((g.ActiveId == id && !_currHotkey.IsEmpty()) || g.ActiveId != id)
		strcpy_s(buf_display, static_cast<std::string>(hotkey).c_str());
	else if (g.ActiveId == id)
		strcpy_s(buf_display, "<Press a key>");

	const ImRect clip_rect(frame_bb.Min.x, frame_bb.Min.y, frame_bb.Min.x + item_size.x, frame_bb.Min.y + item_size.y); // Not using frame_bb.Max because we have adjusted size
	ImVec2 render_pos = frame_bb.Min + style.FramePadding;
	ImGui::RenderTextClipped(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding, buf_display, NULL, NULL, style.ButtonTextAlign, &clip_rect);
	//RenderTextClipped(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding, buf_display, NULL, NULL, GetColorU32(ImGuiCol_Text), style.ButtonTextAlign, &clip_rect);
	//draw_window->DrawList->AddText(g.Font, g.FontSize, render_pos, GetColorU32(ImGuiCol_Text), buf_display, NULL, 0.0f, &clip_rect);
	if (label_size.x > 0)
		ImGui::RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + style.FramePadding.y), label);

	return valueChanged;
}

void ImGui::TextURL(const char* text, const char* url)
{
	auto textSize = CalcTextSize(text);

	PushID(text);
	PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0));
	PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));
	if (InvisibleButton(text, textSize))
		Utils::OpenURL(url);
	PopStyleColor(3);
	PopID();

	if (IsItemHovered())
	{
		SetMouseCursor(ImGuiMouseCursor_Hand);
		SetTooltip("Open in browser\n%s", url);
	}

	SetCursorPosY(GetCursorPosY() - textSize.y);
	TextColored(ImVec4(0.0f, 0.5f, 1.0f, 1.0f), "%s", text);
}

bool ImGui::CheckboxFill(const char* label, bool* v)
{
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	const ImRect check_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(label_size.y + style.FramePadding.y * 2, label_size.y + style.FramePadding.y * 2));
	ItemSize(check_bb, style.FramePadding.y);

	ImRect total_bb = check_bb;
	if (label_size.x > 0)
		SameLine(0, style.ItemInnerSpacing.x);
	const ImRect text_bb(window->DC.CursorPos + ImVec2(0, style.FramePadding.y), window->DC.CursorPos + ImVec2(0, style.FramePadding.y) + label_size);
	if (label_size.x > 0)
	{
		ItemSize(ImVec2(text_bb.GetWidth(), check_bb.GetHeight()), style.FramePadding.y);
		total_bb = ImRect(ImMin(check_bb.Min, text_bb.Min), ImMax(check_bb.Max, text_bb.Max));
	}

	if (!ItemAdd(total_bb, id))
		return false;

	bool hovered, held;
	bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);
	if (pressed)
		*v = !(*v);

	RenderFrame(check_bb.Min, check_bb.Max, GetColorU32((held && hovered) ? ImGuiCol_FrameBgActive : hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg), true, style.FrameRounding);
	if (*v)
	{
		const float check_sz = ImMin(check_bb.GetWidth(), check_bb.GetHeight());
		const float pad = ImMax(1.0f, (float)(int)(check_sz / 6.0f));
		window->DrawList->AddRectFilled(check_bb.Min + ImVec2(pad, pad), check_bb.Max - ImVec2(pad, pad), GetColorU32(ImGuiCol_CheckMark), style.FrameRounding);
	}

	if (g.LogEnabled)
		LogRenderedText(&text_bb.Min, *v ? "[~]" : *v ? "[x]" : "[ ]");
	if (label_size.x > 0.0f)
		RenderText(text_bb.GetTL(), label);

	return pressed;
}

static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}

static auto vector_getter = [](void* vec, int idx, const char** out_text) {
	auto& vector = *static_cast<std::vector<std::string>*>(vec);
	if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
	*out_text = vector.at(idx).c_str();
	return true;
};

bool ImGui::Combo(const char* label, int* currIndex, std::vector<std::string>& values) {
	if (values.empty()) { return false; }
	return ImGui::Combo(label, currIndex, vector_getter,
		static_cast<void*>(&values), values.size());
}

bool ImGui::BeginGroupBox(const char* name, const ImVec2& size_arg)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_ChildWindow;

	window->DC.CursorPos.y += GImGui->FontSize / 2;
	const ImVec2 content_avail = ImGui::GetContentRegionAvail();
	ImVec2 size = ImFloor(size_arg);
	if (size.x <= 0.0f) {
		size.x = ImMax(content_avail.x, 4.0f) - fabsf(size.x); // Arbitrary minimum zero-ish child size of 4.0f (0.0f causing too much issues)
	}
	if (size.y <= 0.0f) {
		size.y = ImMax(content_avail.y, 4.0f) - fabsf(size.y);
	}

	ImGui::SetNextWindowSize(size);
	bool ret;
	ImGui::Begin(name, &ret, flags);
	//bool ret = ImGui::Begin(name, NULL, size, -1.0f, flags);

	window = ImGui::GetCurrentWindow();

	auto padding = ImGui::GetStyle().WindowPadding;

	auto text_size = ImGui::CalcTextSize(name, NULL, true);

	if (text_size.x > 1.0f) {
		window->DrawList->PushClipRectFullScreen();
		//window->DrawList->AddRectFilled(window->DC.CursorPos - ImVec2{ 4, 0 }, window->DC.CursorPos + (text_size + ImVec2{ 4, 0 }), GetColorU32(ImGuiCol_ChildWindowBg));
		//RenderTextClipped(pos, pos + text_size, name, NULL, NULL, GetColorU32(ImGuiCol_Text));
		window->DrawList->PopClipRect();
	}
	//if (!(window->Flags & ImGuiWindowFlags_ShowBorders))
	//	ImGui::GetCurrentWindow()->Flags &= ~ImGuiWindowFlags_ShowBorders;

	return ret;
}
void ImGui::EndGroupBox()
{
	ImGui::EndChild();
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DC.CursorPosPrevLine.y -= GImGui->FontSize / 2;
}

bool ImGui::ListBox(const char* label, int* current_item, std::string items[], int items_count, int height_items) {
	char** tmp;
	tmp = new char* [items_count];//(char**)malloc(sizeof(char*) * items_count);
	for (int i = 0; i < items_count; i++) {
		//tmp[i] = new char[items[i].size()];//(char*)malloc(sizeof(char*));
		tmp[i] = const_cast<char*>(items[i].c_str());
	}

	const bool value_changed = ImGui::ListBox(label, current_item, Items_ArrayGetter, static_cast<void*>(tmp), items_count, height_items);
	return value_changed;
}
bool ImGui::ListBox(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items)
{
	return ImGui::ListBox(label, current_item, [](void* data, int idx, const char** out_text)
		{
			*out_text = (*reinterpret_cast<std::function<const char* (int)>*>(data))(idx);
	return true;
		}, &lambda, items_count, height_in_items);
}
bool ImGui::Combo(const char* label, int* current_item, std::function<const char* (int)> lambda, int items_count, int height_in_items)
{
	return ImGui::Combo(label, current_item, [](void* data, int idx, const char** out_text)
		{
			*out_text = (*reinterpret_cast<std::function<const char* (int)>*>(data))(idx);
	return true;
		}, &lambda, items_count, height_in_items);
}
void ImGui::Separator(const char* label)
{
	const auto size = ImGui::CalcTextSize(label);
	auto draw_list = ImGui::GetWindowDrawList();
	const auto width = ImGui::GetContentRegionAvail().x;

	const auto cursor = ImGui::GetCursorScreenPos();
	const auto pos = ImVec2(cursor.x + width / 2 - size.x / 2, cursor.y);

	const auto start_col = ImGui::GetStyleColorVec4(ImGuiCol_SliderGrabActive);
	const auto col = ImGui::GetColorU32(start_col);
	const auto col2 = ImGui::GetColorU32(ImVec4(start_col.x, start_col.y, start_col.z, 0));

	draw_list->AddText(pos, ImGui::GetColorU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), label);

	// SEXY LOOKING RECT 
	draw_list->AddRectFilledMultiColor(ImVec2(cursor.x, cursor.y + size.y / 2), ImVec2(pos.x - 5.f, (cursor.y + size.y / 2) + 2), col2, col, col2, col);
	//draw_list->AddRectFilledMultiColor(ImVec2(cursor.x, cursor.y + size.y / 2), ImVec2(pos.x - 5.f, (cursor.y + size.y / 2) + 2), col2, col, col, col2);
	draw_list->AddRectFilledMultiColor(ImVec2(pos.x + size.x + 5.f, cursor.y + size.y / 2), ImVec2(cursor.x + width, (cursor.y + size.y / 2) + 2), col, col2, col2, col);

	ImGui::NewLine();
}
void ImGui::RainbowSeparator(const char* label)
{
	Color colColor(0, 0, 0);
	static float flRainbow;
	float flSpeed = 0.001f;
	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;

	const auto size = ImGui::CalcTextSize(label);
	auto draw_list = ImGui::GetWindowDrawList();
	const auto width = ImGui::GetContentRegionAvail().x;

	const auto cursor = ImGui::GetCursorScreenPos();
	const auto pos = ImVec2(cursor.x + width / 2 - size.x / 2, cursor.y);

	const auto start_col = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
	const auto col = ImGui::GetColorU32(start_col);
	const auto col2 = ImGui::GetColorU32(ImVec4(start_col.x, start_col.y, start_col.z, 0));

	draw_list->AddText(pos, ImGui::GetColorU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), label);
	for (float i = 0; i < width; i++)
	{
		float hue = (1.f / (float)width) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;
		Color colRainbow = colColor.FromHSB(hue, 1.f, 1.f);

		draw_list->AddRectFilledMultiColor(ImVec2(cursor.x, cursor.y + size.y / 2), ImVec2(pos.x - 5.f, (cursor.y + size.y / 2) + 2), col2, colRainbow.GetU32(), col, col2);
		draw_list->AddRectFilledMultiColor(ImVec2(pos.x + size.x + 5.f, cursor.y + size.y / 2), ImVec2(cursor.x + width, (cursor.y + size.y / 2) + 2), colRainbow.GetU32(), col2, col, col2);
	}
	ImGui::NewLine();
}

float GuiUtil::GetX()
{
	return ImGui::GetContentRegionAvail().x;
}

float GuiUtil::GetY()
{
	return ImGui::GetContentRegionAvail().y;
}

void GuiUtil::RainbowRectFilled(int x, int y, int width, int height, float flSpeed, float& flRainbow)
{
	ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
	Color colColor(0, 0, 0);
	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;

	for (float i = 0; i < width; i++)
	{
		float hue = (1.f / (float)width) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;
		Color colRainbow = colColor.FromHSB(hue, 1.f, 1.f);
		windowDrawList->AddRectFilled(ImVec2(x + i, y), ImVec2(width, height), colRainbow.GetU32());
	}
}

void GuiUtil::RainbowLine()
{
	ImGui::BeginGroup();
	static float flRainbow;
	float flSpeed = 0.001f;
	int height, width;

	ImVec2 curPos = ImGui::GetCursorPos();
	ImVec2 curWindowPos = ImGui::GetWindowPos();
	curPos.x += curWindowPos.x;
	curPos.y += curWindowPos.y;
	ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
	GuiUtil::RainbowRectFilled(curPos.x - 6, curPos.y - 6, WINDOW_WIDTH, curPos.y - 2, flSpeed, flRainbow);

	ImGui::EndGroup();
}

void GuiUtil::Line(int newId)
{
	std::string id = "pp_line" + std::to_string(newId);
	ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
	{
		ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
		ImGui::Separator();
		ImGui::EndChild();
	}
	ImGui::PopStyleColor();
}

void GuiUtil::LineVertical()
{
	ImGui::SameLine();
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
	ImGui::SameLine();
}

void GuiUtil::LineHorizontal()
{
	ImGui::SameLine();
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
	ImGui::SameLine();
}

void GuiUtil::CenterText(const char* text, int lineId, bool separator)
{
	if (text == nullptr)
		return;

	ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
	ImGui::Text(text);
	ImGui::Spacing();
	if (true == separator)
		Line(lineId);
}

void GuiUtil::CenterTextEx(const char* text, float width, int lineId, bool separator)
{
	if (text == nullptr)
		return;

	ImGui::SameLine((width / 2) - (ImGui::CalcTextSize(text).x / 2));
	ImGui::Text(text);

	if (true == separator)
		Line(lineId);
}

void GuiUtil::DrawTextImGui(ImVec2 position, ImColor color, const char* format, ...)
{
	if (format == nullptr)
		return;

	char buffer[512];

	va_list  args;
	va_start(args, format);
	vsnprintf_s(buffer, sizeof(buffer), format, args);
	va_end(args);

	ImGui::GetBackgroundDrawList()->AddText(position, color, format, buffer);
}

void GuiUtil::DrawTextOutlined(const char* text)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	Color col;
	ImVec2 text_pos(window->DC.CursorPos.x, window->DC.CursorPos.y + window->DC.CurrLineTextBaseOffset);

	GuiUtil::DrawTextImGui(ImVec2(text_pos.x, text_pos.y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(col.r() / MAX_RGB, col.g() / MAX_RGB, col.b() / MAX_RGB, 1.00f)), text);
	GuiUtil::DrawTextImGui(ImVec2(text_pos.x, text_pos.y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(col.r() / MAX_RGB, col.g() / MAX_RGB, col.b() / MAX_RGB, 1.00f)), text);
	GuiUtil::DrawTextImGui(ImVec2(text_pos.x - 1, text_pos.y), ImGui::ColorConvertFloat4ToU32(ImVec4(col.r() / MAX_RGB, col.g() / MAX_RGB, col.b() / MAX_RGB, 1.00f)), text);
	GuiUtil::DrawTextImGui(ImVec2(text_pos.x + 1, text_pos.y), ImGui::ColorConvertFloat4ToU32(ImVec4(col.r() / MAX_RGB, col.g() / MAX_RGB, col.b() / MAX_RGB, 1.00f)), text);
	GuiUtil::DrawTextImGui(ImVec2(text_pos.x, text_pos.y), ImGui::ColorConvertFloat4ToU32(ImVec4(col.r() / MAX_RGB, col.g() / MAX_RGB, col.b() / MAX_RGB, 1.00f)), text);
}

ImVec4 GuiUtil::ToVec4(float r, float g, float b, float a)
{
	return ImVec4(r / MAX_RGB, g / MAX_RGB, b / MAX_RGB, a / MAX_RGB);
}