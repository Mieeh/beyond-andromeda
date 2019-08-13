#pragma once

#include<SFML/Graphics.hpp>
#include<vector>

// Singleton just as every other system in the engine

class EventListener {
public:
	virtual void ProcessEvent(const sf::Event& event) { }
	virtual void KeyPressed(sf::Keyboard::Key key) { }
};

class EventSystem {
private:
	/* Private methods */
	EventSystem() { }
	static EventSystem* instance;

	/* Methods */
	std::vector<EventListener*> eventListeners;

public:
	/* Methods */
	static EventSystem* Get();
	void AddEventListener(EventListener* eventListener);
	void TakeEvent(const sf::Event& event);
};