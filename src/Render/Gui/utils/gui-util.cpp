#include "gui-util.hpp"
#include "Utils.h"

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