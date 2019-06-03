#include "console_beautifier.h"

#include<string>

ConsoleBeautifier::ConsoleBeautifier()
{
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
