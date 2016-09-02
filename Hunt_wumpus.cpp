/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include <iostream>
#include <stdlib.h> //atoi
#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
	Game test;
	int size = atoi (argv[1]);
	
	if (size <= 4){
		while (size <= 4){
			cout << "Error, you must enter a size greater than 4. Try again: ";
			cin >> size;
		}
	}
	
	system("clear");
	cout << "Welcome to Hunt the Wumpus game!" << endl;
	test.run_game(size);
	
	return 0;
}