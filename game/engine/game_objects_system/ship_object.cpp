#include "ship_object.h"

ShipObject::ShipObject()
{
	shipSprite.setSize(sf::Vector2f(30, 200));
	shipSprite.setFillColor(sf::Color::Red);
}

sf::Drawable & ShipObject::GetDrawable()
{
	// TODO: insert return statement here
	return shipSprite;
}
