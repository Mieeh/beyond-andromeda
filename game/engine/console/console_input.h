#pragma once

#include<stdio.h>
#include<iostream>
#include<numeric>

struct ConsoleInput {
	// Get single input character
	static char GetCharacter(std::string prompt = "") {
		// Display prompt
		std::cout << prompt;
		
		// Input
		char x;
		std::cin.get(x);
		
		// Reset input buffer related
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		
		return x;
	}

	static std::string GetString(std::string prompt = "") {
		std::cout << prompt;

		std::string x;
		std::getline(std::cin, x);

		//std::cin.clear();
		//std::cin.ignore(INT_MAX, '\n');

		return x;
	}
};