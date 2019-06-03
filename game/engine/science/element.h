#pragma once

#include<string>
#include<vector>
#include<iostream>

#define NUMBER_OF_ELEMENTS 17

enum ElementType {
	CORE = 0,
	GAS = 1,
	REACTANT = 2,
	CONSTRUCTION = 3
};

enum ElementIndex {
	H = 0,
	O = 1,
	C = 2,
	N = 3,
	P = 4,
	S = 5,
	Fe = 6,
	Ti = 7,
	Re = 8,
	Pt = 9,
	Si = 10,
	Ig = 11,
	Gl = 12,
	Xe = 13,
	Ar = 14,
	He = 15,
	Ne = 16
};

struct Element {
	std::string elementName;
	ElementType elementType;

	// Operators
	friend std::ostream & operator << (std::ostream& out, const Element& e);
};

static Element master_element_table[NUMBER_OF_ELEMENTS];

// Fill elements list
static void createElements() {
	master_element_table[H] = { "Helium", ElementType::CORE };
	master_element_table[O] = { "Oxygen", ElementType::CORE };
	master_element_table[C] = { "Carbon", ElementType::CORE };
	master_element_table[N] = { "Nitrogen", ElementType::CORE };
	master_element_table[P] = { "Phosphorus", ElementType::CORE };
	master_element_table[S] = { "Sulfur", ElementType::CORE };

	master_element_table[Fe] = { "Iron", ElementType::CONSTRUCTION };
	master_element_table[Ti] = { "Titanium", ElementType::CONSTRUCTION };
	master_element_table[Re] = { "Rhenium", ElementType::CONSTRUCTION };
	master_element_table[Pt] = { "Platinum", ElementType::CONSTRUCTION };

	master_element_table[Si] = { "Simul", ElementType::REACTANT };
	master_element_table[Ig] = { "Ignis", ElementType::REACTANT };
	master_element_table[Gl] = { "Glacies", ElementType::REACTANT };

	master_element_table[Xe] = { "Xenon", ElementType::GAS };
	master_element_table[Ar] = { "Argon", ElementType::GAS };
	master_element_table[He] = { "Helium", ElementType::GAS };
	master_element_table[Ne] = { "Neon", ElementType::GAS };
}

// Elementype to string
static std::string elementTypeToString(ElementType type) {
	switch (type) {
	case ElementType::CONSTRUCTION:
		return "Construction";
		break;
	case ElementType::CORE:
		return "Core";
		break;
	case ElementType::GAS:
		return "Gas";
		break;
	case ElementType::REACTANT:
		return "Reactant";
		break;
	}
}