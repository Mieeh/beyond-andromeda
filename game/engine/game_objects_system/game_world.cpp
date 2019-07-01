#include "game_world.h"

#include"ui_system.h"

#include<SFML\Graphics.hpp>

void GameWorld::setupWorld()
{
	// Call setup on systems
	UISystem::Get()->setup();

	for (int i = 0; i < 10; i++) {
		asteroids.push_back(new AsteroidObject());
	}
}

void GameWorld::render()
{
	/* Call render methods and render all entities */
	render_window.draw(ship_object.GetDrawable());
	for (auto& astr : asteroids) {
		render_window.draw(astr->GetDrawable());
	}

	UISystem::Get()->render();
}
