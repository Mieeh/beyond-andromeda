#pragma once

#if defined(_WIN32)

#include<Windows.h>

#endif

struct ConsoleBeautifier {
	ConsoleBeautifier();

	/*
	Values for the parameters can be taken from Color.h for ease of use
	*/
	void setConsoleColor(int foreground, int background);

	/*
	
	*/


	int currentForeground, currentBakcground;
#if defined(_WIN32)
	HANDLE hndl;
#endif
};