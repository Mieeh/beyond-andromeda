#pragma once

#include"pilot.h"
#include"ship.h"

struct Current {
	Current();
	static Current* _instance;

	static Current* Get() {
		if (_instance == nullptr) {
			_instance = new Current();
		}
		return _instance;
	}

	/* Methods */
	inline float getTimeStep() { return deltaTime * timeScale; }

	/* Members */
	Pilot pilot;
	Ship ship;
	float timeScale;
	float deltaTime;
};