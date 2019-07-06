#pragma once

#include"planet_object.h"
#include"../renderable.h"

#include<SFML\Graphics.hpp>

class AlyssumObject : public PlanetObject, public Renderable {
public:
	AlyssumObject();
	sf::Drawable& GetDrawable() override;
	void Update(float dt);

	sf::CircleShape shape;
	double angle;
};