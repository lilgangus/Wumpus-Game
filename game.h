/*********************************************************************
** Program Filename: game.h
** Author: Charles Tang
** Date: 11/28/2023
** Description: Game class declarations
*********************************************************************/

#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector<vector<Room>> cave;

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not


	//feel free to add more variables...
	// these variables are 2d arrays that hold the x and y position of the player
	int player_starting_room[2];	// array that holds the starting position of the player
	int player_room[2];				// array that holds the current position of the player
	int wumpus_room[2];				// array that holds the position of the wumpus

	bool game_over = false; 		// flag to determine if the game is over
	bool player_has_gold = false;   // flag to determine if the player has the gold

	int reverse_movement = 0; 		// int to determine how many more moves to reverse the player's movement
	int armor = 0;					// int to determine if the player has armor


public:

	//suggested functions:

	/*********************************************************************
	 * ** Function: Game
	 * ** Description: this is the constructor for the Game class
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	Game();

	/*********************************************************************
	 * ** Function: ~Game
	 * ** Description: this is the destructor for the Game class
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	~Game();
	
	/*********************************************************************
	 * ** Function: set_up
	 * ** Description: this function sets up the game
	 * ** Parameters: int length, int width
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: A game is created with the length and width and the player and events placed in random rooms
	 * *********************************************************************/
	void set_up(int, int);


	/*********************************************************************
	 * ** Function: display_game
	 * ** Description: this function displays the game
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: The game is displayed to the console
	 * *********************************************************************/
	void display_game() const;


	/*********************************************************************
	 * ** Function: check_win
	 * ** Description: this function checks if the player has won, returing the game_over variable
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: returns true if the player has won, false otherwise
	 * *********************************************************************/
	bool check_win() const;
	

	/*********************************************************************
	 * ** Function: get_dir
	 * ** Description: this function gets the direction the player wants to move
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: returns the direction the player wants to move as w, a, s, or d
	 * *********************************************************************/
	char get_dir();


	/*********************************************************************
	 * ** Function: wumpus_move
	 * ** Description: this function moves the wumpus to a random room
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the wumpus is moved to a random adjacent room
	 * *********************************************************************/
	void wumpus_move();


	/*********************************************************************
	 * ** Function: fire_arrow
	 * ** Description: this function fires an arrow in the direction the player wants to fire
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the arrow is fired in the direction the player wants to fire, going through 3 rooms
	 * *********************************************************************/
	void fire_arrow();


	/*********************************************************************
	 * ** Function: move_up
	 * ** Description: this function moves the player up
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player is moved up
	 * *********************************************************************/
	void move_up();


	/*********************************************************************
	 * ** Function: move_down
	 * ** Description: this function moves the player down
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player is moved down
	 * *********************************************************************/
	void move_down();


	/*********************************************************************
	 * ** Function: move_left
	 * ** Description: this function moves the player left
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player is moved left
	 * *********************************************************************/
	void move_left();


	/*********************************************************************
	 * ** Function: move_right
	 * ** Description: this function moves the player right
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player is moved right
	 * *********************************************************************/
	void move_right();


	/*********************************************************************
	 * ** Function: move
	 * ** Description: this function calls the appropriate move function based on the direction the player wants to move
	 * ** Parameters: char dir
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player is moved in the direction the player wants to move
	 * *********************************************************************/
	void move(char);


	/*********************************************************************
	 * ** Function: get_input
	 * ** Description: this function gets the input from the user to either move or fire an arrow
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  returns the input from the user
	 * *********************************************************************/
	char get_input();


	/*********************************************************************
	 * ** Function: play_game
	 * ** Description: this function plays the game
	 * ** Parameters: int length, int width, bool debug_view
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the game is run from this function
	 * *********************************************************************/
	void play_game(int, int, bool);

	//feel free (and you will need) to add more functions...

	/*********************************************************************
	 * ** Function: has_player
	 * ** Description: this function checks if the room at the given coordinates has the player
	 * ** Parameters: int length, int width
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  returns true if the room at the given coordinates has the player, false otherwise
	 * *********************************************************************/
	bool has_player(int length, int width) const;


	/*********************************************************************
	 * ** Function: generate_events
	 * ** Description: This function generates the events in the game
	 * ** Parameters: 
	 * 		int l - the length of the board
	 * 		int w - the width of the board
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  returns true if the room at the given coordinates has the wumpus, false otherwise
	 * *********************************************************************/
	void generate_events(int l, int w);


	/*********************************************************************
	 * ** Function: display_surrounding_percepts
	 * ** Description: This function displays the percepts of the surrounding rooms
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  none
	 * *********************************************************************/
	void display_surrounding_percepts();


	/*********************************************************************
	 * ** Function: set_player_room
	 * ** Description: This function sets the player room
	 * ** Parameters: 
	 * 		int increment_value - the value, in the player room array, to increment the player room by
	 * 		bool inc - whether or not to increment the player room base on which direction the player is moving
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the player room is set to the new room
	 * *********************************************************************/
	void set_player_room(int increment_value, bool inc);


	/*********************************************************************
	 * ** Function: encounter_event
	 * ** Description: This function encounters the event in the room, playing the unique event if there is one
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the event in the room is encountered
	 * *********************************************************************/
	void encounter_event();


	/*********************************************************************
	 * ** Function: fire_arrow_in_dir
	 * ** Description: this function fires an arrow in the direction the player wants to fire
	 * ** Parameters: 
	 * 		char dir - the direction the player wants to fire
	 * ** Pre-Conditions: There must be arrows left for the user to fire
	 * ** Post-Conditions:  the arrow is fired in the direction the player wants to fire, going through 3 rooms
	 * *********************************************************************/
	bool fire_arrow_in_dir(char dir);


	/*********************************************************************
	 * ** Function: check_rooms_for_wumpus
	 * ** Description: this function checks if the room in the given direction has the wumpus
	 * ** Parameters: 
	 * 		int direction - the direction to check for the wumpus
	 * 		int i - the index offset from the player's room to check for the wumpus
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  returns true if the room in the given direction has the wumpus, false otherwise
	 * *********************************************************************/
	bool check_rooms_for_wumpus(int direction, int i);


	/*********************************************************************
	 * ** Function: generate_bats_and_stalactites
	 * ** Description: this function generates random locations for the bats and stalactites events in the game
	 * ** Parameters: 
	 * 			int l - the length of the board
	 * 			int w - the width of the board
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the bats and stalactites are placed in random rooms
	 * *********************************************************************/
	void generate_bats_and_stalactites(int l, int w);


	/*********************************************************************
	 * ** Function: generate_wumpus_and_gold
	 * ** Description: this function generates random locations for the wumpus and gold events in the game
	 * ** 				this function also generates an armor event for the extra credit
	 * ** Parameters: 
	 * 			int l - the length of the board
	 * 			int w - the width of the board
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the wumpus and gold are placed in random rooms (and armor event)
	 * *********************************************************************/
	void generate_wumpus_and_gold(int l, int w);


	/*********************************************************************
	 * ** Function: generate_unique_event_location
	 * ** Description: this function generates a random location for the given event
	 * ** Parameters: 
	 * 			int &x - the x position of the event
	 * 			int &y - the y position of the event
	 * 			int l - the length of the board
	 * 			int w - the width of the board
	 * ** Pre-Conditions: none
	 * ** Post-Conditions:  the event is placed in a random room
	 * *********************************************************************/
	void generate_unique_event_location(int &x, int &y, int l, int w);


};
#endif