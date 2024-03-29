#include "gui.h"
#include "global.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
    ImGui::Begin("##Taiga74164", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::BeginGroup();
        {
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
            GuiUtil::CenterText("Solo Levelling Cheeto", 0, 0);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::PopStyleColor();
        }
        ImGui::EndGroup();

		GuiUtil::RainbowLine();
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild("##LeftSide", ImVec2(100, GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

#define MENU_MODULES(name, tab) ImGui::PushStyleColor(ImGuiCol_Button, m_MenuTab == (tab) ? active : inactive); \
		     ImGui::Button(name, ImVec2(90 - 10, 22)); \
		     if (ImGui::IsItemClicked()) m_MenuTab = tab; \
		     ImGui::PopStyleColor()

			MENU_MODULES("Features", 0);
			//MENU_MODULES("Debug", 1);
			MENU_MODULES("About", 1);

#undef MENU_MODULES
		}
		ImGui::EndChild();

		GuiUtil::LineVertical();

		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild("##RightSide", ImVec2(GuiUtil::GetX(), GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGuiCol_Button ? active : inactive);
		switch (m_MenuTab)
		{
		case 0: // Cheats
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill("No Cooldown", &vars.b_NoCooldown);
			ImGui::CheckboxFill("God Mode", &vars.b_GodMode);
			ImGui::CheckboxFill("Damage Hack", &vars.b_DamageHack);
			if (vars.b_DamageHack)
				ImGui::SliderFloat("Value", &vars.f_DamageHackValue, 200.0f, 5000.0f, "%1.0f");
			ImGui::CheckboxFill("Infinite Mission Time", &vars.b_InfiniteMissionTime);
			ImGui::CheckboxFill("Time Scale", &vars.b_TimeScale);
			if (vars.b_TimeScale)
				ImGui::SliderFloat("Speed", &vars.f_TimeScaleSpeed, 1.0f, 10.0f, "%.1f");
			
			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		//case 1: // Debug
		//	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
		//	ImGui::BeginGroup();
		//	ImGui::EndGroup();
		//	ImGui::PopStyleVar();
		//	break;
		case 1: // About
			ImGui::Spacing();
			ImGui::Text("Created by: Taiga74164");
			ImGui::TextURL("Unknown Cheats thread", "https://www.unknowncheats.me/forum/other-mmorpg-and-strategy/629636-solo-leveling-arise-cheeto.html");
			break;
		}

		ImGui::PopStyleColor();
		ImGui::EndChild();
    }

    ImGui::End();
}