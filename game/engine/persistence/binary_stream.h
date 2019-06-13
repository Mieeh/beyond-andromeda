#pragma once

#include<string>

struct Pilot;
struct Ship;

struct BinaryStream {
	/*
	id is used to construct file name
	*/
	void serializePilot(const int id, const Pilot& pilot);
	Pilot deserializePilot(std::string file_name);

	/*
	id is used to construcct file name
	*/
	void serializeShip(const int id, const Ship& ship);
	Ship deserializeShip(std::string file_name);
};
