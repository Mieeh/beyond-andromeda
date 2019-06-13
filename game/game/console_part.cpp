#include "console_part.h"

#include"../engine/console/console_input.h"
#include"../engine/color.h"

#include<iostream>
#include<string>
#include<conio.h>
#include<sstream>

void ConsolePart::enter(){

	cb.resetColors();
	cb.clearConsole();

	// Welcome message
	cb.printWithDelay("Welcome to Beyond Andromeda Incorporated, your gateway to the stars through cutting edge tech\nPress any button to continue...", 1750);
	_getch();
	cb.clearConsole();

	// GOTO MENU
	menu();
}

void ConsolePart::menu()
{
	cb.clearConsole();

	bool running = true;

	while (running) {

		cb.clearConsole();

		// Print options
		cb.setConsoleColor(CONSOLE_COLOR::RED, CONSOLE_COLOR::BLACK);
		cb.printWithDelay("1. Pilot Selection\n", 600);
		cb.printWithDelay("2. Pilot Creation\n", 450);
		cb.setConsoleColor(CONSOLE_COLOR::GREEN, CONSOLE_COLOR::BLACK);
		cb.printWithDelay("3. Ship Creation\n", 450);
		cb.printWithDelay("4. Launch Into Space\n", 450, PrintBehaviours::RANDOM_CHAR_COLOR);
		cb.resetColors();

		// Input for option
		int choice = 0;
		while (true) {
			auto input = ConsoleInput::GetString(">");
			// Convert to number safely
			std::stringstream sstream(input);
			if (sstream >> choice)
				break;
			cb.printWithDelay("Please enter a valid choice!\n");
		}

		// Clear and evaluate choice
		cb.clearConsole();

		// Get pilots files for later use
		auto pilotFiles = persistent.getPilotFileNames();

		switch (choice) {
		case 1:
			juiceLoad("Loading pilots");

			if(!pilotFiles.empty()) {
				// List all pilots
				for (int i = 0; i < pilotFiles.size(); i++) {
					cb.printWithDelay("- " + pilotFiles.at(i) + "\n", 500);
				}
				
				// Input for option
				std::string pilot_choice = ConsoleInput::GetString(">");
				bool validChoice = false;
				for (int i = 0; i < pilotFiles.size(); i++)
				{
					if (pilotFiles.at(i) == pilot_choice) {
						validChoice = true;
						break;
					}
				}

				if (validChoice) {
					// Select pilot
					Current::Get()->pilot = binary_stream.deserializePilot(pilot_choice);
				}
				else {
					cb.printWithDelay("No pilot with that identification number found", 700);
					cb.pause(300);
				}
			}
			else {
				cb.printWithDelay("No pilots found!", 600);
				cb.pause(400);
			}
			break;
		case 2:
			createPilot();
			break;
		case 3:
			createShip();
			break;
		case 4:
			int i = 1;
			while (true) {
				i += 2;
				cb.setRandomBackgroundColor();
				cb.setRandomForegroundColor();
				std::cout << rand() % 10;
				cb.pause(1000/i);
			}
			break;
		}
	}

	exitMessageCall();
}

void ConsolePart::juiceLoad(std::string juiceString)
{
	cb.printWithDelay(juiceString, 500);
	
	for (int i = 0; i < 3; i++) {
		cb.pause(600/3);
		cb.printWithDelay("...", 600);

		// Remove 3 dots
		std::cout << "\b \b";
		std::cout << "\b \b";
		std::cout << "\b \b";
	}

	cb.clearConsole();
}

void ConsolePart::exitMessageCall()
{
	cb.printWithDelay("We thank you for using our services\n", 750);
	juiceLoad("Exiting");
}

