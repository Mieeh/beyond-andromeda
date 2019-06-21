#pragma once

#include"ship_object.h"

namespace sf {
	class RenderWindow;
}

struct GameWorld {

	ShipObject ship_object;
	sf::RenderWindow& render_window;

	GameWorld(sf::RenderWindow& window) : render_window(window) { }
	void setupWorld();
	void render(); // Renders stuff

};