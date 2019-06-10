#include "binary_stream.h"

#include"../constants.h"

#include<fstream>

void BinaryStream::serializePilot(const int id, const Pilot & pilot)
{
	// Write a binary file of pilot to a new bin file
	std::ofstream ostream(PERSISTENT_PATH + std::to_string(id) + ".pilot", std::ios::binary | std::ios::trunc);

	// Write pilot things to the pilot file
	ostream.write((char*)&pilot.name, sizeof(pilot.name));
}

Pilot BinaryStream::deserializePilot(std::string file_name)
{
	Pilot pilot;


}
