/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "bats.h"

/*********************************************************************
** FUNCTION: bats
** DESCRIPTION: sets message and event letter
** PARAMETERS: none
** PRE-CONDITIONS: variables exist
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
Bats::Bats(){
	message = "You hear wings flapping.";
	eventletter = 'b';
}
/*********************************************************************
** FUNCTION: get_message
** DESCRIPTION: gets message
** PARAMETERS:  none
** PRE-CONDITIONS: message exists
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
string Bats::get_message(){
	return message;
}
/*********************************************************************
** FUNCTION:
** DESCRIPTION: 
** PARAMETERS: 
** PRE-CONDITIONS: 
** POST-CONDITIONS: 
** RETURNS: 
*********************************************************************/
void Bats::output_message(){
	cout << message << endl;
}
