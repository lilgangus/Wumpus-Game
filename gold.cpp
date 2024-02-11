/*********************************************************************
** Program Filename: gold.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Gold class definitions
*********************************************************************/

#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation

Gold::Gold(){};

Gold::~Gold(){};

void Gold::display_percept() {
    cout << "You see a glimmer nearby." << endl;
    return;
}

int Gold::play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {
    // if the player has the gold, then pick up the gold by setting the has_gold flag to true
    game_over = false;
    has_gold = true;
    cout << "You have found the gold, now return to the starting room!" << endl;
    return 1;
}

string Gold::return_event_char() {
    return " G";
}