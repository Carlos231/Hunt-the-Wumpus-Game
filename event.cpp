/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "event.h"

/*********************************************************************
** FUNCTION: event
** DESCRIPTION: sets message and event letter
** PARAMETERS: none
** PRE-CONDITIONS: variables exist
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
Event::Event(){
	message = " ";
	eventletter = ' ';
}
/*********************************************************************
** FUNCTION: get_message
** DESCRIPTION: gets message
** PARAMETERS:  none
** PRE-CONDITIONS: message exists
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
string Event::get_message(){
	return message;
}
/*********************************************************************
** FUNCTION: output_message
** DESCRIPTION: outputs the events message
** PARAMETERS: none
** PRE-CONDITIONS: message set
** POST-CONDITIONS: nothing changes
** RETURNS: nothing
*********************************************************************/
void Event::output_message(){
	cout << message << endl;
}