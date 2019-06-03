#include<iostream>

#include"../engine/science/element.h"

int main() {

	createElements();

	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		std::cout << master_element_table[i] << std::endl;
	}

	return 0;
}