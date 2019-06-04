#pragma once

#if defined(_WIN32)
#include<Windows.h>
#endif

#include<string>

struct ConsoleBeautifier {
	ConsoleBeautifier();

	/*
	Values for the parameters can be taken from Color.h for ease of use
	*/
	void setConsoleColor(int foreground, int background);

	/*
	Setters for the different colors
	*/
	void setRandomForegroundColor();
	void setRandomBackgroundColor();

	/*
	std:cout's p\string with p\time taken to do it
	*/
	void printWithDelay(const std::string& string, int time = 1000); // Default time of 100 milliseconds

	/*
	Clears console
	*/
	void clearConsole();

	int currentForeground, currentBakcground;
	// Window's specific console handle! 
#if defined(_WIN32)
	HANDLE hndl;
#endif
};