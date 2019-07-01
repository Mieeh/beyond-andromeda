#pragma once

#include"../renderable.h"

#include<SFML\Graphics.hpp>

class AsteroidObject : public Renderable {
public:
	/* Methods */
	AsteroidObject();
	sf::Drawable& GetDrawable() override;

	sf::VertexArray points;
};