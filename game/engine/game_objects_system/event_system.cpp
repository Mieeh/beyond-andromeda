#include "event_system.h"

EventSystem* EventSystem::instance = nullptr;

EventSystem* EventSystem::Get()
{
	if (instance == nullptr)
		instance = new EventSystem();

	return instance;
}

void EventSystem::AddEventListener(EventListener* eventListener)
{
	eventListeners.push_back(eventListener);
}

void EventSystem::TakeEvent(const sf::Event& event)
{
	// Send event to everyone
	for (auto& x : eventListeners) {
		x->ProcessEvent(event);
	}

	if (event.type == sf::Event::KeyPressed) {
		for (auto& x : eventListeners) {
			x->KeyPressed(event.key.code);
		}
	}
}


