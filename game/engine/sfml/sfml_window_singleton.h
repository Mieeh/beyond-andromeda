#pragma once

// Singleton window for a sfml render window

namespace sf {
	class RenderWindow;
}

class SFMLWindow {
private:
	// Private constructor
	SFMLWindow() { }
	// Static instance
	static SFMLWindow* instance;

public:
	// Getter for private instance
	static SFMLWindow* Get();

	/*
	Sets-up sfml window
	*/
	void CreateWindow();

	/*
	Called on application exit
	*/
	void Shutdown();
	
	// Public members
	sf::RenderWindow* window;
};