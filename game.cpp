/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#include "game.h"

/*********************************************************************
** FUNCTION: Game
** DESCRIPTION: sets up all of the variables
** PARAMETERS: none
** PRE-CONDITIONS: variables made
** POST-CONDITIONS: variables updated with NULL states
** RETURNS: nothing
*********************************************************************/
//constructor
Game::Game(){
	//*rooms = NULL;
	gridSize = 0;
	arrows = 3;
	player_action = 0;
	numGold = 0;
	player_start_x = player_start_y = player_position_x = player_position_y = 0;
	movement = 'o';
	gameover = false;
	won = false;
	startingOver = false;
	wumpusdead = false;
	srand (time(NULL));
}
/*********************************************************************
** FUNCTION: set_gridSize
** DESCRIPTION: gets size of grid size 
** PARAMETERS: none
** PRE-CONDITIONS: gridsize variable exists
** POST-CONDITIONS: new value for gridsize
** RETURNS: nothing
*********************************************************************/
//mutators
void Game::set_gridSize(){ //later through command line arguments
	cout << "Enter grid size: ";
	cin >> gridSize;
}
/*********************************************************************
** FUNCTION: set_rooms
** DESCRIPTION: array of rooms made
** PARAMETERS: none
** PRE-CONDITIONS: rooms pointer blank
** POST-CONDITIONS: rooms array made with gridsize
** RETURNS: nothing
*********************************************************************/
//make the grid
void Game::set_rooms(){
	rooms = new Room *[gridSize];
	for (int i = 0; i < gridSize; ++i)
		rooms[i] = new Room[gridSize];
}
/*********************************************************************
** FUNCTION: set_movement
** DESCRIPTION: asks for where player wants to move to
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::set_movement(){
	cout << "      w - up " << endl;
	cout << " a - left    d - right" << endl;
	cout << "      s - down" << endl;
	cin >> movement;
}
/*********************************************************************
** FUNCTION: set_random_position
** DESCRIPTION: returns random number from 0 - gridsize
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: num
*********************************************************************/
int Game::set_random_position(){
	int num = rand() % gridSize;
	return num;
}
/*********************************************************************
** FUNCTION: set_event_in_rooms
** DESCRIPTION: puts random events in different locations
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::set_event_in_rooms(){
	rooms[player_start_x][player_start_y].set_event('x');
	//set random location for gold
	rooms[set_random_position()][set_random_position()].set_event('g');
	//set random location for Wumpus
	rooms[set_random_position()][set_random_position()].set_event('w');
	//set random location for Bats
	rooms[set_random_position()][set_random_position()].set_event('b');
	//set random location for Bats
	rooms[set_random_position()][set_random_position()].set_event('b');
	//set random location for pits
	rooms[set_random_position()][set_random_position()].set_event('p');
	//set random location for pits
	rooms[set_random_position()][set_random_position()].set_event('p');
}
/*********************************************************************
** FUNCTION: set_starting_position
** DESCRIPTION: sets up the starting position for player
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: variables updated
** RETURNS: nothing
*********************************************************************/
void Game::set_starting_position(){
	player_position_x = player_start_x = set_random_position();
	player_position_y = player_start_y = set_random_position();
	cout << "Player start: " << player_start_x << " " << player_start_y << endl;
}
/*********************************************************************
** FUNCTION: adjust_arrows
** DESCRIPTION: checks to see if have any arrows, subtracts one when called
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: variable changed
** RETURNS: nothing
*********************************************************************/
//for when shoot an arrow
void Game::adjust_arrows(){
	if (arrows <= 0){
		cout << "You do not have any more arrows!" << endl;
		gameover = true;
	}
	else arrows--;
}

