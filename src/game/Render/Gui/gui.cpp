#include "gui.h"
#include "global.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
	auto& vars = Vars::GetInstance();
	
    ImGui::Begin("##Taiga74164", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::BeginGroup();
        {
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
            GuiUtil::CenterText("Solo Leveling Cheeto", 0, 0);
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
			MENU_MODULES("Misc", 1);
			MENU_MODULES("Hotkeys", 2);
			MENU_MODULES("About", 3);

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
		case 0: // Features
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			//ImGui::CheckboxFill("Animation Speed", &vars.PlayerSpeed.value());
			//if (vars.PlayerSpeed.value())
			//	ImGui::SliderFloat("Speed", &vars.PlayerSpeedValue.value(), 1.0f, 20.0f, "%.1f");

			ImGui::CheckboxFill("No Cooldown", &vars.NoCooldown.value());

			ImGui::CheckboxFill("No Cooldown Shadow", &vars.NoCooldownShadow.value()); HELPMAKER("Enable only if you have shadow feature available");

			ImGui::CheckboxFill("God Mode", &vars.GodMode.value());

			ImGui::CheckboxFill("Kill Aura", &vars.KillAura.value());

			ImGui::CheckboxFill("Damage Hack", &vars.DamageHack.value());
			if (vars.DamageHack.value())
				ImGui::SliderInt("Value", &vars.DamageHackValue.value(), 10000, 100000000, "%d");

			ImGui::CheckboxFill("Dumb Enemies", &vars.DumbEnemies.value()); HELPMAKER("This will prevent enemies from attacking or moving towards you");

			ImGui::CheckboxFill("Mob Vacuum", &vars.MobVacuum.value()); HELPMAKER("You have to go to the checkpoint before killing them");
			if (vars.MobVacuum.value())
			{
				ImGui::SliderFloat("Range", &vars.VacuumRange.value(), 1.0f, 50.0f, "%.1f");
				ImGui::SliderFloat("Distance", &vars.VacuumDistance.value(), 1.0f, 10.0f, "%.1f");
			}

			ImGui::CheckboxFill("Mission Time", &vars.MissionTime.value()); HELPMAKER("Make sure this is enabled before starting a mission");
			if (vars.MissionTime.value())
				ImGui::SliderInt("Time (ms)", &vars.MissionTimeMs.value(), 180000, 3600000, "%d");

			ImGui::CheckboxFill("Time Scale", &vars.TimeScale.value());
			if (vars.TimeScale.value())
				ImGui::SliderFloat("Speed", &vars.TimeScaleSpeed.value(), 1.0f, 10.0f, "%.1f");

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 1: // Misc
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill("FPS Unlock", &vars.FPSUnlock.value());
			if (vars.FPSUnlock.value())
				ImGui::SliderInt("FPS", &vars.FPSValue.value(), 5, 360, "%d");
			
			ImGui::CheckboxFill("Fov Changer", &vars.FovChanger.value());
			if (vars.FovChanger.value())
				ImGui::SliderFloat("Fov", &vars.Fov.value(), 1.0f, 360.0f, "%.1f");

			ImGui::CheckboxFill("Skip Intro Movie", &vars.SkipIntroMovie.value()); HELPMAKER("This will skip the intro movie when you start the game");

			ImGui::CheckboxFill("Disable WebView", &vars.DisableWebView.value()); HELPMAKER("Disables WebView pop-up every time you enter the game");

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 2: // Hotkeys
			//ImGui::InputHotkey("PlayerSpeed", vars.PlayerSpeed);
			ImGui::InputHotkey("NoCooldown", vars.NoCooldown);
			ImGui::InputHotkey("NoCooldownShadow", vars.NoCooldownShadow);
			ImGui::InputHotkey("GodMode", vars.GodMode);
			ImGui::InputHotkey("DamageHack", vars.DamageHack);
			//ImGui::InputHotkey("DamagePercentage", vars.DamagePercentage);
			//ImGui::InputHotkey("DamageFixed",& vars.DamageFixedHotkey, vars.DamageFixed);
			ImGui::InputHotkey("MobVacuum", vars.MobVacuum);
			ImGui::InputHotkey("DumbEnemies", vars.DumbEnemies);
			ImGui::InputHotkey("MissionTime", vars.MissionTime);
			ImGui::InputHotkey("TimeScale", vars.TimeScale);
			ImGui::InputHotkey("FPSUnlock", vars.FPSUnlock);
			ImGui::InputHotkey("FovChanger", vars.FovChanger);
			ImGui::InputHotkey("SkipIntroMovie", vars.SkipIntroMovie);
			ImGui::InputHotkey("DisableWebView", vars.DisableWebView);

			break;
		case 3: // About
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