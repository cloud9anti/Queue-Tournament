/*********************************************************************
** Program name:  Project04 - Barbarian.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Barbarian.hpp is the Barbarian class specification file.
**                            
*********************************************************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H


#include "Character.hpp"


#include <string>

using std::string;


//Barbarian class declaration
class Barbarian : public Character
{
  private:
		int armor;
		int strengthPoints;
		bool stunned;
		string fighterName;


  public:

    Barbarian();
		~Barbarian();
		int attack();
		int defense(int);
		string getFighterType();
		int getArmor();
		int getStrengthPoints();
		int getStunned();
		void stun();
		void heal();
		int specialAttack();




		

  
};

#endif
