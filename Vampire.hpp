/*********************************************************************
** Program name:  Project04 - Vampire.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Vampire.hpp is the Vampire class specification file.
**                            
*********************************************************************/
#ifndef VAMPIRE_H
#define VAMPIRE_H


#include "Character.hpp"


#include <string>

using std::string;


//Vampire class declaration
class Vampire : public Character
{
  private:
		int armor;
		int strengthPoints;
		bool stunned;
		string fighterName;


  public:

    Vampire();
    ~Vampire();
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
