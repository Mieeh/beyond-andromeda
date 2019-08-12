#pragma once

#include"entity.h"

#include<SFML\Graphics.hpp>

class SunObject : public Entity {
public:
	/* Methods */
	SunObject(GameWorld& world);
	sf::Drawable& GetDrawable() override;

	sf::CircleShape shape;
};