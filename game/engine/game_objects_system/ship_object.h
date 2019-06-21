#pragma once

#include<squip-ecs\squip-ecs.h>
#include"../renderable.h"
#include<SFML\Graphics.hpp>

class ShipObject : public Renderable {
public:
	/* Methods */
	ShipObject();
	sf::Drawable& GetDrawable() override;

	/* Members */
	sf::RectangleShape shipSprite;

};