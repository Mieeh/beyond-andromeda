#include<iostream>

#include"../engine/console/console_beautifier.h"
#include"../engine/color.h"

int main() {

	ConsoleBeautifier cb;

	cb.setConsoleColor(CONSOLE_COLOR::RED, CONSOLE_COLOR::DARK_RED);

	std::cout << "Red text with red background" << std::endl;

	cb.setConsoleColor(CONSOLE_COLOR::CYAN, CONSOLE_COLOR::WHITE);

	std::cout << "Stylish white with cyan text" << std::endl;

	centerstring("Middle of the screen!");

	system("pause>null");
	return 0;
}
