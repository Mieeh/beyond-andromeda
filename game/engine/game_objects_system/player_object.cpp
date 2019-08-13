#include "player_object.h"

#include<iostream>		

PlayerObject::PlayerObject(GameWorld& world) : Entity(world)
{
	shipSprite.setSize(sf::Vector2f(30, 120));
	shipSprite.setFillColor(sf::Color::Red);
	shipSprite.setOrigin(sf::Vector2f(shipSprite.getSize().x/2, shipSprite.getSize().y/2));
	shipSprite.setPosition({ 0, 0 });

	PhysicsSystem::Get()->AddPhysicsBody(this);
	EventSystem::Get()->AddEventListener(this);
}

sf::Drawable & PlayerObject::GetDrawable()
{
	// TODO: insert return statement here
	return shipSprite;
}

void PlayerObject::Update()
{
	shipSprite.setRotation(angle);
	shipSprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void PlayerObject::FixedUpdate()
{
	
}

void PlayerObject::ProcessEvent(const sf::Event& event)
{

}

void PlayerObject::KeyPressed(sf::Keyboard::Key key)
{

}
