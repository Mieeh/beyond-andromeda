#pragma once

#include"../pilot.h"

struct BinaryStream {
	void serializePilot(const int id, const Pilot& pilot);
	Pilot deserializePilot(std::string file_name);
};
