#include "persistence.h"

#include"../constants.h"

#include<filesystem>
#include<iostream>

namespace fs = std::experimental::filesystem;

std::vector<std::string> PersistenceStruct::getPilotFileNames()
{
	std::vector<std::string> pilotFileNames;
	std::string path = PERSISTENT_PATH;
	for (const auto& entry : fs::directory_iterator(path)) {
		auto fileName = entry.path().filename().generic_string();
		// Make sure fileName has a suffix of .pilot
		int index = fileName.find_last_of('.');
		std::string suffix = fileName.substr(
		pilotFileNames.push_back(fileName);
	}

	return pilotFileNames;

}

std::vector<std::string> PersistenceStruct::getShipFileNames()
{
	std::vector<std::string> shipFileNames;
	std::string path = PERSISTENT_PATH;
	for (const auto& entry : fs::directory_iterator(path)) {
		auto fileName = entry.path().filename().generic_string();
		// Make sure fileName has a suffix of .ship
		shipFileNames.push_back(fileName);
	}

	return shipFileNames;
}
