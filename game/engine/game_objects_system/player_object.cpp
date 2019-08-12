#include "player_object.h"

PlayerObject::PlayerObject(GameWorld& world) : Entity(world)
{
	shipSprite.setSize(sf::Vector2f(30, 120));
	shipSprite.setFillColor(sf::Color::Red);
	shipSprite.setPosition(sf::Vector2f(-15, -15));
}

sf::Drawable & PlayerObject::GetDrawable()
{
	// TODO: insert return statement here
	return shipSprite;
}