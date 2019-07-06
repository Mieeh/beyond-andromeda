#include "alyssum_object.h"

#include"../constants.h"

#include<iostream>

AlyssumObject::AlyssumObject()
{
	angle = 0;

	shape.setRadius(0.2*SR);
	shape.setFillColor(sf::Color::Blue);
}

sf::Drawable & AlyssumObject::GetDrawable()
{
	// TODO: insert return statement here
	return shape;
}

void AlyssumObject::Update(float dt)
{
	// Angle incrementing
	angle += 2*dt;
	//if (angle > 2 * PI)
	//	angle = 0;

	std::cout << angle << std::endl;

	static double R = SR*1.2f;

	position.x = R*cos(angle);
	position.y = R*sin(angle);

	shape.setPosition(position);
}
