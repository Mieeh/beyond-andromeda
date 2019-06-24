#include "ship.h"

Ship::Ship()
{
	// Set everything to zero
	shipStructure = { 0, 0, 0 };
	hp = 0;
}

Ship::Ship(ShipStructure shipStructure)
{
	this->shipStructure = shipStructure;

	// Calculate hp
	hp = MAX_HP(shipStructure.hull); // Temporary @
}
