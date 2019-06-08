#pragma once

#if defined(_WIN32)
#include<Windows.h>
#endif

#include<string>

/*
Utility struct to abstract away os specifik code from game + some other console related stuff
*/

enum PrintBehaviours {
	NONE,
	RANDOM_CHAR_COLOR
};

struct ConsoleBeautifier {
	ConsoleBeautifier();

	/*
	Values for the parameters can be taken from Color.h for ease of use
	*/
	void setConsoleColor(int foreground, int background);

	/*
	Reseting to default terminal colors
	*/
	void resetColors();

	/*
	Setters for the different colors
	*/
	void setRandomForegroundColor();
	void setRandomBackgroundColor();

	/*
	std:cout's p\string with p\time taken to do it
	*/
	void printWithDelay(const std::string& string, int time = 1000, PrintBehaviours behaviours = PrintBehaviours::NONE); // Default time of 100 milliseconds

	/*
	Text aligning to different positions in the console
	*/
	void centerText(const std::string& string);
	void farRightText(const std::string& string, std::string* appends = nullptr, size_t appends_size = 0);

	/*
	Clears console
	*/
	void clearConsole();

	/*
	Pause
	*/
	void pause(int ms);

	int currentForeground, currentBakcground;
	// Window's specific console handle! 
#if defined(_WIN32)
	HANDLE hndl;
#endif
};