#pragma once

#include"game_part.h"

#include"../engine/console/console_beautifier.h"
#include"../engine/persistence/persistence.h"
#include"../engine/current.h"

struct ConsolePart : GamePart {

	/*
	Methods
	*/
	void enter() override;

	/*
	Base menu for console part
	*/
	void menu();

	/*
	Used for exiting console part
	*/
	void exitMessageCall();

	/*
	Pilot related functions
	*/
	void createPilot();

	/*
	Ship related functions
	*/
	void createShip();

	/*
	Juicy
	*/
	void juiceLoad(std::string juiceString);

	/*
	Members
	*/
	ConsoleBeautifier cb;
	PersistenceStruct persistent;
	BinaryStream binary_stream;
};