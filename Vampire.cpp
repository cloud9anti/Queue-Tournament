/*********************************************************************
** Program name:  Project04 - Vampire.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Vampire.cpp is the Vampire class implementation file.
**                            
*********************************************************************/

#include "Vampire.hpp"
#include <string>
#include <iostream>
#include <cmath>


using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      Vampire::Vampire
* This function creates the Vampire object
*******************************************************************/

  Vampire::Vampire() {

		armor = 0;
		strengthPoints = 12;
		stunned = 0;
		fighterName = "";

		
		cout << "Choose a fighter name: " << endl;
		cin>> fighterName;
		cin.clear();
		fighterName = "Vampire " + fighterName;
		
  }


/******************************************************************* 
*                      Vampire::attack
* This function allows the character to attack, randomly generating damage
*******************************************************************/

	int Vampire::attack() {
		//roll the die to calculate the damage

		return (rand() % 12 + 1) ;

	}

/******************************************************************* 
*                      Vampire::defense
* This function allows the character to randomly generate a number that will decrease damage or prevent the character from taking damage
*******************************************************************/
	int Vampire::defense(int attackDamage) {
		//roll the die to calculate the defense
		int defense = (rand() % 6 + 1);

		//calculate the damage inflicted
		int damageInflicted = attackDamage-defense-armor;

		//if the damage inflicted is less than 0, set it to 0

		if (damageInflicted <0) {
			damageInflicted = 0;
		}

		strengthPoints -= damageInflicted;

		return defense;
	}
/******************************************************************* 
*                      Vampire::getFighterType
* This function returns the fighter type
*******************************************************************/
	string Vampire::getFighterType() {

		return fighterName;
	}
/******************************************************************* 
*                      Vampire::getArmor
* This function returns the character's armor
*******************************************************************/
	int Vampire::getArmor() {

		return armor;
	}
/******************************************************************* 
*                      Vampire::getStrengthPoints
* This function returns the character's strength points
*******************************************************************/
	int Vampire::getStrengthPoints() {

		return strengthPoints;
	}

/******************************************************************* 
*                      Vampire::getStunned
* This function returns if the character is stunned or not and makes the character not stunned the next round
*******************************************************************/
	int Vampire::getStunned() {
		int temp = stunned;
		stunned = 0;
		return temp;
	}
/******************************************************************* 
*                      Vampire::stun
* This function stuns the character
*******************************************************************/
	void Vampire::stun() {
		stunned = 1;
	}
/******************************************************************* 
*                      Vampire::specialAttack
* This function uses the character's special attack, Charm.
*******************************************************************/
	int Vampire::specialAttack() {
		//50% chance to use the special attack, Charm. If 1 is returned, the special attack is used and the opponent will be charmed.

		return rand() % 2;
	}

/******************************************************************* 
*                      Vampire::heal
* This function heals the character for a random amount
*******************************************************************/
	void Vampire::heal() {
		int healthGained = (rand() % 6 + 1);

		cout << endl << "While waiting for the next round, " << getFighterType() << " found an apple that heals for " << healthGained << " strength points! " << endl << endl;

		strengthPoints += healthGained;

	}
/******************************************************************* 
*                      Destructor
* This is the destructor for the character
*******************************************************************/
	Vampire::~Vampire() {

	}