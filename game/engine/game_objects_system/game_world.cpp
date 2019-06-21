#include "game_world.h"

#include"ui_system.h"

#include<SFML\Graphics.hpp>

void GameWorld::setupWorld()
{
	// Call setup on systems
	UISystem::Get()->setup();
}

void GameWorld::render()
{
	/* Call render methods and render all entities */
	render_window.draw(ship_object.GetDrawable());

	UISystem::Get()->render();
}
