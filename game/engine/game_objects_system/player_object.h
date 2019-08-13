#pragma once

#include"entity.h"
#include"physics_system.h"
#include"event_system.h"

#include<SFML\Graphics.hpp>

class PlayerObject : public Entity, public PhysicsBody, public EventListener {
public:
	/* Methods */
	PlayerObject(GameWorld& world);
	sf::Drawable& GetDrawable() override;
	void Update() override;
	void FixedUpdate() override;
	void ProcessEvent(const sf::Event& event) override;
	void KeyPressed(sf::Keyboard::Key key) override;

	/* Members */
	sf::RectangleShape shipSprite;

};