/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

//absract pure virtual class
class Event{
	protected:
		int locationx, locationy;
		string message;
		char eventletter;
	public:
		Event();
		virtual string get_message();
		virtual void output_message();
};

#endif