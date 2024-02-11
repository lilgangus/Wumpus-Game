/*********************************************************************
** Program Filename: bats.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Bats member function definitions 
*********************************************************************/

#include "bats.h"

#include <iostream>

using namespace std;

//Bats Implementation
Bats::Bats(){}

Bats::~Bats(){}

void Bats::display_percept() {
    cout << "You hear wings flapping" << endl;
    return;
}

int Bats::play_unique_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {
    game_over = false;
    reverse_movement = 5;
    cout << "You have encountered bats!" << endl;
    return 2;
}

string Bats::return_event_char() {
    return " B";
}