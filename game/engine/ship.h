#pragma once

#include<string>
#include<vector>

struct ShipStructure {
	int hull;      // Some lvalue used when evalutaing hull related calcs for the ship
	int analyzer;  // Some lvalue used when evaluating things related to analyzing when using the ship
	int engine;    // Some lvalue used when evaluating engine related things for the ship
};

struct ShipInventory {
	std::vector<int> element_list;
};

// Main struct for a ship, this is serialized 
struct Ship {
	static bool selected;
	int hp; // Call this integrity in-game, it's a value for how damaged the ship is
	ShipStructure shipStructure;
	ShipInventory shipInventory;
};