#include "console_beautifier.h"

#include"../color.h"
#include"../current.h"
#include"../ship.h"
#include"../pilot.h"

#include"../sfml/sfml_audio_singleton.h"

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

void ConsoleBeautifier::resetColors()
{
	// Black with white foreground
	setConsoleColor(CONSOLE_COLOR::WHITE, CONSOLE_COLOR::BLACK);
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

void ConsoleBeautifier::printWithDelay(const std::string & string, int time, PrintBehaviours behaviours)
{
	int delay = time / string.length();
	for (auto& c : string) {

		if (behaviours == PrintBehaviours::RANDOM_CHAR_COLOR) {
			setRandomForegroundColor();
		}

		std::cout << c; // output the actual char
		SFMLAudio::Get()->playSFX("temp_console_sfx1.ogg", 7); // sfx
		pause(delay); // wait for some time before outputting the next char
	}

	if (behaviours == PrintBehaviours::RANDOM_CHAR_COLOR) {
		resetColors();
	}
}

void ConsoleBeautifier::centerText(const std::string & string)
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
	int spaces = (csbi.dwSize.X/2) - (string.length()/2) - 1; // How many spaces to get to the center
	for (int i = 0; i < spaces; i++) {
		std::cout << " ";
	}
	std::cout << string << std::endl;

#endif
}

void ConsoleBeautifier::farRightText(std::string* str_list, size_t element_count)
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	// How many spaces do we go?
	int longest_word = str_list[0].length();
	for (int i = 1; i < element_count; i++) {
		if (str_list[i].length() > longest_word) {
			longest_word = str_list[i].length();
		}
	}

	static float PADDING = 1.3f;
	int spaces = csbi.dwSize.X - longest_word*PADDING;

	// Output everything now that we know how many spaces we need to go
	for (int i = 0; i < element_count; i++) {
		// Output all the spaces
		for (int i = 0; i < spaces; i++)
			std::cout << " ";
		std::cout << str_list[i] << std::endl;
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

	// Output the permanents after clearing
	setConsoleColor(CONSOLE_COLOR::PINK, CONSOLE_COLOR::BLACK);
	centerText("BEYOND ANDROMEDA");
	resetColors();
	
	// info
	std::string words[] = { "PILOT", "Name: " + Current::Get()->pilot.name, 
		"",
		"SHIP",
		"HP: " + std::to_string(Current::Get()->ship.hp),
		"Hull: " + std::to_string(Current::Get()->ship.shipStructure.hull),
		"Engine: " + std::to_string(Current::Get()->ship.shipStructure.engine),
		"Analyzer: " + std::to_string(Current::Get()->ship.shipStructure.analyzer)
	};

	// Output shit
	farRightText(words, sizeof(words) / sizeof(std::string));

	resetColors();
}

void ConsoleBeautifier::pause(int ms)
{
	// Wait
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(ms));
}
