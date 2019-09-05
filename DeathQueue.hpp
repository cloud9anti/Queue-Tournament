/*********************************************************************
** Program name:  Project04 - DeathQueue.hpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   DeathQueue.hpp is the DeathQueue class specification file.
**                            
*********************************************************************/
#ifndef DEATHQUEUE_H
#define DEATHQUEUE_H

#include "Character.hpp"
#include <string>



//QueueNode struct declaration

struct QueueNode2 {
QueueNode2* Next = nullptr;
QueueNode2* Prev = nullptr;
std::string fighter = "";
};


//Queue class declaration
class DeathQueue
{
  private:




  public:

		QueueNode2* Head = nullptr;
    DeathQueue();
		~DeathQueue();

		bool isEmpty();
		void addBack(std::string);
		string getFront(); 
		void removeFront(); 
		void printQueue(); 



};

#endif
