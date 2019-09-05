
/*********************************************************************
** Program name:  Project04 - DeathQueue.cpp
** Author:               Alexander McGrath
** Date:                  05/24/2019
** Description:   DeathQueue.cpp is the DeathQueue class implementation file.
**                            
*********************************************************************/

#include "DeathQueue.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/******************************************************************* 
*                      DeathQueue::DeathQueue
* This function creates the DeathQueue object
*******************************************************************/

  DeathQueue::DeathQueue() {
		Head = nullptr;

}

/******************************************************************* 
*                      Destructor
* This is the destructor for the DeathQueue
*******************************************************************/
DeathQueue::~DeathQueue() {
		if (Head == nullptr) {

			delete Head;
			Head = nullptr;
		} else if (Head!= nullptr && Head->Next==Head) {

			delete Head;
			Head = nullptr;
		
		} else {

			QueueNode2* Temp = Head;
			while (Temp->Next!=Head)  {

				Temp = Temp->Next;
				if (Temp->Prev!=Head) {
					delete Temp->Prev;
					Temp->Prev = nullptr;
				}

			}
			delete Head;
			Head = nullptr;
			delete Temp;
			Temp = nullptr;
			}




}


/******************************************************************* 
*                      DeathQueue::is empty
* This function checks to see if the DeathQueue object contains any nodes
*******************************************************************/
bool DeathQueue::isEmpty() {
	if (Head == nullptr) {
		return 1;
	}
	return 0;
}
/******************************************************************* 
*                      DeathQueue::add back
* This function adds a new node to the back of the DeathQueue
*******************************************************************/
void DeathQueue::addBack(string fighterName) {
	//set the fighter based on the passed string
	//check to see if the DeathQueue is empty
	if (isEmpty()) {

		Head = new QueueNode2();
		Head->fighter = fighterName;
		Head->Next = Head;
		Head->Prev = Head;

	//check to see if the DeathQueue has one node
	} else if (Head->Next == Head) {
		Head->Next = new QueueNode2();
		Head->Prev = Head->Next;
		Head->Next->fighter = fighterName;
		Head->Next->Next = Head;
		Head->Next->Prev = Head;
	} else {
		QueueNode2* Temp = Head;
		while (Temp->Next!= Head)  {
			Temp = Temp->Next;
		}
		Temp->Next = new QueueNode2();
		Temp->Next->fighter = fighterName;
		Temp->Next->Next = Head;
		Temp->Next->Prev = Temp;
		Head->Prev = Temp->Next;

	}

}
/******************************************************************* 
*                      DeathQueue::get front
* This function returns the value of the node at the front of the DeathQueue
*******************************************************************/
string DeathQueue::getFront() {
	//check to see if head exists
	if (Head != nullptr) {
		return Head->fighter;
	} else {
			return 0;
	}
}

/******************************************************************* 
*                      DeathQueue::remove front
* This function deletes the first node in the DeathQueue.
*******************************************************************/
void DeathQueue::removeFront() {

	//if no nodes exist
	if (isEmpty()) {

		//if one node exists
	} else if (Head->Next == Head) {

		delete Head;
		Head = nullptr;
	//if 2 nodes exist
	} else if (Head->Next->Next == Head) {
		Head = Head->Next;
		Head->Next = Head;
		delete Head->Prev;
		Head->Prev = Head;
	}
	//if 3 or more nodes exist
	else {

		Head = Head->Next;
		Head->Prev = Head->Prev->Prev;
		delete Head->Prev->Next;
		Head->Prev->Next = Head;

	}
		
}

/******************************************************************* 
*                      DeathQueue::print queue
* This function traverses through the queue from head using next pointers, and prints the values of each node in the queue.
*******************************************************************/
void DeathQueue::printQueue() {

	if (Head->Prev != nullptr) {
		cout << Head->Prev->fighter << endl;
		//Create a temporary pointer that will iterate through the list until reaching the pointer before the head.
		QueueNode2* Temp = Head->Prev;
		while (Temp->Prev!=Head->Prev) {
			Temp = Temp->Prev;
			cout << Temp->fighter << endl;
		} 

		cout << endl;
		//if the queue is empty, print that it is empty
	} else {
		cout << "no fighters have fallen." << endl;
	}
	cout << endl;
}



