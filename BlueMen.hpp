/*********************************************************************
** Program name:  Project04 - BlueMen.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   BlueMen.hpp is the BlueMen class specification file.
**                            
*********************************************************************/
#ifndef BLUEMEN_H
#define BLUEMEN_H


#include "Character.hpp"


#include <string>

using std::string;


//BlueMen class declaration
class BlueMen : public Character
{
  private:
		int armor;
		int strengthPoints;
		bool stunned;
		string fighterName;


  public:

    BlueMen();
    ~BlueMen();
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
