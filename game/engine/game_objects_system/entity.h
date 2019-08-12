#pragma once

/*
Base class for, ships, planets etc
*/

#include<SFML/Graphics.hpp>

struct GameWorld;

class Entity {
public:
	// Members shared
	GameWorld& world; // World reference 

public:
	Entity(GameWorld& _world) : world(_world) { }
	virtual ~Entity() { }

	virtual sf::Drawable& GetDrawable() = 0; // Pos, size
	virtual void Update() { }

};