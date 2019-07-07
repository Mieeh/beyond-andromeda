#pragma once

#include"ship_object.h"
#include"asteroid_object.h"
#include"sun_object.h"
#include"alyssum_object.h"

#include<vector>

namespace sf {
	class RenderWindow;
}

struct GameWorld {

	ShipObject ship_object;
	SunObject sun_object;
	AlyssumObject alyssum_object;
	std::vector<AsteroidObject> asteroids;

	sf::Shader sun_shader;
	sf::RenderWindow& render_window;

	GameWorld(sf::RenderWindow& window) : render_window(window) { }
	void setupWorld();
	void render(); // Renders stuff
	void update();

};