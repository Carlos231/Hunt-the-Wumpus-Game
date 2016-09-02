/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

class Room {
	protected:
		Event *inRoom; //each room has 1 at most
		char event;
		char player; 

	public:	
		//constructor
		Room();
		
		//accessors
		char get_event();
		char get_player();
		string get_messages();
		
		//mutators
		void set_player(char);
		void set_event(char);
		void set_Wumpus();
		
		//deeconstructor
		~Room();
};

#endif