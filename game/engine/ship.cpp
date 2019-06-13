#include "ship.h"

Ship::Ship(ShipStructure shipStructure)
{
	this->shipStructure = shipStructure;

	// Calculate hp
	hp = shipStructure.hull * 3; // Temporary @
}
