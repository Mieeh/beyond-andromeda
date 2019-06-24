#include "ui_system.h"
UISystem* UISystem::instance = nullptr;

#include<iostream>

#include<SFML\Graphics.hpp>

#include"../imgui/imgui.h"
#include"../current.h"
#include"../sfml/sfml_window_singleton.h"
#include"../asteroid_generator.h"

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
	static auto current = Current::Get();
	static auto render_window = SFMLWindow::Get()->window;
	static sf::VertexArray asteroid_vertex_array;

	ImVec2 windowSize = ImGui::GetIO().DisplaySize;
	bool* p_open = NULL;
	int window_config = ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_::ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize;
	
	static ImVec2 selectViewProportions(0.45, 0.35); // Percent of screen 
	static ImVec2 shipWindowProportions(0.4, 0.2);
	static ImVec2 logProportions(0.3, 0.25);

	ImVec2 selectViewSize = ImVec2(windowSize.x * selectViewProportions.x, windowSize.y * selectViewProportions.y);
	ImVec2 shipWindowSize(windowSize.x*shipWindowProportions.x, windowSize.y*shipWindowProportions.y);
	ImVec2 shipWindowPos(0, windowSize.y - shipWindowSize.y);
	ImVec2 logSize = ImVec2(windowSize.x*logProportions.x, windowSize.y*logProportions.y);
	ImVec2 logPosition = ImVec2(windowSize.x - logSize.x, 0);

	/* Select view window */
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(selectViewSize);
	ImGui::Begin("Select View", p_open, window_config);

	static float minR, maxR, minStep, maxStep;
	static ImVec2 origin = ImVec2(windowSize.x/2, windowSize.y/2);
	ImGui::InputFloat("Min Radius", &minR, 1, 5);
	ImGui::InputFloat("Max Radius", &maxR, 1, 5);
	std::string x = "Ends at: " + std::to_string(2*3.14159f);
	ImGui::Text(x.c_str());
	ImGui::InputFloat("Min Step", &minStep, 0.1f, 0.0f);
	ImGui::InputFloat("Max Step", &maxStep, 0.1f, 0.0f);
	ImGui::InputFloat2("Origin", (float*)&origin);

	if (ImGui::Button("Generate Asteroid")) {
		sf::Color _color(rand()%255, rand() % 255, rand() % 255);
		GenerateAsteroidVertexArray(minR, maxR, minStep, maxStep, origin, 
			_color, asteroid_vertex_array);
	}

	ImGui::End();

	///* Ship window */
	//ImGui::SetNextWindowPos(shipWindowPos);
	//ImGui::SetNextWindowSize(shipWindowSize);
	//ImGui::Begin("Ship View", p_open, window_config);
	//
	//std::string integrity = "Integrity: " + std::to_string(current->ship.hp) + "/" + std::to_string(MAX_HP(current->ship.shipStructure.hull));
	//ImGui::Text(integrity.c_str());
	//
	//// Stats
	//std::string shipStats = "Engine: " + std::to_string(current->ship.shipStructure.engine)
	//	+ "\nHull: " + std::to_string(current->ship.shipStructure.hull) + "\nAnalyzer: " + 
	//	std::to_string(current->ship.shipStructure.analyzer);
	//ImGui::Text(shipStats.c_str());
	//
	//ImGui::End();
	//
	///* Ship window */
	//ImGui::SetNextWindowPos(logPosition);
	//ImGui::SetNextWindowSize(logSize);
	//ImGui::Begin("Log", p_open, window_config);
	//
	//ImGui::End();

	// Test rendering for asteroid
	render_window->draw(asteroid_vertex_array);
}