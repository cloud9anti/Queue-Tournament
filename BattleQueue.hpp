/*********************************************************************
** Program name:  Project04 - BattleQueue.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   BattleQueue.hpp is the BattleQueue class specification file.
**                            
*********************************************************************/
#ifndef BATTLEQUEUE_H
#define BATTLEQUEUE_H

#include "Character.hpp"



//QueueNode struct declaration

struct QueueNode {
QueueNode* Next = nullptr;
QueueNode* Prev = nullptr;
Character* fighter = nullptr;
};


//Queue class declaration
class BattleQueue
{
  private:




  public:

		QueueNode* Head = nullptr;
    BattleQueue();
		~BattleQueue();

		bool isEmpty();
		void addBack(int);
		string getFront(); 
		Character* getFrontFighter();
		void removeFront();  
		void rotate();


};

#endif
