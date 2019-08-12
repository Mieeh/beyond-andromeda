#include "game_world.h"

#include"ui_system.h"
#include"physics_system.h"

#include"player_object.h"
#include"asteroid_object.h"
#include"sun_object.h"
#include"alyssum_object.h"

#include<SFML\Graphics.hpp>
#include<iostream>

GameWorld::~GameWorld()
{
	for (auto* x : constant_entities) {
		delete x;   
	}
}
               
void GameWorld::setupWorld()
{
	// Create all entities
	constant_entities[0] = new AlyssumObject(*this);
	constant_entities[1] = new SunObject(*this);
	constant_entities[2] = new PlayerObject(*this);

	// Call setup on systems
	UISystem::Get()->Setup();
	PhysicsSystem::Get()->Setup();

	// Setup sun shader
	if (!sun_shader.loadFromFile("resources\\shaders\\sun.frag", sf::Shader::Fragment)) {
		std::cout << "Sun shader not loading!" << std::endl;
	}

	sun_shader.setUniform("fadedelta", 0.5f);
	//sun_shader.setParameter("img", sf::Shader::CurrentTexture);
	sun_shader.setUniform("width", 1600.0f);
	sun_shader.setUniform("g", 1.5f);
}

void GameWorld::render()
{
	for (int i = 0; i < NUM_OF_ENTITIES; i++) {
		render_window.draw(constant_entities[i]->GetDrawable());
	}			

	UISystem::Get()->Render();
}

void GameWorld::update()
{
	// Update all objects that need to be updated 
	for (int i = 0; i < NUM_OF_ENTITIES; i++) {
		constant_entities[i]->Update();
	}
}

void GameWorld::fixed_update()
{
	PhysicsSystem::Get()->FixedUpdate();
}
