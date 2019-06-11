#include "binary_stream.h"

#include"../constants.h"

#include<fstream>
#include<iostream>

void BinaryStream::serializePilot(const int id, const Pilot & pilot)
{
	// Write a binary file of pilot to a new bin file
	std::ofstream ostream(PERSISTENT_PATH + std::to_string(id) + ".pilot", std::ios::binary | std::ios::trunc);

	// Write pilot things to the pilot file
	ostream.write((char*)&pilot, sizeof(Pilot));
}

Pilot BinaryStream::deserializePilot(std::string file_name)
{
	Pilot pilot; // This is what we read into

	// Open files 
	std::ifstream istream(PERSISTENT_PATH + file_name, std::ios::binary | std::ios::app);
	if (!istream.is_open()) {
		std::cout << "Deserializing function: file not found!!! big error" << std::endl;
		return pilot;
	}

	// Read pilot struct into our pilot object then return
	istream.read((char*)&pilot.name, sizeof(std::string));

	return pilot;
}
