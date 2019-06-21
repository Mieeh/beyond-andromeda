#pragma once

class UISystem {
private:
	/* Singleton */
	UISystem() { }
	static UISystem* instance;

public:
	static UISystem* Get();

	void setup();
	void render();
};