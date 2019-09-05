
/*********************************************************************
** Program name:  Project04 - BattleQueue.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   BattleQueue.cpp is the BattleQueue class implementation file.
**                            
*********************************************************************/

#include "BattleQueue.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/******************************************************************* 
*                      BattleQueue::BattleQueue
* This function creates the BattleQueue object
*******************************************************************/

  BattleQueue::BattleQueue() {
		Head = nullptr;

}

/******************************************************************* 
*                      Destructor
* This is the destructor for the BattleQueue
*******************************************************************/
BattleQueue::~BattleQueue() {
		if (Head == nullptr) {
			//delete Head->fighter;
			//Head->fighter = nullptr;
			delete Head;
			Head = nullptr;
		} else if (Head!= nullptr && Head->Next==Head) {
			//Head->fighter = nullptr;
			delete Head;
			Head = nullptr;
		
		} else {

			QueueNode* Temp = Head;
			while (Temp->Next!=Head)  {

				Temp = Temp->Next;
				if (Temp->Prev!=Head) {
					//Temp->Prev->fighter = nullptr;
					delete Temp->Prev;
					Temp->Prev = nullptr;
				}

			}
			Head->fighter = nullptr;
			delete Head;
			Head = nullptr;
			delete Temp;
			Temp = nullptr;
			}




}


/******************************************************************* 
*                      BattleQueue::is empty
* This function checks to see if the BattleQueue object contains any nodes
*******************************************************************/
bool BattleQueue::isEmpty() {
	if (Head == nullptr) {
		return 1;
	}
	return 0;
}
/******************************************************************* 
*                      BattleQueue::add back
* This function adds a new node to the back of the BattleQueue
*******************************************************************/
void BattleQueue::addBack(int fighterNum) {
	//set the fighter based on the passed integer

	Character* fighterTemp = nullptr;
	if (fighterNum == 1) {
		fighterTemp = new Barbarian();
	} else if (fighterNum == 2) {
		fighterTemp = new Vampire();
	} else if (fighterNum == 3) {
		fighterTemp = new BlueMen();
	} else if (fighterNum == 4) {
		fighterTemp = new Medusa();
	} else if (fighterNum == 5) {
		fighterTemp = new HarryPotter();
	}

	//check to see if the BattleQueue is empty
	if (isEmpty()) {

		Head = new QueueNode();
		Head->fighter = fighterTemp;
		Head->Next = Head;
		Head->Prev = Head;

	//check to see if the BattleQueue has one node
	} else if (Head->Next == Head) {
		Head->Next = new QueueNode();
		Head->Prev = Head->Next;
		Head->Next->fighter = fighterTemp;
		Head->Next->Next = Head;
		Head->Next->Prev = Head;
	} else {
		QueueNode* Temp = Head;
		while (Temp->Next!= Head)  {
			Temp = Temp->Next;
		}
		Temp->Next = new QueueNode();
		Temp->Next->fighter = fighterTemp;
		Temp->Next->Next = Head;
		Temp->Next->Prev = Temp;
		Head->Prev = Temp->Next;

	}

}
/******************************************************************* 
*                      BattleQueue::get front
* This function returns the value of the node at the front of the BattleQueue
*******************************************************************/
string BattleQueue::getFront() {
	//check to see if head exists
	if (Head != nullptr) {
		return Head->fighter->getFighterType();
	} else {
			return 0;
	}


}




Character* BattleQueue::getFrontFighter() {
	if (Head != nullptr) {
		return Head->fighter;
	} else {
		return 0;
	}
}
/******************************************************************* 
*                      BattleQueue::remove front
* This function deletes the first node in the BattleQueue.
*******************************************************************/
void BattleQueue::removeFront() {

	//if no nodes exist
	if (isEmpty()) {

		//if one node exists
	} else if (Head->Next == Head) {
		delete Head->fighter;
		Head->fighter = nullptr;

		delete Head;
		Head = nullptr;
	//if 2 nodes exist
	} else if (Head->Next->Next == Head) {
		Head = Head->Next;
		Head->Next = Head;
		delete Head->Prev->fighter;
		Head->Prev->fighter = nullptr;
		delete Head->Prev;
		Head->Prev = Head;
	}
	//if 3 or more nodes exist
	else {

		Head = Head->Next;
		Head->Prev = Head->Prev->Prev;
		delete Head->Prev->Next->fighter;
		Head->Prev->Next->fighter = nullptr;
		delete Head->Prev->Next;
		Head->Prev->Next = Head;

	}
		
}
/******************************************************************* 
*                      BattleQueue::rotate
* This function rotates the lineup so the current fighter will go to the back of the queue.
*******************************************************************/
void BattleQueue::rotate() {
	if (Head!= nullptr && Head->Prev!= nullptr) {
		Head = Head->Prev;
	}
}



