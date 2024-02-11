/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Wumpus class definitions
*********************************************************************/

#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
// Wumpus constructor created and defined to create new Wumpus events
Wumpus::Wumpus() {}

// destructor created to delete Wumpus events, prevents warnings, doesn't do anything
Wumpus::~Wumpus() {}


void Wumpus::display_percept() {
    cout << "You smell a terrible stench." << endl;
    return;
}

int Wumpus::play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {
    // if armor is greater than 0, then the player is saved from the Wumpus, otherwise we set game_over to true and the player is eaten
    if(armor > 0) {
        cout << "You have encountered the Wumpus, but your armor saved you!" << endl;
        armor--;
    } else {
        game_over = true;
        cout << "You have been eaten by the Wumpus!" << endl;
    }
    return 0;
}

string Wumpus::return_event_char() {
    return " W";
}