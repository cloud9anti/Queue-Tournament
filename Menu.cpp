/*********************************************************************
** Program name:  Project04 - Menu.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Menu.cpp brings up the the menu displaying five characters by their names, and prompts the user to select two characters to fight one another. After every round, the results are displayed on the screen.
**                            
*********************************************************************/

#include <string>
#include <iostream>
#include <vector>

#include "Menu.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "BattleQueue.hpp"
#include "DeathQueue.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/******************************************************************* 
*                      Menu
* This function displays the menu that asks the user to choose who will fight
*******************************************************************/
void menu() {

	//choose a name for the teams
	int team1Score = 0;
	int team2Score = 0;
	string team1Name = "one";
	string team2Name = "two";

	cout << "Choose a name for team 1 (max of one word): " << endl;
	cin>> team1Name;


	cout << "Choose a name for team 2 (max of one word): " << endl;
	cin>> team2Name;

	//ask the users how many fighters will be on each team

	cout << "Choose the number of fighters per team (1-10): " << endl;
	//use input validation to ensure that the user selects a positive integer.

	int fighters = 0;

	//the user enters information into the variable input
	cin >> fighters;

	//if the input is not an appropriate integer, the user is prompted to try again
	while ((fighters <1 || fighters >10)) {
		//clear the cin
		cin.clear();
		cin.ignore();
		cout << "Please enter an integer 1-10"<< endl;
		cin >> fighters;
	} cout << endl;



	//create the lineups using two BattleQueue objects

	BattleQueue* Team1 = new BattleQueue();
	BattleQueue* Team2 = new BattleQueue();
	DeathQueue* Graveyard = new DeathQueue();



	//use input validation to ensure that the user selects one of the available characters.

	int choice1 = 0;

	//the user enters information into the variable input
	for (int i=0; i<fighters; i++) {
		//ask the user to select the characters to battle

		cout << "Select a character for team 1 (max of one word): " << endl
		<< "1. Barbarian" << endl << "2. Vampire" << endl
		<< "3. Blue Men" << endl << "4. Medusa" << endl
		<< "5. Harry Potter" << endl << endl;
		cin >> choice1;
		cin.clear();

		//if the input is not an appropriate integer, the user is prompted to try again
		while ((choice1 !=1 && choice1 !=2 && choice1 !=3 && choice1!=4 && choice1 != 5)) {
				
			//clear the cin
			cin.clear();
			cin.ignore();
			cout << "Please enter 1, 2, 3, 4, or 5" << endl;
			cin >> choice1;
		} cout << endl;

		if (choice1 == 1) {
			cout << "Player 1 chose: Barbarian." << endl;
			Team1->addBack(1);
		}
		if (choice1 == 2) {
			cout << "Player 1 chose: Vampire." << endl;
			Team1->addBack(2);
		}
		if (choice1 == 3) {
			cout << "Player 1 chose: BlueMen." << endl;
			Team1->addBack(3);
		}
		if (choice1 == 4) {
			cout << "Player 1 chose: Medusa." << endl;
			Team1->addBack(4);
		}
		if (choice1 == 5) {
			cout << "Player 1 chose: HarryPotter." << endl;
			Team1->addBack(5);
		}
	}



	//	//use input validation to ensure that the user selects one of the available characters.

	choice1 = 0;

	//the user enters information into the variable input
	for (int i=0; i<fighters; i++) {

		//ask the user to select the characters to battle

		cout << "Select a character for team 2 (max of one word): " << endl
		<< "1. Barbarian" << endl << "2. Vampire" << endl
		<< "3. Blue Men" << endl << "4. Medusa" << endl
		<< "5. Harry Potter" << endl << endl;

		cin >> choice1;
		cin.clear();

		//if the input is not an appropriate integer, the user is prompted to try again
		while ((choice1 !=1 && choice1 !=2 && choice1 !=3 && choice1!=4 && choice1 != 5)) {
				
			//clear the cin
			cin.clear();
			cin.ignore();
			cout << "Please enter 1, 2, 3, 4, or 5" << endl;
			cin >> choice1;
		} cout << endl;

		if (choice1 == 1) {
			cout << "Player 2 chose: Barbarian." << endl;
			Team2->addBack(1);
		}
		if (choice1 == 2) {
			cout << "Player 2 chose: Vampire." << endl;
			Team2->addBack(2);
		}
		if (choice1 == 3) {
			cout << "Player 2 chose: BlueMen." << endl;
			Team2->addBack(3);
		}
		if (choice1 == 4) {
			cout << "Player 2 chose: Medusa." << endl;
			Team2->addBack(4);
		}
		if (choice1 == 5) {
			cout << "Player 2 chose: HarryPotter." << endl;
			Team2->addBack(5);
		}
	}

	//remove the losing fighters and rotate the winners.
	while (Team1->getFrontFighter()!=0 && Team2->getFrontFighter()!=0) {
		battle(Team1->getFrontFighter(),Team2->getFrontFighter());

		if (Team1->getFrontFighter()->getStrengthPoints() <1) {
				//Add the loser to the death queue
				Graveyard->addBack(Team1->getFrontFighter()->getFighterType());
				Team1->removeFront();
				Team2->rotate();
				team2Score+=1;


		}
		if (Team2->getFrontFighter()->getStrengthPoints() <1) {
				//Add the loser to the death queue
			Graveyard->addBack(Team2->getFrontFighter()->getFighterType());
				Team2->removeFront();
				Team1->rotate();
				team1Score+=1;

		}
	}
	string winner = "";
	if (team1Score > team2Score) {
		winner = team1Name;
	} else if (team2Score > team1Score) {
		winner = team2Name;
	} else {
		winner = "Neither! It's a tie!";
	}



cout << "Team " << team1Name << " scored " << team1Score << " and Team " << team2Name << " scored " << team2Score << "! The winner is " << winner << "!!!" << endl << endl;

int choice = 0;


	cout << "Would you like to see the loser pile?" << endl << "1. Yes" << endl << "2. No" << endl;

	//use input validation to ensure that the user selects one of the available characters.


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

		//show the graveyard in order of who died most recently
		cout << "Graveyard: " << endl << endl;
		Graveyard->printQueue();

	}

	//delete the team and graveyard pointers and free the memory
	for (int i = 0; i<fighters; i++) {
		Team1->removeFront();
		Team2->removeFront();
		Graveyard->removeFront();
	}

	//ask the user to play again or quit.

	cout << "Play again?" << endl << "1. Play again." << endl << "2. Quit." << endl;

	//use input validation to ensure that the user selects one of the available characters.

	choice = 0;

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
		//start the game again
		menu();
	} else {
		//reset the choice variable and exit the game
		choice = 0;
	}



	delete Graveyard;
	Graveyard = 0;
	delete Team1;
	Team1 = 0;
	delete Team2;
	Team2 = 0;



}
/******************************************************************* 
*                      Battle
* This function processes the battle and displays the battle results to the console
*******************************************************************/

  void battle(Character* P1,Character* P2) {

		int game = 0;
		

		//initialize the variables
		int damage, defense, armor, strengthPoints, damageInflicted, special = 0;
		bool stone = 0;

		while (game == 0) {
			//check to see if player 1 can attack
			if (P1->getStunned() == 0) {

				//calculate the damage
				damage = P1->attack();

				//special attack
				special = P1->specialAttack();

				if (special == 1) {
					P2->stun();
					} else if (special == 2) {
						stone = 1;
					}
			

				special = 0;



				//if the enemy is turned to stone, display an alternate message
				if (stone == 1) {

					defense = P2->defense(100);
					stone = 0;
					strengthPoints = P2->getStrengthPoints();
					if (strengthPoints<0) {
						strengthPoints = 0;
					}

				} else {
					
				//player 1 attacks player 2. Roll the dice and calculate the defense

				strengthPoints = P2->getStrengthPoints();
				defense = P2->defense(damage);
				armor = P2->getArmor();
				
			

				//calculate the damage inflicted and remaining strength points
				damageInflicted = damage-defense-armor;

				//if the damage inflicted is less than 0, set it to 0

				if (damageInflicted <0) {
					damageInflicted = 0;
				}
				strengthPoints = P2->getStrengthPoints();

				//ensure that the health does not go below 0.
				if (strengthPoints<0) {
					strengthPoints = 0;

				}


			}
				
				if (strengthPoints <=0) {
					cout << P2->getFighterType() << " has been defeated by " << P1->getFighterType() << " and was sent to the graveyard." << endl;

					P1->heal();
					game = 1;
				}

			}
		
			

			if (game == 0) {

				//check to see if player 2 can attack
				if (P2->getStunned() == 0) {

				//calculate the damage
				damage = P2->attack();

				//special attack
				special = P2->specialAttack();
				if (special == 1) {
					P1->stun();
				} else if (special == 2) {
					stone = 1;
				}


				special = 0;



				//if the enemy is turned to stone, display an alternate message

					if (stone == 1) {

						defense = P1->defense(100);
						stone = 0;
						strengthPoints = P1->getStrengthPoints();
						if (strengthPoints<0) {
							strengthPoints = 0;
						}
					} else {

					//player 2 attacks player 1. Roll the dice and calculate the defense

					strengthPoints = P1->getStrengthPoints();
					defense = P1->defense(damage);
					armor = P1->getArmor();

						//calculate the damage inflicted and remaining strength points
						damageInflicted = damage-defense-armor;

						//if the damage inflicted is less than 0, set it to 0

						if (damageInflicted <0) {
							damageInflicted = 0;
						}
						strengthPoints = P1->getStrengthPoints();

						//ensure that the health does not go below 0.
						if (strengthPoints<0) {
							strengthPoints = 0;
						}
					}
						
						if (strengthPoints <=0) {
					cout << P1->getFighterType() <<" has been defeated by " << P2->getFighterType() << " and was sent to the graveyard." << endl;

							P2->heal();
							game = 1;
						}
					}
				}
		}
		


  }


