/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef BATS_H
#define BATS_H

#include "event.h"

//child class
class Bats : public Event{
	protected:
		//message
		string message;
	public:	
		Bats();
		string get_message();
		void output_message();
};

#endif
