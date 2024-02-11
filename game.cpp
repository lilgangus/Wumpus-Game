/*********************************************************************
** Program Filename: game.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Game class definitions
*********************************************************************/

#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "armor.h"

#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:

}


void Game::generate_unique_event_location(int &x, int &y, int l, int w) {
	// generate a unique x and y location for an event to be placed with no events or player
	while (this->cave[x][y].has_player_in_room() || this->cave[x][y].has_event_in_room())
	{
		x = rand() % l;
		y = rand() % w;
	}
	return;
}

void Game::generate_bats_and_stalactites(int l, int w) {

	// intialize a random x and y location
	int x = rand() % l;
	int y = rand() % w;

	// loop twice
	for (int i = 0; i < 2; ++i) {
		// generate 2 bats
		generate_unique_event_location(x, y, l, w);
		this->cave[x][y].set_event(new Bats());
		
		// generate 2 stalactites
		generate_unique_event_location(x, y, l, w);
		this->cave[x][y].set_event(new Stalactites());

 	}
	return;
}

void Game::generate_wumpus_and_gold(int l, int w) {

	// generate a random x and y location
	int x = rand() % l;
	int y = rand() % w;

	// generate a wumpus and set the wumpus room to the location of the wumpus
	generate_unique_event_location(x, y, l, w);
	this->cave[x][y].set_event(new Wumpus());
	this->wumpus_room[0] = x;
	this->wumpus_room[1] = y;


	// generate gold and armor
	generate_unique_event_location(x, y, l, w);
	this->cave[x][y].set_event(new Gold());
	generate_unique_event_location(x, y, l, w);
	this->cave[x][y].set_event(new Armor());
	return;
}


void Game::generate_events(int l, int w) {

	// generate a random starting position
	this->player_starting_room[0] = rand() % l;
	this->player_starting_room[1] = rand() % w;
	// set the player to be in the starting room
	this->cave[this->player_starting_room[0]][this->player_starting_room[1]].set_player_in_room(true);
	this->player_room[0] = this->player_starting_room[0];
	this->player_room[1] = this->player_starting_room[1];

	// generate bats and stalactites
	this->generate_bats_and_stalactites(l, w);

	// generate wumpus and gold
	this->generate_wumpus_and_gold(l, w);
	
	
}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
	
	// Create the game board: 2D vector of Room objects

	// resize the vector to the given length and width
	this->cave.resize(this->length);
	for (int i = 0; i < this->length; ++i)
	{
		this->cave[i].resize(this->width);
	}

	// generate events
	this->generate_events(l, w);
	
	

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	

}

bool Game::has_player(int length, int width) const {
	// return if the room at the given e and y has a player in it
	return this->cave[length][width].has_player_in_room();
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "
			if(this->has_player(i, j)) { 
				cout << "*";
			} else {
				cout << " ";
			}
			
			//The second char indicates whether there is an event in that room or not, and print it if the user wants to see the debug view
			if(this->debug_view) {
				string room = this->cave[i][j].return_room_event();
				cout <<  room << "||";
			} else {
				cout << "  ||";
			}
			//Fix the following...
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}


bool Game::check_win() const{
	//check if game over/win
	//Your code here:

	// check if the game_over flag is set to true, returning true that the game is over, or if the player is in the starting room and has the gold, returning true that the player has won
	if(game_over) {
		return true;
	} else if(this->cave[this->player_starting_room[0]][this->player_starting_room[1]].has_player_in_room() && this->player_has_gold) {
		return true;
	} else {
		return false;
	}

	// cout << "Game::check_win() is not implemented..." << endl;
	// return false;
}


void Game::set_player_room(int increment_value, bool inc) {
	// set room the player is currently in to be false
	this->cave[this->player_room[0]][this->player_room[1]].set_player_in_room(false);

	// increment set the player's room in the given direction with
	if(inc) {
		this->player_room[increment_value]++;
	} else {
		this->player_room[increment_value]--;
	}
	// set the player's room to be true
	this->cave[this->player_room[0]][this->player_room[1]].set_player_in_room(true);
	return;
}

