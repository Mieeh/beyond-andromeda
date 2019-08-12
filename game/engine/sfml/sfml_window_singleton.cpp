#include "sfml_window_singleton.h"

SFMLWindow* SFMLWindow::instance = nullptr;

SFMLWindow * SFMLWindow::Get()
{
	if (instance == nullptr) {
		instance = new SFMLWindow();
	}
	return instance;
}

void SFMLWindow::CreateWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Beyond Andromeda");

	// Set views
	view.reset(sf::FloatRect(0, 0, 800, 600));
	window->setView(view);
}

void SFMLWindow::Shutdown()
{
	delete window;
}