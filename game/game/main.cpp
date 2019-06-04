#include<iostream>

#include"../engine/console/console_beautifier.h"
#include"../engine/color.h"

#include<random>

int main() {

	ConsoleBeautifier cb;

	cb.setConsoleColor(CONSOLE_COLOR::BLACK, CONSOLE_COLOR::DARK_RED);

	while (true) {
		cb.setRandomForegroundColor();
		std::cout << rand() % 100;
	}

	cb.setConsoleColor(CONSOLE_COLOR::CYAN, CONSOLE_COLOR::WHITE);

	std::cout << "Stylish white with cyan text" << std::endl;

	system("pause>null");
	return 0;
}
