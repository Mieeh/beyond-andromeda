#pragma once

#include"game_part.h"

#include"../engine/console/console_beautifier.h"
#include"../engine/persistence/persistence.h"

struct ConsolePart : GamePart {

	/*
	Methods
	*/
	void enter() override;

	/*
	Juicy
	*/
	void juiceLoad(std::string juiceString);

	/*
	Members
	*/
	ConsoleBeautifier cb;
	PersistenceStruct persistent;
};