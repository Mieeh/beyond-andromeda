#include "game_world.h"

#include"ui_system.h"

#include<SFML\Graphics.hpp>

void GameWorld::setupWorld()
{
	// Call setup on systems
	UISystem::Get()->setup();

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
	/* Call render methods and render all entities */
	render_window.draw(ship_object.GetDrawable());

	render_window.draw(sun_object.GetDrawable());

	render_window.draw(alyssum_object.GetDrawable());

	for (auto& astr : asteroids) {
		render_window.draw(astr.GetDrawable());
	}

	UISystem::Get()->render();
}

void GameWorld::update(float dt)
{
	alyssum_object.Update(dt);
}
