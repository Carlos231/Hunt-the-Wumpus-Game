/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "pit.h"

/*********************************************************************
** FUNCTION: pit
** DESCRIPTION: sets message and event letter
** PARAMETERS: none
** PRE-CONDITIONS: variables exist
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
Pit::Pit(){
	message = "You feel a breeze.";
	eventletter = 'p';
}
/*********************************************************************
** FUNCTION: get_message
** DESCRIPTION: gets message
** PARAMETERS:  none
** PRE-CONDITIONS: message exists
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
string Pit::get_message(){
	return message;
}