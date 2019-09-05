/*********************************************************************
** Program name:  Project04 - BlueMen.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   BlueMen.cpp is the BlueMen class implementation file.
**                            
*********************************************************************/

#include "BlueMen.hpp"
#include <string>
#include <iostream>
#include <cmath>


using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      Bluemen::BlueMen
* This function creates the BlueMen object
*******************************************************************/

  BlueMen::BlueMen() {

		armor = 0;
		strengthPoints = 12;
		stunned = 0;
		fighterName = "";

		
		cout << "Choose a fighter name: " << endl;
		cin>> fighterName;
		cin.clear();
		fighterName = "BlueMen " + fighterName;
		
  }


/******************************************************************* 
*                      BlueMen::attack
* This function allows the character to attack, randomly generating damage
*******************************************************************/

	int BlueMen::attack() {
		//roll the die to calculate the damage

		return (rand() % 10 + 1) + (rand() % 10 + 1);

	}

/******************************************************************* 
*                      BlueMen::defense
* This function allows the character to randomly generate a number that will decrease damage or prevent the character from taking damage
*******************************************************************/
	int BlueMen::defense(int attackDamage) {
		//roll the dice to calculate the defense. The number of dice depends on the strength points remaining.
		int defense = 0;
		if (strengthPoints >8) {
			defense = (rand() % 6 + 1) + (rand() % 6 + 1)+ (rand() % 6 + 1);
		} else if (strengthPoints >4 && strengthPoints <8) {
			defense = (rand() % 6 + 1) + (rand() % 6 + 1);
		} else {
			defense = (rand() % 6 + 1);
		}

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
*                      BlueMen::getFighterType
* This function returns the fighter type
*******************************************************************/
	string BlueMen::getFighterType() {

		return fighterName;
	}
/******************************************************************* 
*                      BlueMen::getArmor
* This function returns the character's armor
*******************************************************************/
	int BlueMen::getArmor() {

		return armor;
	}
/******************************************************************* 
*                      BlueMen::getStrengthPoints
* This function returns the character's strength points
*******************************************************************/
	int BlueMen::getStrengthPoints() {

		return strengthPoints;
	}
/******************************************************************* 
*                      BlueMen::getStunned
* This function returns if the character is stunned or not and makes the character not stunned the next round
*******************************************************************/
	int BlueMen::getStunned() {
		int temp = stunned;
		stunned = 0;
		return temp;
	}
/******************************************************************* 
*                      BlueMen::stun
* This function stuns the character
*******************************************************************/
	void BlueMen::stun() {
		stunned = 1;
	}
/******************************************************************* 
*                      BlueMen::specialAttack
* This function uses the character's special attack
*******************************************************************/
	int BlueMen::specialAttack() {
		return 0;
	}
/******************************************************************* 
*                      BlueMen::heal
* This function heals the character for a random amount
*******************************************************************/
	void BlueMen::heal() {
		int healthGained = (rand() % 6 + 1);

		cout << endl << "While waiting for the next round, " << getFighterType() << " found an apple that heals for " << healthGained << " strength points! " << endl << endl;

		strengthPoints += healthGained;

	}
/******************************************************************* 
*                      Destructor
* This is the destructor for the character
*******************************************************************/
	BlueMen::~BlueMen() {

	}