/*********************************************************************
** FUNCTION: get_movement
** DESCRIPTION: returns movement
** PARAMETERS: none
** PRE-CONDITIONS: none 
** POST-CONDITIONS: none
** RETURNS: movement
*********************************************************************/
char Game::get_movement(){
	return movement;
}
/*********************************************************************
** FUNCTION: get_won
** DESCRIPTION: returns movement
** PARAMETERS: none
** PRE-CONDITIONS: none 
** POST-CONDITIONS: none
** RETURNS: movement
*********************************************************************/
bool Game::get_won(){
	return won;
}
/*********************************************************************
** FUNCTION: output_grid
** DESCRIPTION: outputs entire grid
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::output_grid(){
	for (int i = 0; i < gridSize; ++i){
		for (int j = 0; j < gridSize; ++j){
			cout << "|" << rooms[i][j].get_event() << "|";
		}
		cout << endl;
	}
}
/*********************************************************************
** FUNCTION: get_player_action
** DESCRIPTION: asks player if move or shoot arrow
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: gets action
** RETURNS: nothing
*********************************************************************/
void Game::get_player_action(){
	cout << "Would you like to move through a (1) tunnel or (2) Fire an arrow through an adjacent room? ";
	cin >> player_action;
	while (player_action != 1 && player_action != 2){
		cout << "Bad input, try again: ";
		cin >> player_action;
	}
}
/*********************************************************************
** FUNCTION: move_player
** DESCRIPTION: moves player from one spot to another and checks for event
** PARAMETERS: none
** PRE-CONDITIONS: player in one position
** POST-CONDITIONS: player in a new position
** RETURNS: nothing
*********************************************************************/
void Game::move_player(){
	
	if ((movement == 'w') && (inbounds(player_position_x-1, player_position_y) == true)){ //up
		//previous position
		rooms[player_position_x][player_position_y].set_event(' ');
		player_position_x--;
		check_event();
		rooms[player_position_x][player_position_y].set_event('x');
	}
	
	else if ((movement == 'a') && (inbounds(player_position_x, player_position_y-1) == true)){ //left
		//previous position
		rooms[player_position_x][player_position_y].set_event(' ');
		player_position_y--;
		check_event();
		rooms[player_position_x][player_position_y].set_event('x');
	}
	
	else if ((movement == 'd') && (inbounds(player_position_x, player_position_y+1) == true)){ //right
		//previous position
		rooms[player_position_x][player_position_y].set_event(' ');
		player_position_y++;
		check_event();
		rooms[player_position_x][player_position_y].set_event('x');
	}
	
	else if ((movement == 's') && (inbounds(player_position_x+1, player_position_y) == true)){ //down
		//previous position
		rooms[player_position_x][player_position_y].set_event(' ');
		player_position_x++;
		check_event();
		rooms[player_position_x][player_position_y].set_event('x');
	}
	else cout << "**** You are out of bounds! ****" << endl;
}

/*********************************************************************
** FUNCTION: check_event
** DESCRIPTION: looks at what event is in the position then does their specific action
** PARAMETERS: none
** PRE-CONDITIONS: events set in position
** POST-CONDITIONS: actions made, position may change and variables updates
** RETURNS:  nothing
*********************************************************************/
//function to check what event is in the spot
void Game::check_event(){
	if (rooms[player_position_x][player_position_y].get_event() == 'w'){
		//wumpus function
		cout << "You have walked into the Wumpus room waking the Wumpus up! He has now ate you. " << endl;
		gameover = true;
	}
	//bats
	else if (rooms[player_position_x][player_position_y].get_event() == 'b'){
		cout << "OH NO, SUPER BATS! They have taken you to a new location." << endl;
		rooms[player_position_x][player_position_y].set_event(' ');
		player_position_x = set_random_position();
		player_position_y = set_random_position();
		rooms[player_position_x][player_position_y].set_event('x');
	}
	//gold
	else if (rooms[player_position_x][player_position_y].get_event() == 'g'){
		cout << "You have found gold, congrats!" << endl;
		numGold++;
	}
	//pit
	else if (rooms[player_position_x][player_position_y].get_event() == 'p'){
		cout << "You have fallen in a pit and died. You lose:(" << endl;
		gameover = true;
	}
}

/*********************************************************************
** FUNCTION: inbounds
** DESCRIPTION: makes sure player is in grid inbounds
** PARAMETERS: int x, int y
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: true or false
*********************************************************************/
bool Game::inbounds(int x, int y){
	if (x > gridSize-1 || x < 0 || y > gridSize-1 || y < 0){
		return false;
	}
	else
		return true;
}


