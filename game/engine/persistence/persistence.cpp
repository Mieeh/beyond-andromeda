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
		pilotFileNames.push_back(fileName);
	}

	return pilotFileNames;

}
