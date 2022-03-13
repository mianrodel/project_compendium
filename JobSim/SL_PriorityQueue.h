#pragma once
#include <iostream>
using namespace std;
#include "QueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public QueueInterface<ItemType>
{
private:
	LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
									  // items in the priority queue
public:
	SL_PriorityQueue()
	{
		slistPtr = new LinkedSortedList<ItemType>();
	}
	SL_PriorityQueue(const SL_PriorityQueue& pq)
	{

	}
	~SL_PriorityQueue()
	{

	}
	bool isEmpty() const
	{
		return slistPtr->getLength() == 0;
	}
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const //throw(PrecondViolatedExcep)
	{
		return slistPtr->getEntry(1);
	}
	int position(const ItemType& Entry)
	{
		return slistPtr->getPosition(Entry);
	}
	/** @throw PrecondViolatedExcep if priority queue is empty. */
	ItemType peek() const //throw(PrecondViolatedExcep)
	{
		return slistPtr->getEntry(1);
	}
}; // end SL_PriorityQueue

 //@file SL_PriorityQueue.cpp 

template<class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}  // end add

template<class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
	// The highest priority item is at the end of the sorted list
	return slistPtr->remove(slistPtr->getLength());
}  // end remove

