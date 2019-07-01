#pragma once

#include"ship_object.h"
#include"asteroid_object.h"

#include<vector>

namespace sf {
	class RenderWindow;
}

struct GameWorld {

	ShipObject ship_object;
	sf::RenderWindow& render_window;
	std::vector<AsteroidObject*> asteroids;

	GameWorld(sf::RenderWindow& window) : render_window(window) { }
	void setupWorld();
	void render(); // Renders stuff

};