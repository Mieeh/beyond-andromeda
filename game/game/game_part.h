#pragma once

struct GamePart {

	virtual void enter() { }

	GamePart* nextPart;

};