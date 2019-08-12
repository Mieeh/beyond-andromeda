#pragma once

#include"entity.h"

#include<SFML\Graphics.hpp>

class AlyssumObject : public Entity {
public:
	AlyssumObject(GameWorld &world);
	sf::Drawable& GetDrawable() override;
	void Update() override;

	sf::CircleShape shape;
	double angle;
};