#include "pch.h"
#include "ProductChanger.h"

std::string ProductChanger::GetPluginName()
{
	return "ProductChanger";
}

void ProductChanger::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> ProductChanger
void ProductChanger::RenderSettings()
{
	ImGui::Checkbox("Remove Goal Explosion For Local Player", &RemoveGoalExplosionForLocalPlayer);
	ImGui::Checkbox("Default Engine For Local Player", &DefaultEngineForLocalPlayer);
	ImGui::NewLine();
	ImGui::Checkbox("Remove Goal Explosion For Other Players", &RemoveGoalExplosionForOtherPlayers);
	ImGui::Checkbox("Default Engine For Other Players", &DefaultEngineForOtherPlayers);
}

/*
// Do ImGui rendering here
void ProductChanger::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string ProductChanger::GetMenuName()
{
	return "ProductChanger";
}

// Title to give the menu
std::string ProductChanger::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void ProductChanger::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool ProductChanger::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool ProductChanger::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void ProductChanger::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void ProductChanger::OnClose()
{
	isWindowOpen_ = false;
}
*/