void Game::move_up() {
	//move player up
	//Your code here:

	// if the player has reverse movement, move the player in the opposite direction
	if(this->reverse_movement > 0) {
		
		// if the player is not in the top row, move the player up
		if(!((this->player_room[0] + 1) == this->length)) {
			this->set_player_room(0, true);
		}

		// decrement the reverse movement counter
		this->reverse_movement--;

	} else if(!(this->player_room[0] == 0)) {
		// if the player is not in the top row, move the player up
		this->set_player_room(0, false);
	} else {
		cout << "Cannot move in that direction" << endl;
	}
	// cout << "Game::move_up() is not implemented..." << endl;
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:

	// if the player has reverse movement, move the player in the opposite direction
	if(this->reverse_movement > 0) {

		// if the player is not in the bottom row, move the player down
		if(!(this->player_room[0] == 0)) {
			this->set_player_room(0, false);
		}
		// decrement the reverse movement counter
		this->reverse_movement--;

	} else if(!((this->player_room[0] + 1) == this->length)) {
		this->set_player_room(0, true);
	} else {
		cout << "Cannot move in that direction" << endl;
	}
	// cout << "Game::move_down() is not implemented..." << endl;
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:

	// if the player has reverse movement, move the player in the opposite direction
	if (this->reverse_movement > 0) {

		// if the player is not in the leftmost column, move the player left
		if(!(this->player_room[1] == (this->width - 1))) {
			this->set_player_room(1, true);
		}
		// decrement the reverse movement counter
		this->reverse_movement--;

	} else if(!(this->player_room[1] == 0)) {
		this->set_player_room(1, false);
	} else {
		cout << "Cannot move in that direction" << endl;
	}
	// cout << "Game::move_left() is not implemented..." << endl;
	return;

}

void Game::move_right() {
	//move player right
	//Your code here:

	// if the player has reverse movement, move the player in the opposite direction
	if(this->reverse_movement > 0) {

		// if the player is not in the rightmost column, move the player right
		if(!(this->player_room[1] == 0)) {
			this->set_player_room(1, false);
		}

		// decrement the reverse movement counter
		this->reverse_movement--;

	} else if(!(this->player_room[1] == (this->width - 1))) {
		this->set_player_room(1, true);
	} else {

		cout << "Cannot move in that direction" << endl;
	}

	// cout << "Game::move_right() is not implemented..." << endl;
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move
	
	// if the random number between 4 and 0 is less than or equal to 3, move the wumpus
	if((rand() % 5) <= 3) {
		
		// set the wumpus room to have no event
		this->cave[this->wumpus_room[0]][this->wumpus_room[1]].set_event(nullptr);
		
		// generate a unique random x and y location for the wumpus
		int x = rand() % this->length;
		int y = rand() % this->width;
		while(this->cave[x][y].has_event_in_room()) {
			x = rand() % this->length;
			y = rand() % this->width;
		}

		// set the wumpus room to have a wumpus
		this->cave[x][y].set_event(new Wumpus());
		this->wumpus_room[0] = x;
		this->wumpus_room[1] = y;
	
	}

	//Your code here:
	// cout << "Game::wumpus_move() is not implemented..." << endl;
	
	return;
}

bool Game::check_rooms_for_wumpus(int direction, int i) {

	// handle north
	if(direction == 0) {
		// if the room is in the cave, check if the room has a wumpus
		if(this->player_room[0] - i >= 0) {

			// if the room has a wumpus, set the wumpus room to have no event and return true
			if(this->cave[this->player_room[0] - i][this->player_room[1]].return_room_event() == " W") {

				this->cave[this->wumpus_room[0]][this->wumpus_room[1]].set_event(nullptr);
				return true;

			} 
		}	

	} else if(direction == 1) {
		// handle south
		// if the room is in the cave, check if the room has a wumpus
		if(this->player_room[0] + i <= this->length - 1) {

			// if the room has a wumpus, set the wumpus room to have no event and return true
			if(this->cave[this->player_room[0] + i][this->player_room[1]].return_room_event() == " W") {

				this->cave[this->wumpus_room[0]][this->wumpus_room[1]].set_event(nullptr);
				return true;

			} 
		}
	} else if(direction == 2) {
		// handle west

		// if the room is in the cave, check if the room has a wumpus
		if(this->player_room[1] - i >= 0) {

			// if the room has a wumpus, set the wumpus room to have no event and return true
			if(this->cave[this->player_room[0]][this->player_room[1] - i].return_room_event() == " W") {
				
				// set the wumpus room to have no event and return true
				this->cave[this->wumpus_room[0]][this->wumpus_room[1]].set_event(nullptr);
				return true;

			} 
		}
	} else if(direction == 3) {
		// handle east

		// if the room is in the cave, check if the room has a wumpus
		if(this->player_room[1] + i <= this->width - 1) {

			// if the room has a wumpus, set the wumpus room to have no event and return true
			if(this->cave[this->player_room[0]][this->player_room[1] + i].return_room_event() == " W") {

				this->cave[this->wumpus_room[0]][this->wumpus_room[1]].set_event(nullptr);
				return true;

			} 
		}
	}
	return false;
}

