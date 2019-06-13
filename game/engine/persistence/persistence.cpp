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
		// Get file name
		auto fileName = entry.path().filename().generic_string();

		// Make sure fileName has a suffix of .pilot
		int index = fileName.find_last_of('.');
		std::string suffix = fileName.substr(index+1, fileName.length());
		if (suffix == "pilot") {
			// Add filename to the return list
			pilotFileNames.push_back(fileName);
		}
	}

	return pilotFileNames;

}

std::vector<std::string> PersistenceStruct::getShipFileNames()
{
	std::vector<std::string> shipFileNames;
	std::string path = PERSISTENT_PATH;
	for (const auto& entry : fs::directory_iterator(path)) {
		auto fileName = entry.path().filename().generic_string();

		// Make sure fileName has a suffix of .pilot
		int index = fileName.find_last_of('.');
		std::string suffix = fileName.substr(index + 1, fileName.length());
		if (suffix == "ship") {
			// Add filename to the return list
			shipFileNames.push_back(fileName);
		}
	}

	return shipFileNames;
}
