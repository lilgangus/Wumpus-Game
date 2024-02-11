/*********************************************************************
** Program Filename: armor.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Armor member function definitions 
*********************************************************************/

#include "armor.h"

#include <iostream>

using namespace std;

//Armor Implementation
Armor::Armor(){}

Armor::~Armor(){}

void Armor::display_percept() {
    cout << "You feel the power" << endl;
    return;
}

int Armor::play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {
    // set game_over to false, and add 2 armor to the player
    game_over = false;
    armor = 2;
    cout << "You have encountered Armor!" << endl;
    return 4;
}

string Armor::return_event_char() {
    return " A";
}