/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "gold.h"

/*********************************************************************
** FUNCTION: gold
** DESCRIPTION: sets message and event letter
** PARAMETERS: none
** PRE-CONDITIONS: variables exist
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
Gold::Gold(){
	message = "You see a glimmer nearby.";
	eventletter = 'g';
}
/*********************************************************************
** FUNCTION: get_message
** DESCRIPTION: gets message
** PARAMETERS:  none
** PRE-CONDITIONS: message exists
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
string Gold::get_message(){
	return message;
}