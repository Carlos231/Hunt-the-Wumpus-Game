/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "room.h"

using namespace std;

class Game : Room{
	protected:
		Room **rooms;//array of rooms
		int gridSize, arrows, numGold;
		//starting position location (also rope location)
		int player_start_x, player_start_y, player_position_x, player_position_y, player_action;
		char movement;
		bool gameover, won, startingOver, wumpusdead;
	public:	
		//constructors
		Game();
		
		//mutators
		void set_gridSize();
		void set_rooms();
		void set_event_in_rooms();
		void set_movement();
		void set_starting_position();
		int set_random_position();
		void adjust_arrows();
		bool inbounds(int, int);
		
		
		//accessors
		char get_movement();
		void get_player_action();
		bool get_won();
		
		//deconstructor
		~Game();
		
		//game functions
		void run_game(int);
		void output_grid();
		void move_player();
		void check_event();
		void menu();
		void output_messages();
		void shoot_arrow();
		void endgame();
		void check_if_won();
};

#endif