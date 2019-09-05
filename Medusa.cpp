/*********************************************************************
** Program name:  Project04 - Medusa.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Medusa.cpp is the Medusa class implementation file.
**                            
*********************************************************************/

#include "Medusa.hpp"
#include <string>
#include <iostream>
#include <cmath>


using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      Medusa::Medusa
* This function creates the Medusa object
*******************************************************************/

  Medusa::Medusa() {

		armor = 0;
		strengthPoints = 12;
		stunned = 0;
		fighterName = "";

		
		cout << "Choose a fighter name: " << endl;
		cin>> fighterName;
		cin.clear();
		fighterName = "Medusa " + fighterName;
		
  }

/******************************************************************* 
*                      Medusa::attack
* This function allows the character to attack, randomly generating damage
*******************************************************************/

	int Medusa::attack() {
		//roll the dice to calculate the damage
		int total = (rand() % 6 + 1) + (rand() % 6 + 1);
		if (total == 12) {
			glare = 2;
		}
		return total;

	}

/******************************************************************* 
*                      Medusa::defense
* This function allows the character to randomly generate a number that will decrease damage or prevent the character from taking damage
*******************************************************************/
	int Medusa::defense(int attackDamage) {
		//roll the dice to calculate the defense
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
*                      Medusa::getFighterType
* This function returns the fighter type
*******************************************************************/
	string Medusa::getFighterType() {

		return fighterName;
	}
/******************************************************************* 
*                      Medusa::getArmor
* This function returns the character's armor
*******************************************************************/
	int Medusa::getArmor() {

		return armor;
	}
/******************************************************************* 
*                      Medusa::getStrengthPoints
* This function returns the character's strength points
*******************************************************************/
	int Medusa::getStrengthPoints() {

		return strengthPoints;
	}

/******************************************************************* 
*                      Medusa::getStunned
* This function returns if the character is stunned or not and makes the character not stunned the next round
*******************************************************************/
	int Medusa::getStunned() {
		int temp = stunned;
		stunned = 0;
		return temp;
	}
/******************************************************************* 
*                      Medusa::stun
* This function stuns the character
*******************************************************************/
	void Medusa::stun() {
		stunned = 1;
	}
/******************************************************************* 
*                      Medusa::specialAttack
* This function uses the character's special attack, glare.
*******************************************************************/
	int Medusa::specialAttack() {
		int temp = glare;
		glare = 0;
		return temp;
	}
/******************************************************************* 
*                      Medusa::heal
* This function heals the character for a random amount
*******************************************************************/
	void Medusa::heal() {
		int healthGained = (rand() % 6 + 1);

		cout << endl << "While waiting for the next round, " << getFighterType() << " found an apple that heals for " << healthGained << " strength points! " << endl << endl;

		strengthPoints += healthGained;

	}
/******************************************************************* 
*                      Destructor
* This is the destructor for the character
*******************************************************************/
	Medusa::~Medusa() {

	}