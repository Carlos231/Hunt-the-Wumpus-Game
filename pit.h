/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef PIT_H
#define PIT_H

#include "event.h"

//child class
class Pit : public Event{
	protected:
		//message
		string message;
	public:	
		Pit();
		string get_message();
};
#endif