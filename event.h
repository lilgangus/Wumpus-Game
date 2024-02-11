/*********************************************************************
** Program Filename: event.h
** Author: Charles Tang
** Date: 11/28/2023
** Description: Event class declarations
*********************************************************************/

#ifndef EVENT_H
#define EVENT_H 
#include <string>

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	
public:

	/*********************************************************************
     * ** Function: ~Event
     * ** Description: this is the virtual destructor for the Event class
     * ** Parameters: none
     * ** Pre-Conditions: none
     * ** Post-Conditions: none
     * *********************************************************************/
	virtual ~Event() = default; //destructor

	/*********************************************************************
	 * ** Function: display_percept
	 * ** Description: this is a virtual function that displays the percept 
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	virtual void display_percept() = 0;


	/*********************************************************************
	 * ** Function: play_unique_event
	 * ** Description: this is a virtual function that plays the unique event
	 * ** Parameters: 
	 * 			bool &game_over - this is a reference to the game_over variable in the main function
	 * 			int &reverse_movement - this is a reference to the reverse_movement variable in the main function
	 * 			bool &has_gold - this is a reference to the has_gold variable in the main function
	 * 			int &armor - this is a reference to the armor variable in the main function
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	virtual int play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) = 0;


	/*********************************************************************
	 * ** Function: return_event_char
	 * ** Description: this is a virtual function that returns the event char
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
	virtual string return_event_char() = 0;
};
#endif