/*********************************************************************
** FUNCTION: output_messages
** DESCRIPTION: outputs nearby event messages
** PARAMETERS: none
** PRE-CONDITIONS: events made
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::output_messages(){
	cout << "************MESSAGES!***********************" << endl;
	//up
	if ((inbounds(player_position_x-1, player_position_y) == true) && (rooms[player_position_x-1][player_position_y].get_event() != ' ')){
		cout << rooms[player_position_x-1][player_position_y].get_messages() << endl;
	}
	
	//left
	if ((inbounds(player_position_x, player_position_y-1) == true) && (rooms[player_position_x][player_position_y-1].get_event() != ' ')){
		cout << rooms[player_position_x][player_position_y-1].get_messages() << endl;
	}
	 
	//right
	if ((inbounds(player_position_x, player_position_y+1) == true) && (rooms[player_position_x][player_position_y+1].get_event() != ' ')){
		cout << rooms[player_position_x][player_position_y+1].get_messages() << endl;
	}
	 
	//down
	if ((inbounds(player_position_x+1, player_position_y) == true) && (rooms[player_position_x+1][player_position_y].get_event() != ' ')){
		cout << rooms[player_position_x+1][player_position_y].get_messages() << endl;
	}
}
/*********************************************************************
** FUNCTION: shoot_arrow
** DESCRIPTION: shoots arrow through 3 rooms or at Wumpus
** PARAMETERS: none
** PRE-CONDITIONS: none 
** POST-CONDITIONS: sees if kills wumpus or not
** RETURNS: nothing
*********************************************************************/
void Game::shoot_arrow(){
	set_movement(); //get direction for arrow
	int tempX = player_position_x;
	int tempY = player_position_y; 
	cout << "Arrow shot-> -> ->" << endl;
	if (movement == 'w'){
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++){
			tempX = player_position_x+i;
			tempY = player_position_y;
			if ((inbounds(tempX, tempY) == true) && (rooms[tempX][tempY].get_event() == 'w')){
				cout << "You have killed the Wumpus!" << endl;
				wumpusdead = true;
				break;
			}
			else cout << "You did not kill the Wumpus!" << endl;
		}
	}
	
	else if (movement == 'a'){ //left
	
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++){
			tempX = player_position_x;
			tempY = player_position_y-1;
			if ((inbounds(tempX, tempY) == true) && (rooms[tempX][tempY].get_event() == 'w')){
				cout << "You have killed the Wumpus!" << endl;
				wumpusdead = true;
				break;
			}
			else cout << "You did not kill the Wumpus!" << endl;
		}
	}
	
	else if (movement == 'd') { //right
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++){
			tempX = player_position_x;
			tempY = player_position_y+1;
			if ((inbounds(tempX, tempY) == true) && (rooms[tempX][tempY].get_event() == 'w')){
				cout << "You have killed the Wumpus!" << endl;
				wumpusdead = true;
				break;
			}
			else cout << "You did not kill the Wumpus!" << endl;
		}
	}
	
	else if (movement == 's') { //down
		//loop until arrow moves 3 places or hits wall
		for (int i = 1; i < 4; i++){
			tempX = player_position_x+1;
			tempY = player_position_y;
			if ((inbounds(tempX, tempY) == true) && (rooms[tempX][tempY].get_event() == 'w')){
				cout << "You have killed the Wumpus!" << endl;
				wumpusdead = true;
				break;
			}
			else cout << "You did not kill the Wumpus!" << endl;
		}
	}
}

/*********************************************************************
** FUNCTION: menu
** DESCRIPTION: main menu for the game, checks the actio they have chosen
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::menu(){
	get_player_action();
	if (player_action == 1){
		set_movement(); //arrow selection to move
		
		//function to move player
		move_player();
		check_event();
		
	}
	else if (player_action == 2){
		adjust_arrows();
		//function to send arrow through rooms
		shoot_arrow();
	}
}

/*********************************************************************
** FUNCTION: Game
** DESCRIPTION: removes arrray
** PARAMETERS: none
** PRE-CONDITIONS: array exists
** POST-CONDITIONS: array is deleted
** RETURNS: nothing
*********************************************************************/
//deconstructors
Game::~Game(){
	for (int i = 0; i < gridSize; ++i){
		delete[] rooms[i];
	}
	delete[] rooms;
}
/*********************************************************************
** FUNCTION: endgame
** DESCRIPTION: outputs messages for end of game
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::endgame(){
	int choice;
	if (won != true){
		cout << "You lost, would you like to: " << endl;
		cout << " (1) Start game over with same cave configuration. "<< endl;
		cout << " (2) Start game over with new random cave configuration" << endl; 
		cout << " (3) Quit game entirely." << endl;
		cin >> choice;
		
		if (choice == 1){
			won = false;
		}
		else if (choice == 2){
			//run_game();
		}
	}
	else cout << "Congratulations, you won!" << endl;
}

/*********************************************************************
** FUNCTION: check_if_won
** DESCRIPTION: checks variables to see if won
** PARAMETERS: none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
void Game::check_if_won(){
	if (numGold == 1 && wumpusdead == true && player_position_x == player_start_x && player_position_y == player_start_y){
		won = true;
		gameover = true;
	}
}

/*********************************************************************
** FUNCTION: run_game
** DESCRIPTION: runs entire game
** PARAMETERS: int num
** PRE-CONDITIONS: game non existent
** POST-CONDITIONS: game, variables and arrays made
** RETURNS: nothing
*********************************************************************/
void Game::run_game(int num){
		if (startingOver == true){
			set_gridSize(); //get number for cave size
		}
		gridSize = num;
		set_rooms(); //build array and set to blank spot
		set_starting_position(); //set random spot in cave to start
		set_event_in_rooms(); //change spots in cave to events
		output_grid(); //output the cave
		
		do{
			cout << endl;
			cout << "Gold found: " << numGold << endl;
			cout << "Number of arrows: " << arrows << endl;
			cout << "Postion: " << player_position_x << " " << player_position_y << endl;
			
			output_messages();
			menu(); //walk or shoot 
			output_grid(); //output the cave
			check_if_won();
		
		} while (gameover != true);
		endgame();
}
