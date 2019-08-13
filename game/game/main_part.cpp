#include "main_part.h"

#include"../engine/imgui/imgui.h"
#include"../engine/imgui/imgui-SFML.h"

#include<SFML\Graphics.hpp>

#include"../engine/sfml/sfml_window_singleton.h"
#include"../engine/sfml/sfml_audio_singleton.h"

#include"../engine/game_objects_system/game_world.h"
#include"../engine/game_objects_system/physics_system.h"
#include"../engine/game_objects_system/event_system.h"

#include"../engine/current.h"

#include<iostream>

#define PI 3.14159

void MainPart::enter()
{
	srand(time(0)); // Seed random generation

	// Get the window from the singleton class
	SFMLWindow::Get()->CreateWindow();
	auto& window = *SFMLWindow::Get()->window;
	ImGui::SFML::Init(window); // Init IMGUI-SFML connection
	
	// Get the view 
	auto& view = SFMLWindow::Get()->view;
	view.setCenter({ 0,0 });
	
	// Load sfx
	SFMLAudio::Get(); // Loads sfx in the constructor method
				
	// World object
	GameWorld game_world(window);
	game_world.setupWorld();

	auto physicsSystem = PhysicsSystem::Get();
	auto eventSystem = EventSystem::Get();

	// Main game loop
	sf::Clock deltaClock1;
	sf::Clock deltaClock2;
	sf::Clock fixedUpdateClock;
	sf::Clock clock;

	fixedUpdateClock.restart();
	clock.restart();

	double physicsTimeSimulated = 0;
	double lastUpdateTime = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event); // Send processed event to ImGui
			eventSystem->TakeEvent(event); // Send event to the engine-system

			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized) {
				view.setSize({ (float)event.size.width, (float)event.size.height });
			}
		}

		while (physicsTimeSimulated < clock.getElapsedTime().asMilliseconds()) {
			game_world.fixed_update();
			physicsTimeSimulated += physicsSystem->physicsTimeStep;
		}
	
		/* Update */
		ImGui::SFML::Update(window, deltaClock1.restart()); // Update IMGUI
		Current::Get()->deltaTime = deltaClock2.restart().asSeconds();
		game_world.update();

		// Used for fixed update
		lastUpdateTime = clock.getElapsedTime().asMilliseconds();

		// Clear for render
		window.clear();
	
		// View thingy has to been done each frame appearently...
		window.setView(view);

		/* Render starts here */
		game_world.render();

		ImGui::SFML::Render(window); // Render ImGUI
		window.display();
	}

	// End
	SFMLWindow::Get()->Shutdown();
}