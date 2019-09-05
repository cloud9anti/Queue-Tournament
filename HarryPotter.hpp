/*********************************************************************
** Program name:  Project04 - HarryPotter.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   HarryPotter.hpp is the HarryPotter class specification file.
**                            
*********************************************************************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H


#include "Character.hpp"


#include <string>

using std::string;


//HarryPotter class declaration
class HarryPotter : public Character
{
  private:
		int armor;
		int strengthPoints;
		int lives;
		bool stunned;
		string fighterName;


  public:

    HarryPotter();
    ~HarryPotter();
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