bool Game::fire_arrow_in_dir(char dir) {

	// set and create a wumpus killed flag to false
	bool wumpus_killed = false;

	// handle north
	if(dir == 'w') {
		// check if wumpus is in the next 3 rooms above
		for(int i = 1; i <= 3; i++) {

			// check if the room has a wumpus
			wumpus_killed = this->check_rooms_for_wumpus(0, i);

			if(wumpus_killed) {
				break;
			}
		}
	} else if(dir == 'a') {
		// check if wumpus is in the next 3 rooms to the left
		for(int i = 1; i <= 3; i++) {

			wumpus_killed = this->check_rooms_for_wumpus(2, i);

			if(wumpus_killed) {
				break;
			}
		}
	} else if(dir == 's') {

		// check if wumpus is in the next 3 rooms below
		for(int i = 1; i <= 3; i++){

			wumpus_killed = check_rooms_for_wumpus(1, i);

			if(wumpus_killed) {
				break;
			}
		}
	} else if(dir == 'd') {
		// check if wumpus is in the next 3 rooms to the right
		for(int i = 1; i <= 3; i++) {

			wumpus_killed = check_rooms_for_wumpus(3, i);

			if(wumpus_killed) {
				break;
			}
		}
	}

	// if the status of the wumpus 
	return wumpus_killed;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	//Your code here:

	// if the player has no arrows, print that the player has no arrows
	if(this->num_arrows == 0) {
		cout << "No arrows to fire" << endl;
		return;
	} else {
		// get the direction of the arrow, and decrement the num_arrows
		char dir = get_dir();
		this->num_arrows--;

		// if the wumpus is killed from firing in that direction, print that the wumpus is killed, otherwise move the wumpus
		bool wumpus_killed = this->fire_arrow_in_dir(dir);
		
		if(wumpus_killed) {

			cout << "You have killed the Wumpus!" << endl;

		} else if(num_arrows == 2) {
			
			this->wumpus_move();

		}
	}
	// cout << "Game::fire_arrow() is not implemented..." << endl;

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

void Game::display_surrounding_percepts() {
	// display percept above
	if(this->player_room[0] > 0) {
		this->cave[this->player_room[0] - 1][this->player_room[1]].display_room_percept();
	}

	// display percept below
	if(player_room[0] <= (this->length - 2)) {
		this->cave[this->player_room[0] + 1][this->player_room[1]].display_room_percept();
	}

	// display percept to the left  
	if(player_room[1] > 0) {
		this->cave[this->player_room[0]][this->player_room[1] - 1].display_room_percept();
	}

	// display percept to the right  
	if(player_room[1] <= this->width - 2) {
		this->cave[this->player_room[0]][this->player_room[1] + 1].display_room_percept();
	}
}

void Game::encounter_event() {
	// call play_event on the room the player is in
	this->cave[this->player_room[0]][this->player_room[1]].play_event(this->game_over, this->reverse_movement, this->player_has_gold, this->armor);
	return;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){

	//set up the game
	Game::set_up(w, l);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		Game::display_surrounding_percepts();

		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		Game::encounter_event();
	}

	Game::display_game();

	//check if game over  is a win or lose
	if(this->game_over) {
		cout << "GAME OVER!" << endl;
	} else {
		cout << endl;
		cout << "YOU WIN!" << endl;
		cout << endl;
	}

	return;

}