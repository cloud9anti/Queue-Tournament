/*********************************************************************
** Program name:  Project04 - HarryPotter.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   HarryPotter.cpp is the HarryPotter class implementation file.
**                            
*********************************************************************/

#include "HarryPotter.hpp"
#include <string>
#include <iostream>
#include <cmath>


using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      HarryPotter::HarryPotter
* This function creates the HarryPotter object
*******************************************************************/

  HarryPotter::HarryPotter() {

		armor = 0;
		strengthPoints = 12;
		stunned = 0;
		fighterName = "";

		
		cout << "Choose a fighter name: " << endl;
		cin>> fighterName;
		cin.clear();
		fighterName = "Harry Potter " + fighterName;
		
  }

/******************************************************************* 
*                      HarryPotter::attack
* This function allows the character to attack, randomly generating damage
*******************************************************************/

	int HarryPotter::attack() {
		//roll the dice to calculate the damage

		return (rand() % 6 + 1) + (rand() % 6 + 1);

	}

/******************************************************************* 
*                      HarryPotter::defense
* This function allows the character to randomly generate a number that will decrease damage or prevent the character from taking damage
*******************************************************************/
	int HarryPotter::defense(int attackDamage) {
		//roll the dice to calculate the defense
		int defense = (rand() % 6 + 1) + (rand() % 6 + 1);

		//calculate the damage inflicted
		int damageInflicted = attackDamage-defense-armor;

		//if the damage inflicted is less than 0, set it to 0

		if (damageInflicted <0 ) {
			damageInflicted = 0;
		}

		strengthPoints -= damageInflicted;
		if (strengthPoints <1 && lives == 1) {
			lives -=1;
			strengthPoints = 20;
			cout << "Harry Potter uses his special ability 'Hogwarts' to return to life!" << endl << endl;
		}

		return defense;
	}
/******************************************************************* 
*                      HarryPotter::getFighterType
* This function returns the fighter type
*******************************************************************/
	string HarryPotter::getFighterType() {

		return fighterName;
	}
/******************************************************************* 
*                      HarryPotter::getArmor
* This function returns the character's armor
*******************************************************************/
	int HarryPotter::getArmor() {

		return armor;
	}
/******************************************************************* 
*                      HarryPotter::getStrengthPoints
* This function returns the character's strength points
*******************************************************************/
	int HarryPotter::getStrengthPoints() {

		return strengthPoints;
	}

/******************************************************************* 
*                      HarryPotter::getStunned
* This function returns if the character is stunned or not and makes the character not stunned the next round
*******************************************************************/
	int HarryPotter::getStunned() {
		int temp = stunned;
		stunned = 0;
		return temp;
	}
/******************************************************************* 
*                      HarryPotter::stun
* This function stuns the character
*******************************************************************/
	void HarryPotter::stun() {
		stunned = 1;
	}
/******************************************************************* 
*                      HarryPotter::specialAttack
* This function uses the character's special attack.
*******************************************************************/
	int HarryPotter::specialAttack() {

		return 0;
	}
/******************************************************************* 
*                      HarryPotter::heal
* This function heals the character for a random amount
*******************************************************************/
	void HarryPotter::heal() {
		int healthGained = (rand() % 6 + 1);

		cout << endl << "While waiting for the next round, " << getFighterType() << " found an apple that heals for " << healthGained << " strength points! " << endl << endl;

		strengthPoints += healthGained;

	}
/******************************************************************* 
*                      Destructor
* This is the destructor for the character
*******************************************************************/
	HarryPotter::~HarryPotter() {

	}