#pragma once


#include<SFML\Graphics.hpp>

class AsteroidObject {
public:
	/* Methods */
	AsteroidObject();
	sf::Drawable& GetDrawable();

	sf::VertexArray points;
};