/*********************************************************************
** Program Filename: stalactites.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Stalactites class definitions
*********************************************************************/

#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

Stalactites::Stalactites(){};

Stalactites::~Stalactites(){};

void Stalactites::display_percept() {
    cout << "You hear water dripping." << endl;
    return;
}

int Stalactites::play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {
    // 75% chance of stalactite, and 25% chance of nothing, if the player has armor, they survive the stalactite and lose 1 armor
    if (rand() % 5 <= 3) {
        if( armor > 0) {
            armor--;
            cout << "Your armor saved you from a stalacite!" << endl;
            game_over = false;
        } else {
            cout << "Unlucky, you have been impaled by a stalactite!" << endl;
            game_over = true;
        }
    } else {
        cout << "You just avoided a stalactite!" << endl;
        game_over = false;
    }

    return 3;
}

string Stalactites::return_event_char() {
    return " S";
}