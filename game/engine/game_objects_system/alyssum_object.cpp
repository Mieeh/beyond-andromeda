#include "alyssum_object.h"

#include"../constants.h"
#include"../planetary_utility.h"
#include"../current.h"

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

void AlyssumObject::Update()
{
	float dt = Current::Get()->getTimeStep();

	// Angle incrementing
	angle += .2 * dt;
	if (angle > 2 * PI)
		angle = 0;

	static double a = 3 * SR;
	static double b = 1.5 * SR;

	position.x = a * cos(angle) - 0.2*SR;
	position.y = b * sin(angle) - 0.2*SR;

	shape.setPosition(position);
}
