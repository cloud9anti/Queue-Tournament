/*********************************************************************
** Program name:  Project04 - Medusa.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Medusa.hpp is the Medusa class specification file.
**                            
*********************************************************************/
#ifndef MEDUSA_H
#define MEDUSA_H


#include "Character.hpp"


#include <string>

using std::string;


//Medusa class declaration
class Medusa : public Character
{
  private:
		int armor;
		int strengthPoints;
		bool stunned;
		int glare;
		string fighterName;


  public:

    Medusa();
    ~Medusa();
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
