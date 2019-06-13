#include "binary_stream.h"

#include"../constants.h"
#include"../ship.h"
#include"../pilot.h"

#include<fstream>
#include<iostream>

void BinaryStream::serializePilot(const int id, const Pilot & pilot)
{
	// Write a binary file of pilot to a new bin file
	std::ofstream ostream(PERSISTENT_PATH + std::to_string(id) + ".pilot", std::ios::binary | std::ios::trunc);

	// Write name to the binary file
	size_t len = pilot.name.size();
	ostream.write((char*)&len, sizeof(len));
	ostream.write(pilot.name.c_str(), len);

	ostream.close();
}

Pilot BinaryStream::deserializePilot(std::string file_name)
{
	Pilot pilot;

	// Open files 
	std::ifstream istream(PERSISTENT_PATH + file_name, std::ios::binary);
	if (!istream.is_open()) {
		std::cout << "Deserializing pilot-function: file not found!!! big error" << std::endl;
		return pilot;
	}

	// Read pilot name
	size_t len = 0;
	istream.read((char*)&len, sizeof(len));
	char* temp = new char[len + 1];
	istream.read(temp, len);
	temp[len] = '\0';
	pilot.name = temp; // Set pilot name to the read buffer array
	delete[] temp;


	return pilot;
}

void BinaryStream::serializeShip(const int id, const Ship & ship)
{
	// Write a binary file of ship to a new bin file
	std::ofstream ostream(PERSISTENT_PATH + std::to_string(id) + ".ship", std::ios::binary | std::ios::trunc);

	// Write hp and ship structure
	ostream.write((char*)&ship.hp, sizeof(int));
	ostream.write((char*)&ship.shipStructure, sizeof(ShipStructure));
}

Ship BinaryStream::deserializeShip(std::string file_name)
{
	Ship ship;

	// Open files 
	std::ifstream istream(PERSISTENT_PATH + file_name, std::ios::binary);
	if (!istream.is_open()) {
		std::cout << "Deserializing ship-function: file not found!!! big error" << std::endl;
		return ship;
	}

	// Read hp
	istream.read((char*)&ship.hp, sizeof(int));
	// Read ship structure
	istream.read((char*)&ship.shipStructure, sizeof(ShipStructure));

	return ship;
}
