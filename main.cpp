

/*********************************************************************
** Program name:  Project04 - main.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   This program brings up a  menu asking the user if they would like to play. The user is then prompted to choose the names of two teams, choose how many fighters will be on each team, choose the name and type of fighters, then create a tournament with the two teams. They will battle by rolling dice and using special abilities until all the characters from a team are defeated. When one fighter defeats another, the winner will regain some strength points then move to the back of the fighting queue. The user will then be asked if they would like to view the list of defeated characters, then the user will be asked if they would like to play again or quit. 
**                            
*********************************************************************/

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
	
	//randomize the game
	srand(time(0));

	//ask the user if they would like to play

	cout << "Would you like to play?" << endl << "1. Play" << endl << "2. Quit" << endl;

	//use input validation to ensure that the user selects one of the available characters.

	int choice = 0;

	//the user enters information into the variable input
	cin >> choice;

	//if the input is not an appropriate integer, the user is prompted to try again
	while ((choice !=1 && choice !=2)) {
		//clear the cin
		cin.clear();
		cin.ignore();
		cout << "Please enter 1 or 2"<< endl;
		cin >> choice;
	} cout << endl;

	if (choice == 1) {
		//start the game
		menu();
	}


  cout << endl << "Program Terminated." <<endl;



return 0;
}
