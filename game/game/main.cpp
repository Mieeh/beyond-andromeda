#include<iostream>

/*
#include"../engine/console/console_beautifier.h"
#include"../engine/color.h"
#include"../engine/persistence/persistence.h"
*/

#include"console_part.h"
#include"main_part.h"

#include"../engine/persistence/persistence.h"
#include"../engine/persistence/binary_stream.h"
#include"../engine/pilot.h"
#include"../engine/ship.h"

/*
#include "../engine/imgui/imgui.h"
#include "../engine/imgui/imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
*/

int main() {

	BinaryStream bs;

	Current::Get()->ship = bs.deserializeShip("13.ship");
	Current::Get()->pilot = bs.deserializePilot("1.pilot");

	ConsolePart consolePart;
	MainPart mainPart;
	consolePart.nextPart = &mainPart;
	
	//consolePart.enter();
	mainPart.enter();

	return 0;
}
