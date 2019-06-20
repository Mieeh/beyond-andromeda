#include "main_part.h"

#include"../engine/imgui/imgui.h"
#include"../engine/imgui/imgui-SFML.h"

#include<squip-ecs\squip-ecs.h>
#include<SFML\Graphics.hpp>

#include"../engine/sfml/sfml_window_singleton.h"
#include"../engine/sfml/sfml_audio_singleton.h"

using namespace squip;

void MainPart::enter()
{
	// Get the window from the singleton class
	SFMLWindow::Get()->CreateWindow();
	auto& window = *SFMLWindow::Get()->window;
	ImGui::SFML::Init(window); // Init IMGUI-SFML connection
	
	// Load sfx
	SFMLAudio::Get(); // Loads sfx in the constructor method
															
	ecs::World world;
	world.addEntity("run that shit back");

	// Main game loop
	sf::Clock deltaClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event); // Send processed event to ImGui
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		// Clear for render
		window.clear();
	
		/* Logic updates here */
		ImGui::SFML::Update(window, deltaClock.restart()); // Update IMGUI
		world.onUpdate();

		/* Render starts here */
		ImGui::ShowDemoWindow();

		ImGui::SFML::Render(window); // Render ImGUI
		window.display();
	}

	// End
	SFMLWindow::Get()->Shutdown();
}