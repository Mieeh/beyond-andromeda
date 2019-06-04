#include "console_beautifier.h"

#include"../color.h"

#include<string>
#include<chrono> // Crossplatform, we use for delayed print functionality
#include<iostream>
#include<thread>

#if defined(__APPLE__)
#include <unistd.h>
#include <term.h>
#endif

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

void ConsoleBeautifier::printWithDelay(const std::string & string, int time) 
{
	int delay = time / string.length();
	for (auto& c : string) {
		std::cout << c;
		// Wait
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(delay));
	}
}

void ConsoleBeautifier::clearConsole()
{
#if defined(_WIN32)
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
#elif defined(__APPLE__)
	if (!cur_term)
	{
		int result;
		setupterm(NULL, STDOUT_FILENO, &result);
		if (result <= 0) return;
	}

	putp(tigetstr("clear"));
#endif
}
