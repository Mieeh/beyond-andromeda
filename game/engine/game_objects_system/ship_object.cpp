#include "ship_object.h"

ShipObject::ShipObject()
{
	shipSprite.setSize(sf::Vector2f(30, 30));
	shipSprite.setFillColor(sf::Color::Red);
	shipSprite.setPosition(sf::Vector2f(-15, -15));
}

sf::Drawable & ShipObject::GetDrawable()
{
	// TODO: insert return statement here
	return shipSprite;
}
