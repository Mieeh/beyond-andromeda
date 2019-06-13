#include<iostream>

#include"../engine/console/console_beautifier.h"
#include"../engine/color.h"

#include"../engine/persistence/persistence.h"

#include"console_part.h"

#include<random>
#include<stdio.h>

int main() {
		
	ConsolePart consolePart;
	consolePart.enter();
	consolePart.nextPart = &consolePart;

	system("pause>null");
	return 0;
}
