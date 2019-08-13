#pragma once

#include"game_world.h"

class UISystem {
private:
	/* Singleton */
	UISystem() { }
	static UISystem* instance;

	GameWorld* game_world;

public:
	static UISystem* Get();

	void Setup(GameWorld* world);
	void Render();
};