/*********************************************************************
** Program Filename: room.cpp
** Author: Charles Tang
** Date: 11/28/2023
** Description: Room class definitions
*********************************************************************/

#include "room.h"
#include <string>
#include <iostream>

using namespace std;

//Room Implementation

bool Room::has_player_in_room() const {
    return this->player_in_room;
}

bool Room::has_event_in_room() const {
    return this->has_event;
}

void Room::set_player_in_room(bool x) {
    this->player_in_room = x;
    return;
}

void Room::set_event(Event *e) {
    // if the event to set is null, delete the current event and set has_event to false
    if(e == nullptr) {
        this->has_event = false;
        delete this->event;
        this->event = nullptr;
        return;
    }

    // if the event to set is not null, set has_event to true and set the event
    this->event = e;
    this->has_event = true;
    return;
}

void Room::display_room_percept() {
    // if the room has an event, call the event's display_percept function
    if(this->has_event) {
        this->event->display_percept();
    } else {
        cout << endl;
    }
    return;
}

// default constructor
Room::Room() {
    this->player_in_room = false;
    this->has_event = false;
    this->event = nullptr;
}

Room::~Room() {
    delete event;
}


void Room::play_event(bool &game_over, int &reverse_movement, bool &has_gold, int &armor) {

    // if the room has an event, call the event's play_unique_event function
    if(this->has_event) {
        // play the event and get the event type
        // 0 for wumpus, 1 for gold, 2 for stalaticies, 3 for bats, 4 for armor
        int event_type = this->event->play_unique_event(game_over, reverse_movement, has_gold, armor);

        // if the event is gold or armor, delete the event
        if(event_type == 1 || event_type == 4) {
            delete this->event;
            this->event = nullptr;
            this->has_event = false;
        
        }
    }
    return;
}

string Room::return_room_event() const {
    // if the room has an event, return the event's character, otherwise return two spaces
    if(this->has_event) {
        string event_character = this->event->return_event_char();
        return event_character;
    } else {
        return "  ";
    }
}