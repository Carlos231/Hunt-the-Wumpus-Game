/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

//child class
class Wumpus : public Event{
	protected:
		string message;
		bool alive;
	public:	
		Wumpus();
		
		string get_message();
		bool get_alive();
};

#endif