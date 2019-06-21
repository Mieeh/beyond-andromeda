#include "ui_system.h"
UISystem* UISystem::instance = nullptr;

#include<iostream>
#include"../imgui/imgui.h"

UISystem * UISystem::Get()
{
	if (instance == nullptr)
		instance = new UISystem();
	return instance;
}

void UISystem::setup()
{

}

void UISystem::render()
{
	// ImGui stuff
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	static bool s = true;
	int window_config = ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize;

	ImGui::Begin("Ship & Pilot", &s, window_config);

	ImGui::Text("Name: starlord dave");
	ImGui::Text("Analyzer: 4\nEngine: 3\nHull: 3");
	ImGui::Text("Closest Planet: 133AU");

	ImGui::End();
}
