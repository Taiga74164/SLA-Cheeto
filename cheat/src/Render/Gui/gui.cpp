#include "gui.h"
#include "global.h"
#include "imgui.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
	auto& vars = Vars::GetInstance();
	
    ImGui::Begin(xorstr("##Taiga74164"), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::BeginGroup();
        {
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
            GuiUtil::CenterText(xorstr(Utils::GenerateRandomString(10).c_str()), 0, 0);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::PopStyleColor();
        }
        ImGui::EndGroup();

		GuiUtil::RainbowLine();
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild(xorstr("##LeftSide"), ImVec2(100, GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

#define MENU_MODULES(name, tab) ImGui::PushStyleColor(ImGuiCol_Button, m_MenuTab == (tab) ? active : inactive); \
		     ImGui::Button(name, ImVec2(90 - 10, 22)); \
		     if (ImGui::IsItemClicked()) m_MenuTab = tab; \
		     ImGui::PopStyleColor()

			MENU_MODULES(xorstr("Features"), 0);
			MENU_MODULES(xorstr("Misc"), 1);
			MENU_MODULES(xorstr("Hotkeys"), 2);
			MENU_MODULES(xorstr("About"), 3);

#undef MENU_MODULES
		}
		ImGui::EndChild();

		GuiUtil::LineVertical();

		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild(xorstr("##RightSide"), ImVec2(GuiUtil::GetX(), GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGuiCol_Button ? active : inactive);
		switch (m_MenuTab)
		{
		case 0: // Features
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			//ImGui::CheckboxFill(xorstr("Animation Speed"), &vars.PlayerSpeed.value());
			//if (vars.PlayerSpeed.value())
			//	ImGui::SliderFloat(xorstr("Speed"), &vars.PlayerSpeedValue.value(), 1.0f, 20.0f, "%.1f");

			ImGui::CheckboxFill(xorstr("Instant Regen"), &vars.InstantRegen.value()); HELPMAKER(xorstr("Press Run"));

			ImGui::CheckboxFill(xorstr("No Cooldown"), &vars.NoCooldown.value());

			ImGui::CheckboxFill(xorstr("No Cooldown Shadow"), &vars.NoCooldownShadow.value()); HELPMAKER(xorstr("Enable only if you have shadow feature available"));

			ImGui::CheckboxFill(xorstr("God Mode"), &vars.GodMode.value());

			ImGui::CheckboxFill(xorstr("Kill Aura"), &vars.KillAura.value());

			ImGui::CheckboxFill(xorstr("Damage Hack"), &vars.DamageHack.value());
			if (vars.DamageHack.value())
				ImGui::SliderInt(xorstr("Value"), &vars.DamageHackValue.value(), 10000, 100000000, "%d");

			ImGui::CheckboxFill(xorstr("Dumb Enemies"), &vars.DumbEnemies.value()); HELPMAKER(xorstr("This will prevent enemies from attacking or moving towards you"));

			ImGui::CheckboxFill(xorstr("Mob Vacuum"), &vars.MobVacuum.value()); HELPMAKER(xorstr("You have to go to the checkpoint before killing them"));
			if (vars.MobVacuum.value())
			{
				ImGui::SliderFloat(xorstr("Range"), &vars.VacuumRange.value(), 1.0f, 50.0f, "%.1f");
				ImGui::SliderFloat(xorstr("Distance"), &vars.VacuumDistance.value(), 1.0f, 10.0f, "%.1f");
			}

			ImGui::CheckboxFill(xorstr("Mission Time"), &vars.MissionTime.value()); HELPMAKER(xorstr("Make sure this is enabled before starting a mission"));
			if (vars.MissionTime.value())
				ImGui::SliderInt(xorstr("Time (ms)"), &vars.MissionTimeMs.value(), 180000, 3600000, "%d");

			ImGui::CheckboxFill(xorstr("Time Scale"), &vars.TimeScale.value());
			if (vars.TimeScale.value())
				ImGui::SliderFloat(xorstr("Speed"), &vars.TimeScaleSpeed.value(), 1.0f, 10.0f, "%.1f");

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 1: // Misc
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill(xorstr("FPS Unlock"), &vars.FPSUnlock.value());
			if (vars.FPSUnlock.value())
				ImGui::SliderInt(xorstr("FPS"), &vars.FPSValue.value(), 5, 360, "%d");

			ImGui::CheckboxFill(xorstr("Fov Changer"), &vars.FovChanger.value());
			if (vars.FovChanger.value())
				ImGui::SliderFloat(xorstr("Fov"), &vars.Fov.value(), 1.0f, 360.0f, "%.1f");

			ImGui::CheckboxFill(xorstr("Skip Intro Movie"), &vars.SkipIntroMovie.value()); HELPMAKER(xorstr("This will skip the intro movie when you start the game"));

			ImGui::CheckboxFill(xorstr("Disable Web View"), &vars.DisableWebView.value()); HELPMAKER(xorstr("Disables WebView pop-up every time you enter the game"));

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 2: // Hotkeys
			//ImGui::InputHotkey(xorstr("PlayerSpeed"), vars.PlayerSpeed);
			ImGui::InputHotkey(xorstr("Instant Regen"), vars.InstantRegen);
			ImGui::InputHotkey(xorstr("No Cooldown"), vars.NoCooldown);
			ImGui::InputHotkey(xorstr("No Cooldown Shadow"), vars.NoCooldownShadow);
			ImGui::InputHotkey(xorstr("God Mode"), vars.GodMode);
			ImGui::InputHotkey(xorstr("Damage Hack"), vars.DamageHack);
			//ImGui::InputHotkey(xorstr("DamagePercentage"), vars.DamagePercentage);
			//ImGui::InputHotkey(xorstr("DamageFixed"),& vars.DamageFixedHotkey, vars.DamageFixed);
			ImGui::InputHotkey(xorstr("Mob Vacuum"), vars.MobVacuum);
			ImGui::InputHotkey(xorstr("Dumb Enemies"), vars.DumbEnemies);
			ImGui::InputHotkey(xorstr("Mission Time"), vars.MissionTime);
			ImGui::InputHotkey(xorstr("Time Scale"), vars.TimeScale);
			ImGui::InputHotkey(xorstr("FPS Unlock"), vars.FPSUnlock);
			ImGui::InputHotkey(xorstr("Fov Changer"), vars.FovChanger);
			ImGui::InputHotkey(xorstr("Skip Intro Movie"), vars.SkipIntroMovie);
			ImGui::InputHotkey(xorstr("Disable Web View"), vars.DisableWebView);

			break;
		case 3: // About
			ImGui::Spacing();
			ImGui::Text(xorstr("Created by: Taiga74164"));
			ImGui::TextURL(xorstr("Unknown Cheats thread"), xorstr("https://www.unknowncheats.me/forum/other-mmorpg-and-strategy/629636-solo-leveling-arise-cheeto.html"));
			break;
		}

		ImGui::PopStyleColor();
		ImGui::EndChild();
    }

    ImGui::End();
}