void ConsolePart::createPilot()
{
	cb.clearConsole(); // Clear console

	cb.printWithDelay("Is this your first time creating a pilot? [Y/N]\n");
	// Get input for yes or no for the above question
	char in = ConsoleInput::GetCharacter(">");
	if (in == 'Y' || in == 'y') {
		// Describe pilot
	}
	
	cb.printWithDelay("Now let's create your pilot");
	cb.pause(500);
	cb.clearConsole();

	cb.printWithDelay("Enter a name\n");
	std::string name = ConsoleInput::GetString(">");

	cb.printWithDelay("Enter a identification number for this pilot\n");
	int id = 0;
	while (true) {
		auto input = ConsoleInput::GetString(">");
		// Convert to number safely
		std::stringstream sstream(input);
		if (sstream >> id)
			break;
		cb.printWithDelay("Please enter a valid identification number!\n");
	}

	// Set current pilot
	Current::Get()->pilot.name = name;

	// Serialize current pilot
	binary_stream.serializePilot(id, Current::Get()->pilot);
}

void ConsolePart::createShip()
{
	cb.clearConsole(); // Clear screen

	cb.printWithDelay("Is this your first time creating a ship? [Y/N]\n");
	// Get input for yes or no for the above question
	char in = ConsoleInput::GetCharacter(">");
	if (in == 'Y' || in == 'y') {
		// Describe a ship
	}

	cb.clearConsole();

	int points_to_spend = 10;
	int hull_points, analyzer_points, engine_points;
	int temp = 0;

	while (points_to_spend > 0) {

		// Reset points
		points_to_spend = 10;
		hull_points = 0;
		analyzer_points = 0;
		engine_points = 0;

		// Ask for hull 
		cb.printWithDelay("Points left: " + std::to_string(points_to_spend) + "\n", 600);
		cb.printWithDelay("Hull, affects how strong your ship is [0-10][1/3]\n");
		while (true) {
			auto input = ConsoleInput::GetString(">");
			// Convert to number safely
			std::stringstream sstream(input);
			if (sstream >> temp) {
				if (temp >= 0 && temp <= points_to_spend)
					break;
			}
			cb.printWithDelay("Please enter a valid value!\n");
		}
		hull_points = temp;
		points_to_spend -= temp;

		// Ask for analyzer 
		cb.printWithDelay("Points left: " + std::to_string(points_to_spend) + "\n", 600);
		cb.printWithDelay("Analyzer, affects how good your ship is at scanning foreign objects [0-10][2/3]\n");
		while (true) {
			auto input = ConsoleInput::GetString(">");
			// Convert to number safely
			std::stringstream sstream(input);
			if (sstream >> temp) {
				if (temp >= 0 && temp <= points_to_spend)
					break;
			}
			cb.printWithDelay("Please enter a valid value!\n");
		}
		analyzer_points = temp;
		points_to_spend -= temp;

		// Ask for engine
		cb.printWithDelay("Points left: " + std::to_string(points_to_spend) + "\n", 600);
		cb.printWithDelay("Engine, affects ship speed and ability to move through space [0-10][3/3]\n");
		while (true) {
			auto input = ConsoleInput::GetString(">");
			// Convert to number safely
			std::stringstream sstream(input);
			if (sstream >> temp) {
				if (temp >= 0 && temp <= points_to_spend)
					break;
			}
			cb.printWithDelay("Please enter a valid value!\n");
		}
		engine_points = temp;
		points_to_spend -= temp;

		if (points_to_spend > 0) {
			cb.printWithDelay("You still have " + std::to_string(points_to_spend) + " points left to spend!\n");
			cb.printWithDelay("Would you like to reset and try again? [Y/N]\n");
			// Get input for yes or no for the above question
			char in = ConsoleInput::GetCharacter(">");
			if (in == 'N' || in == 'n') {
				break;
			}
		}

		// get ship ID
		cb.printWithDelay("Enter a identification number for this ship\n");
		int id = 0;
		while (true) {
			auto input = ConsoleInput::GetString(">");
			// Convert to number safely
			std::stringstream sstream(input);
			if (sstream >> id)
				break;
			cb.printWithDelay("Please enter a valid identification number!\n");
		}

		// Construct ship
		ShipStructure structure;
		structure.analyzer = analyzer_points;
		structure.engine = engine_points;
		structure.hull = hull_points;
		Ship ship = Ship(structure);

		// Set current ship
		Current::Get()->ship = ship;

		// Serialize current ship!
		binary_stream.serializeShip(id, Current::Get()->ship);
	}
}