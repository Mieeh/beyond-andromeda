#pragma once

#include"entity.h"
#include<SFML\Graphics.hpp>

class PlayerObject : public Entity {
public:
	/* Methods */
	PlayerObject(GameWorld& world);
	sf::Drawable& GetDrawable() override;

	/* Members */
	sf::RectangleShape shipSprite;

};