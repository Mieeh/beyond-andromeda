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
}

void SFMLWindow::Shutdown()
{
	delete window;
}