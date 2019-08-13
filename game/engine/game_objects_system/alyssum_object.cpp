#include "alyssum_object.h"

#include"../constants.h"
#include"../planetary_utility.h"
#include"../current.h"
#include"../constants.h"

#include<iostream>

AlyssumObject::AlyssumObject(GameWorld &world) : Entity(world)
{
	angle = 0;

	shape.setRadius(ALYSSUM_R);
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(sf::Vector2f(ALYSSUM_R, ALYSSUM_R));
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
	angle += .5 * dt;
	if (angle > 2 * PI)
		angle = 0;

	static double x = 3.5 * SR;
	static double y = 2.5 * SR;

	shape.setPosition(x * cos(angle), y * sin(angle));
}
