#include "sun_object.h"

#include"../constants.h"

SunObject::SunObject()
{
	shape.setRadius(1*SR); // 1 sun radius
	shape.setFillColor(sf::Color::Yellow);
}

sf::Drawable & SunObject::GetDrawable()
{
	// TODO: insert return statement here
	return shape;
}
