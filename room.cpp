/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "room.h"

/*********************************************************************
** FUNCTION: room
** DESCRIPTION: sets variables to NULL states
** PARAMETERS: none
** PRE-CONDITIONS: variables exist
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
Room::Room(){
	event = ' ';
	inRoom = NULL;
	player = 'x';
	srand (time(NULL));
}
/*********************************************************************
** FUNCTION: get_event
** DESCRIPTION: returns event
** PARAMETERS: none
** PRE-CONDITIONS: event set
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
char Room::get_event(){
	return event;
}
/*********************************************************************
** FUNCTION: get_player
** DESCRIPTION: returns player
** PARAMETERS: none
** PRE-CONDITIONS: variable set
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
char Room::get_player(){
	return player;
}
/*********************************************************************
** FUNCTION: set_event
** DESCRIPTION: depending on which event wanted, will set that event
** PARAMETERS: char event
** PRE-CONDITIONS: empty room pointer
** POST-CONDITIONS: pointer to child event class
** RETURNS: nothing
*********************************************************************/
void Room::set_event(char event){
	this->event = event;
	if (event == 'w'){
		inRoom = new Wumpus;
	}
	else if (event == 'b'){
		inRoom = new Bats;
	}
	else if (event == 'p'){
		inRoom = new Pit;
	}
	else if (event == 'g'){
		inRoom = new Gold;
	}
	else if (event == ' '){
		inRoom = NULL;
	}
}
/*********************************************************************
** FUNCTION: output_message
** DESCRIPTION: outputs the message
** PARAMETERS: none
** PRE-CONDITIONS: message made and inRoom pointing to event
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
string Room::get_messages(){
	return inRoom->get_message();
}

/*********************************************************************
** FUNCTION: Room
** DESCRIPTION: deconstructor
** PARAMETERS: none
** PRE-CONDITIONS: inRoom made
** POST-CONDITIONS: inRoom wiped
** RETURNS: nothing
*********************************************************************/
Room::~Room(){
	delete [] inRoom;
}