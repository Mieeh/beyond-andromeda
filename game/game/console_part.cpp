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
		cb.printWithDelay("Options\n1. Pilot Selection\n", 600);
		cb.printWithDelay("2. Pilot Creation", 450);
		cb.printWithDelay("3. Ship Selection\n", 450);
		cb.printWithDelay("4. Launch Into Space\n", 450, PrintBehaviours::RANDOM_CHAR_COLOR);

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
		auto& pilotFiles = persistent.getPilotFileNames();

		switch (choice) {
		case 1:
			juiceLoad("Loading pilots");

			if(!pilotFiles.empty()) {
				// List all pilots
				for (int i = 0; i < pilotFiles.size(); i++) {
					cb.printWithDelay("- " + pilotFiles.at(i) + "\n", 500);
				}
				
				// Input for option
				std::string choice = ConsoleInput::GetString(">");
				bool validChoice = false;
				for (int i = 0; i < pilotFiles.size(); i++)
				{
					if (pilotFiles.at(i) == choice) {
						validChoice = true;
						break;
					}
				}

				if (validChoice) {

				}
			}
			else {
				cb.printWithDelay("No pilots found!", 600);
			}
			break;
		case 2:
			createPilot();
			break;
		case 3:
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
