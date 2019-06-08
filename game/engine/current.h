#pragma once

#include"pilot.h"
#include"ship.h"

struct Current {
	static Current* _instance;

	static Current* Get() {
		if (_instance == nullptr) {
			_instance = new Current();
		}
		return _instance;
	}

	Pilot pilot;
	Ship ship;
};