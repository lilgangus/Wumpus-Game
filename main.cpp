/*********************************************************************
** Program Filename: main.cpp
** Author: Charles Tang
** Date: 11/28/2023 
** Description: This is the Programming Assignment 4 for CS 162
Input: Program prompts the different inputs, futher prompting based on the previous prompts. These inputs allow the user to play a hunt the wumpus game.
** Output: Program ouputs different movements from the game based on what the user selects
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	// initialize the variables to be non-valid values
	int wid = 4, len = 4;
	bool debug = false;
	
	Game g;

	//get two inputs: size of the cave(wid and len)
	while ((wid < 5 || len < 5) || (wid > 50 || len > 50)) {
		cout << "Please enter the desired width of the cave (Between 5 and 50): ";
		cin >> wid;
		cout << "Please enter the desired length of the cave (Between 5 and 50): ";
		cin >> len;
	}

	//get the 3rd input --> debug mode or not
	cout << "Do you want to play in debug mode (y/n)? ";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		debug = true;
	} else {
		debug = false;
	}

	//Play game
	g.play_game(wid, len, debug);


	return 0;
}