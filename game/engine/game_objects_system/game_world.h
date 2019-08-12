#pragma once

#include"entity.h"

#include<vector>

#define NUM_OF_ENTITIES 3

namespace sf {
	class RenderWindow;
}

struct GameWorld {
	
	~GameWorld();

	// Entities that we know are never going to be removed from the world
	// Keeping them in an array (const-size) makes the most sense!
	Entity* constant_entities[3];

	sf::Shader sun_shader;
	sf::RenderWindow& render_window;
	sf::RenderTexture render_texture;

	GameWorld(sf::RenderWindow& window) : render_window(window) { }
	void setupWorld();
	void render(); // Renders stuff
	void update();
	void fixed_update();

};