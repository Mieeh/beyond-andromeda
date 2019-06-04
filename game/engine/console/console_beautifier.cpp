#include "console_beautifier.h"

#include"../color.h"

#include<string>

ConsoleBeautifier::ConsoleBeautifier()
{
	currentBakcground = CONSOLE_COLOR::BLACK;
	currentForeground = CONSOLE_COLOR::WHITE;

#if defined(_WIN32)
	hndl = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}

void ConsoleBeautifier::setConsoleColor(int foreground, int background)
{
	currentForeground = foreground;
	currentBakcground = background;

#if defined(_WIN32)

	SetConsoleTextAttribute(hndl, foreground + background * 16);

#elif defined(__APPLE__)

	std::string fground = std::to_string(foreground);
	std::string bground = std::to_string(background+10);
	std::cout << "\x1b[" << fground << ";" << bground << "m";

#endif
}

void ConsoleBeautifier::setRandomForegroundColor()
{
#if defined(_WIN32)
	int randNum = rand() % (CONSOLE_COLOR_END - CONSOLE_COLOR_START + 1) + CONSOLE_COLOR_START;
	currentForeground = randNum;
	SetConsoleTextAttribute(hndl, currentForeground + currentBakcground * 16);
#elif defined(__APPLE__)

#endif
}

void ConsoleBeautifier::setRandomBackgroundColor()
{
#if defined(_WIN32)
	int randNum = rand() % (CONSOLE_COLOR_END - CONSOLE_COLOR_START + 1) + CONSOLE_COLOR_START;
	currentBakcground = randNum;
	SetConsoleTextAttribute(hndl, currentForeground + currentBakcground * 16);
#elif defined(__APPLE__)

#endif
}
