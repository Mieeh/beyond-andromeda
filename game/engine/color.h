#pragma once

struct Color {
	float r, g, b;
};

/*
Console color macros, windows & mac
*/

#if defined(_WIN32)

typedef enum CONSOLE_COLOR {
	BLACK = 0,
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_PINK = 5,
	DARK_YELLOW = 6,
	DARK_WHITE = 7,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15
};

#elif defined(__APPLE__)

enum CONSOLE_COLOR {
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37
};

#endif