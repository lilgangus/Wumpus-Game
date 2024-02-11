/*********************************************************************
** Program Filename: Room.h
** Author: Charles Tang
** Date: 11/28/2023
** Description: Room class declarations
*********************************************************************/

#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
	bool player_in_room = false;
	bool has_event = false;
	Event *event = nullptr;
public:

	/*********************************************************************
     * ** Function: Room
     * ** Description: This is the default constructor for the Room class 
     * ** Parameters: none
     * ** Pre-Conditions: none
     * ** Post-Conditions: none
     * *********************************************************************/
	Room();

	/*********************************************************************
	 * ** Function: ~Room
	 * ** Description: This is the destructor for the Room class 
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	~Room();

	/*********************************************************************
	 * ** Function: get_player_in_room
	 * ** Description: This is a getter function for the player_in_room variable
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: Returns the player_in_room variable
	 * *********************************************************************/
	bool has_player_in_room() const;

	/*********************************************************************
	 * ** Function: get_has_event
	 * ** Description: This is a getter function for the has_event variable
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: Returns the has_event variable
	 * *********************************************************************/
	bool has_event_in_room() const;

	/*********************************************************************
	 * ** Function: set_player_in_room
	 * ** Description: This is a setter function for the player_in_room variable
	 * ** Parameters: bool x which is the value for if the player should be set in the room
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: Sets the player_in_room variable to x
	 * *********************************************************************/
	void set_player_in_room(bool x);

	/*********************************************************************
	 * ** Function: set_event
	 * ** Description: This is a setter function for the event variable
	 * ** Parameters: Event *e which a pointer to the event that should be set in the room
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: Sets the given event variable to e
	 * *********************************************************************/
	void set_event(Event *e);

	/*********************************************************************
	 * ** Function: display_room_percept
	 * ** Description: This is a function that displays the percept of the room
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	void display_room_percept();

	/*********************************************************************
	 * ** Function: play_event
	 * ** Description: This is a function that plays the event in the room
	 * ** Parameters: 
	 * 		bool &game_over - a reference to the game_over variable in the game class
	 * 		int &reverse_movement - a reference to the reverse_movement variable in the game class
	 * 		bool &has_gold - a reference to the has_gold variable in the game class
	 * 		int &armor - a reference to the armor variable in the game class
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: Depending on the event, different input variables may be set or changed
	 * *********************************************************************/
	void play_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor);

	/*********************************************************************
	 * ** Function: return_event_char
	 * ** Description: This is a function that returns the event char
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	string return_room_event() const;

};

#endif