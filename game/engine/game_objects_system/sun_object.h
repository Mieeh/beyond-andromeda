#pragma once

#include"../renderable.h"

#include<SFML\Graphics.hpp>

class SunObject : public Renderable {
public:
	/* Methods */
	SunObject();
	sf::Drawable& GetDrawable() override;

	sf::CircleShape shape;
};