#include "console_part.h"

#include<iostream>
#include<string>

void ConsolePart::enter(){
	// Welcome message
	cb.printWithDelay("Welcome to Beyond Andromeda Incorporated, your gateway to the stars through cutting edge tech\nPress any button to continue...", 1750);
	std::cin.get();
	cb.clearConsole();

	/*
	Juice
	*/
	juiceLoad("Loading pilots");

	// Look for pilot files
	auto& pilotFiles = persistent.getPilotFileNames();
	if (pilotFiles.empty()) {
		cb.printWithDelay("We can't seem to find any existing pilot for this account...\n", 1000);
		cb.printWithDelay("Would you like to create a pilot? [Y/N]\n");

		std::string input;
		std::cin >> input;
		if(std::string::)
	}
}

void ConsolePart::juiceLoad(std::string juiceString)
{
	cb.printWithDelay(juiceString, 500);
	cb.printWithDelay("...", 1000);
	cb.clearConsole();
}
