#include "ui_system.h"
UISystem* UISystem::instance = nullptr;

#include<iostream>

#include<SFML\Graphics.hpp>

#include"../imgui/imgui.h"
#include"../current.h"
#include"../sfml/sfml_window_singleton.h"

UISystem * UISystem::Get()
{
	if (instance == nullptr)
		instance = new UISystem();
	return instance;
}

void UISystem::Setup()
{

}

void UISystem::Render()
{
	static auto current = Current::Get();
	static auto window_singleton = SFMLWindow::Get();

	ImVec2 windowSize = ImGui::GetIO().DisplaySize;
	bool* p_open = NULL;
	int window_config = ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize;
	
	static ImVec2 selectViewProportions(0.3, 0.3); // Percent of screen 
	static ImVec2 shipWindowProportions(0.4, 0.2);
	static ImVec2 logProportions(0.3, 0.3);

	ImVec2 selectViewSize = ImVec2(windowSize.x * selectViewProportions.x, windowSize.y * selectViewProportions.y);
	ImVec2 shipWindowSize(windowSize.x*shipWindowProportions.x, windowSize.y*shipWindowProportions.y);
	ImVec2 shipWindowPos(0, windowSize.y - shipWindowSize.y);
	ImVec2 logSize = ImVec2(windowSize.x*logProportions.x, windowSize.y*logProportions.y);
	ImVec2 logPosition = ImVec2(windowSize.x - logSize.x, 0);

	/* Select view window */
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(selectViewSize);				
	ImGui::Begin("Select View", p_open, window_config);

	float x = window_singleton->view.getCenter().x;
	float y = window_singleton->view.getCenter().y;
	ImGui::DragFloat("x", &x);
	ImGui::DragFloat("y", &y);

	if (ImGui::Button("-")) {
		window_singleton->view.zoom(1.1);
	}
	ImGui::SameLine();
	if (ImGui::Button("+")) {
		window_singleton->view.zoom(0.9);
	}

	window_singleton->view.setCenter({ x,y });

	ImGui::DragFloat("Time Scale", &Current::Get()->timeScale, 0.1f);   

	ImGui::End();

	/* Ship window */
	ImGui::SetNextWindowPos(shipWindowPos);
	ImGui::SetNextWindowSize(shipWindowSize);
	ImGui::Begin("Ship View", p_open, window_config);
	
	std::string integrity = "Integrity: " + std::to_string(current->ship.hp) + "/" + std::to_string(MAX_HP(current->ship.shipStructure.hull));
	ImGui::Text(integrity.c_str());
	
	// Stats
	std::string shipStats = "Engine: " + std::to_string(current->ship.shipStructure.engine)
		+ "\nHull: " + std::to_string(current->ship.shipStructure.hull) + "\nAnalyzer: " + 
		std::to_string(current->ship.shipStructure.analyzer);
	ImGui::Text(shipStats.c_str());
	
	ImGui::End();
	
	/* Ship window */
	ImGui::SetNextWindowPos(logPosition);
	ImGui::SetNextWindowSize(logSize);
	ImGui::Begin("Log", p_open, window_config);
	
	ImGui::End();
}
