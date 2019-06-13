#pragma once

#include<vector>

#include"binary_stream.h"

struct PersistenceStruct {
	
	std::vector<std::string> getPilotFileNames();
	std::vector<std::string> getShipFileNames();

};