/*********************************************************************
** Program name:  Project04 - Barbarian.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Barbarian.cpp is the Barbarian class implementation file.
**                            
*********************************************************************/

#include "Barbarian.hpp"
#include <string>
#include <iostream>
#include <cmath>


using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      Barbarian::Barbarian
* This function creates the Barbarian object
*******************************************************************/

  Barbarian::Barbarian() {

		armor = 0;
		strengthPoints = 12;
		stunned = 0;
		fighterName = "";

		
		cout << "Choose a fighter name: " << endl;
		cin>> fighterName;
		cin.clear();
		fighterName = "Barbarian " + fighterName;
		
  }


/******************************************************************* 
*                      Barbarian::attack
* This function allows the character to attack, randomly generating damage
*******************************************************************/

	int Barbarian::attack() {
		//roll the dice to calculate the damage

		return (rand() % 6 + 1) + (rand() % 6 + 1);

	}

/******************************************************************* 
*                      Barbarian::defense
* This function allows the character to randomly generate a number that will decrease damage or prevent the character from taking damage
*******************************************************************/
	int Barbarian::defense(int attackDamage) {
		//roll the dice to calculate the defense
		int defense = (rand() % 6 + 1) + (rand() % 6 + 1);

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
*                      Barbarian::getFighterType
* This function returns the fighter type
*******************************************************************/
	string Barbarian::getFighterType() {

		return fighterName;
	}
/******************************************************************* 
*                      Barbarian::getArmor
* This function returns the character's armor
*******************************************************************/
	int Barbarian::getArmor() {

		return armor;
	}
/******************************************************************* 
*                      Barbarian::getStrengthPoints
* This function returns the character's strength points
*******************************************************************/
	int Barbarian::getStrengthPoints() {

		return strengthPoints;
	}
/******************************************************************* 
*                      Barbarian::getStunned
* This function returns if the character is stunned or not and makes the character not stunned the next round
*******************************************************************/
	int Barbarian::getStunned() {
		int temp = stunned;
		stunned = 0;
		return temp;
	}
/******************************************************************* 
*                      Barbarian::stun
* This function stuns the character
*******************************************************************/
	void Barbarian::stun() {
		stunned = 1;
	}
/******************************************************************* 
*                      Barbarian::specialAttack
* This function uses the character's special attack
*******************************************************************/
	int Barbarian::specialAttack() {
		return 0;
	}
/******************************************************************* 
*                      Barbarian::heal
* This function heals the character for a random amount
*******************************************************************/
	void Barbarian::heal() {
		int healthGained = (rand() % 6 + 1);

		cout << endl << "While waiting for the next round, " << getFighterType() << " found an apple that heals for " << healthGained << " strength points! " << endl << endl;

		strengthPoints += healthGained;

	}
/******************************************************************* 
*                      Destructor
* This is the destructor for the character
*******************************************************************/
	Barbarian::~Barbarian() {

	}