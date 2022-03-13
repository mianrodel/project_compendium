#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	//static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
	ItemType *items = new ItemType[itemCount + 5];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	vector<ItemType> toVector() const;
	void getPrint() const//Prints contents of items
	{
		for (int i = 0; i < itemCount; i++)
			cout << items[i];
	}
	void organizeArray()//Organizes array/if char or string converts to ASCII
	{
		ItemType number;
		for (int i = 0; i < itemCount; i++) //Read the numbers in the array for re-arrangement
		{
			for (int j = i + 1; j < itemCount; j++) // Assign the value for j from the array
			{
				if (items[j] < items[i]) //Compare j with i within the array
				{
					number = items[i]; // Switch value from i to number
					items[i] = items[j]; // Switch value from i to j
					items[j] = number; //Switch value from j to number
				}
			}
		}

	}
}; // end ArrayBag

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(1000)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	items[itemCount] = newEntry;
	itemCount++;
	return true;

}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
	return false; // STUB
 }  // end remove
*/

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if

	return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
	// STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;       // Current array index
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		}  // end if

		curIndex++;          // Increment to next entry
	}  // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
	  if (anEntry == items[curIndex])
	  {
		 found = true;
	  } // end if

	  curIndex++;           // Increment to next entry
   }  // end while

   return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

	return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
	int result = -1;
	int searchIndex = 0;

	// If the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}  // end if
	}  // end while

	return result;
}  // end getIndexOf



#endif

