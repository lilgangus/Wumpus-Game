/*********************************************************************
** Program Filename: stalactites.h
** Author: Charles Tang
** Date: 11/28/2023
** Description: Stalactites class definitions
*********************************************************************/

#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"
//Stalactites Interface

class Stalactites : public Event {
private:
    /* data */
public:
    /*********************************************************************
	 * ** Function: Stalactites
	 * ** Description: this is the constructor for the Stalactites class
	 * ** Parameters: none
	 * ** Pre-Conditions: none
	 * ** Post-Conditions: none
	 * *********************************************************************/
    Stalactites();

    /*********************************************************************
     * ** Function: ~Stalactites
     * ** Description: this is the destructor for the Stalactites class
     * ** Parameters: none
     * ** Pre-Conditions: none
     * ** Post-Conditions: none
     * *********************************************************************/
    ~Stalactites();

    /*********************************************************************
     * ** Function: display_percept
     * ** Description: this is a virtual function that displays the percept 
     * ** Parameters: none
     * ** Pre-Conditions: none
     * ** Post-Conditions: none
     * *********************************************************************/
    void display_percept() override;


    /*********************************************************************
     * ** Function: play_unique_event
     * ** Description: this is a virtual function that plays the unique event
     * ** Parameters: 
	 * 			bool &game_over - this is a reference to the game_over variable in the main function
	 * 			int &reverse_movement - this is a reference to the reverse_movement variable in the main function
	 * 			bool &has_gold - this is a reference to the has_gold variable in the main function
	 * 			int &armor - this is a reference to the armor variable in the main function
     * ** Pre-Conditions: none
     * ** Post-Conditions: the game_over is set to true and the user dies, if the user does not have armor and is unlucky
     * **          returns 3 for the event occuring      
     * *********************************************************************/
    int play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) override;


    /*********************************************************************
     * ** Function: return_event_char
     * ** Description:	this is a virtual function that returns the event char
     * ** Parameters: none
     * ** Pre-Conditions: none
     * ** Post-Conditions: none
     * *********************************************************************/
    string return_event_char() override;
};

#endif
