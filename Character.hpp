/*********************************************************************
** Program name:  Project04 - Character.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   Character.hpp is the Character class specification file.
**                            
*********************************************************************/
#ifndef CHARACTER_H
#define CHARACTER_H




#include <string>

using std::string;


//Character class declaration
class Character
{
  private:




  public:

    Character();
		virtual int attack()=0;
		virtual int defense(int)=0;
		virtual string getFighterType()=0;
		virtual int getArmor()=0;
		virtual int getStrengthPoints()=0;
		virtual int getStunned()=0;
		virtual void stun()=0;
		virtual int specialAttack()=0;
		virtual void heal()=0;
		virtual ~Character() = 0;
		




		

  
};

#endif
