#pragma once
#include <iostream> 
#include <assert.h>
using namespace std;
#include "BagInterface.h" 
#include "Node.h" 
#include "Terminos.h"
#include "Polinom.h"
template < class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node 
	int itemCount; // Current count of bag items 
// Returns either a pointer to the node containing a given entry // or the null pointer if the entry is not in the bag. 
	Node<ItemType>* getPointerTo(const ItemType& target) const
	{
		bool found = false;
		Node<ItemType>* curPtr = headPtr;
		while (!found && (curPtr != nullptr))
		{
			if (target.getCoeff() == curPtr->getItem().getCoeff() && target.getExpo() == curPtr->getItem().getExpo())
				found = true;
			else
				curPtr = curPtr->getNext();
		}   // end while 
		return curPtr;
	}
	Node<ItemType>* getPointerToExpo(const ItemType& target) const
	{
		bool found = false;
		Node<ItemType>* curPtr = headPtr;
		while (!found && (curPtr != nullptr))
		{
			if (target.getExpo() == curPtr->getItem().getExpo())
				found = true;
			else
				curPtr = curPtr->getNext();
		}   // end while 
		return curPtr;
	}

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& aBag);
	~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	//Removes the factor with the same exponent
	ItemType extract(const ItemType& anEntry);
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
	//Funcion que Imprima
	void print();
	//Anade un nodo al final de la lista
	void anadido(const ItemType& newEntry, int newPosition);
	//Busca el mayor el ultimo nodo y lo cambia con el nodo del valor entrado, luego borra el ultimo valor
	void moveToLastRemove(const ItemType& Entry);
	//void organize();
	int evaluate();
	Node<ItemType>* getNodeAt(int position) const;
	bool containsExpo(const ItemType& anEntry) const;
}; // end LinkedBag 
//#endif

template < class ItemType>
LinkedBag<ItemType>::LinkedBag()
{
	headPtr = nullptr;
	itemCount = 0;

}
template < class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag->itemCount;
	Node<ItemType>* origChainPtr = aBag->headPtr;
	if (origChainPtr == nullptr)
	{
		headPtr = nullptr;
	}// Original bag is empty; so is copy 
	else
	{         // Copy first node         
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		// Copy remaining nodes         
		Node<ItemType>* newChainPtr = headPtr; // Last-node pointer 
		Node<ItemType>* origPtr;//Change
		while (origPtr != nullptr)
		{
			origChainPtr = origChainPtr->getNext(); // Advance pointer 
			 // Get next item from original chain            
			ItemType nextItem = origChainPtr->getItem();
			// Create a new node containing the next item            
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			// Copy constructor
			  // Link new node to end of new chain             
			newChainPtr->setNext(newNodePtr);
			// Advance pointer to new last node             
			newChainPtr = newChainPtr->getNext();
		}   // end while 
		newChainPtr->setNext(nullptr); // Flag end of new chain    
	}   // end if } 

}
template < class ItemType>
LinkedBag<ItemType>::~LinkedBag()//virtual
{
	clear();
}
template < class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const//virtual
{
	return itemCount;
}
template < class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}
template < class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr); // New node points to chain     
	headPtr = newNodePtr;         // New node is now first node     
	itemCount++;
	cout << "Added\n";
	return true;
	
}
template < class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem)
	{
		// Copy data from first node to located node         
		entryNodePtr->setItem(headPtr->getItem());
		// Delete first node         
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		// Return node to the system         
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
	}   // end if 
	return canRemoveItem;
}
template < class ItemType>
void LinkedBag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		// Return node to the system   
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}  // end while  // headPtr is nullptr; nodeToDeletePtr is nullptr 

	itemCount = 0;
}
template < class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}
template < class ItemType>
bool LinkedBag<ItemType>::containsExpo(const ItemType& anEntry) const
{
	return (getPointerToExpo(anEntry) != nullptr);
}
template < class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0; int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{

		if (anEntry.getExpo() == curPtr->getItem().getExpo())
		{
			frequency++;
		}   // end if 
		counter++;
		curPtr = curPtr->getNext();
	}   // end while 
	return frequency;

}
template < class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}   // end while 
	return bagContents;  // end toVector

}
template < class ItemType>
void LinkedBag<ItemType>::print()
{
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (counter < itemCount - 1)
			cout << curPtr->getItem().getCoeff() << "(x)^" << curPtr->getItem().getExpo() << " + ";
		else
			cout << curPtr->getItem().getCoeff() << "(x)^" << curPtr->getItem().getExpo();
		curPtr = curPtr->getNext();
		counter++;
	}   // end while 

}
template < class ItemType>
void LinkedBag<ItemType>::moveToLastRemove(const ItemType& Entry)
{
	Node<ItemType>* target = getPointerTo(Entry);
	Node <ItemType>* current = headPtr;
	Node <ItemType>* next = current->getNext();
	while (next != nullptr)
	{
		current = next;
		next = current->getNext();
	}
	ItemType temp;
	temp = target->getItem();
	target->getItem() = current->getItem();
	current->getItem() = temp;
	remove(temp);
}
template < class ItemType>
void  LinkedBag<ItemType>::anadido(const ItemType& newEntry, int newPosition)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		cout << "Inserting!\n";
		// Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		// Attach new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}  // end if

		itemCount++;  // Increase count of entries
	}  // end if

}  // end insert
//Cambiar linked
template < class ItemType>
int LinkedBag<ItemType>::evaluate()
{
	/*
	int x;
	cout << "Enter a number to be evaluated: ";
	cin >> x;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0, sum = 0;
	ItemType *array = new ItemType[itemCount];
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		sum = sum + curPtr->getItem().getCoeff() * pow(x, curPtr->getItem().getExpo());
		counter++;
	}
	*/
	return 0;
}
template < class ItemType>
ItemType LinkedBag<ItemType>::extract(const ItemType& anEntry)
{
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{

		if (anEntry.getExpo() == curPtr->getItem().getExpo())
		{
			return curPtr->getItem();
		}   // end if 
		counter++;
		curPtr = curPtr->getNext();
	}   // end while 
}
template < class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}