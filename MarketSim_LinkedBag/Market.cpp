#include <iostream>
using namespace std;
#include "Market.h"
/*
template < class ItemType>
Market<ItemType>::Market()
{
	
	SuperLine = new ListQueue<ItemType>();
	ExpressLine = new ListQueue<ItemType>();
	ExpressLine2 = new ListQueue<ItemType>();
	StandardLine = new ListQueue<ItemType>();
	
	time = 0;
	timeSuper = 0;
	timeExp = 0;
	timeStd = 0;
	//Used Vars
	counter=0;
	//Variables used to find the max lenght of each line
	currentSuper=0;
	maxSuper=0;
	currentExpress=0;
	maxExpress=0;
	currentStandard=0;
	maxStandard=0;
	//Variable used to add up wiating times fro average
	superWait=0;
	expressWait=0;
	standardWait=0;
	//Amounts in each ExpressLine
	line1=0;
	line2=0;
	//Variables para calcular la dta final.
	expWaiting=0;
	expCostumers=0;
	supWaiting=0;
	supCostumers=0;

	stanWaiting=0;
	stanCostumers=0;

	superItems=0;
	expressItems=0;
	stanItems=0;

	freeSuper=0;
	freeExpress=0;
	freeStan = 0;
}
//Calls the simulation function which adds the time
template < class ItemType>
void Market<ItemType>::add(ItemType& entry)
{
	counter++;
	if (entry.getItems() <= 5)
	{
		SuperLine->enqueue(entry);
		supCostumers++;
		currentSuper++;
		superItems = entry.getItems() + superItems;
		if (currentSuper > maxSuper)
			maxSuper = currentSuper;
		runSimulation();
	}
	else if (entry.getItems() <= 15 && entry.getItems() > 5)
	{
		if (line1 >= line2)
		{
			ExpressLine->enqueue(entry);
		}
		else
		{
			ExpressLine2->enqueue(entry);
			
		}
		expCostumers++;
		currentExpress++;
		if (currentExpress > maxExpress)
			maxExpress = currentExpress;
		expressItems = entry.getItems() + expressItems;
		runSimulation();
	}
	else if (entry.getItems() > 15)
	{
		StandardLine->enqueue(entry);
		stanCostumers++;
		stanItems = entry.getItems() + stanItems;
		if (currentStandard > maxStandard)
			maxStandard = currentStandard;
		runSimulation();
	}

}
//Runs simulation, removes costumers if necesarry and counts total free time
template < class ItemType>
void Market<ItemType>::runSimulation()
{
	//Time increase
	time++;
	//These ifs remove someone frome the queue if 
	//enough time passed
	if (!(SuperLine->isEmpty()))
	{
		if (SuperLine->peekFront().getTime() == time)
		{
			SuperLine->dequeue();
			currentSuper--;
			counter--;
		}
	}
	if (!(ExpressLine->isEmpty()))
	{
		if (ExpressLine->peekFront().getTime() == time)
		{
			ExpressLine->dequeue();
			line1--;
			currentExpress--;
			counter--;
		}
	}
	if (!(ExpressLine2->isEmpty()))
	{
		if (ExpressLine2->peekFront().getTime() == time)
		{
			ExpressLine2->dequeue();
			line2--;
			currentExpress--;
			counter--;
		}
	}
	if (!(StandardLine->isEmpty()))
	{
		if (StandardLine->peekFront().getTime() == time)
		{
			StandardLine->dequeue();
			currentStandard--;
			counter--;
		}
	}

	//Add a unit to a variable if the counter is free
	if (SuperLine->isEmpty())
	{
		freeSuper++;
	}
	if (ExpressLine->isEmpty())
	{
		freeExpress++;
	}
	if (ExpressLine2->isEmpty())
	{
		freeExpress++;
	}
	if (StandardLine->isEmpty())
	{
		freeStan++;
	}
}
//Displays the supermarkets results
template < class ItemType>
void Market<ItemType>::displayData()
{
	cout << "ECONO\n'Donde mejor se compra'\n-Mahatma Gandhi\n";
	cout << "AVerage waiting times: \n";
	cout<< "SuperLine: " << (superItems * 5) / supCostumers << "timeUNITS\n";
	cout << "ExpressLines: " << (expressItems * 5) / expCostumers << "timeUNITS\n";
	cout << "StandardLine: " << (stanItems * 5) / stanCostumers << "timeUNITS\n";
	cout << "Overall: " << ((superItems * 5) + (expressItems * 5) + (stanItems * 5)) / double(supCostumers + expCostumers + stanCostumers) << endl;
	cout << "Maximum leangth of eac line: \n";
	cout << "SuperLine: " << maxSuper << " Costumers\n";
	cout << "ExpressLines: " << maxExpress << " Costumers\n";
	cout << "StandardLine: " << maxStandard << " Costumers\n";
	cout << "Econo recieved:\n";
	cout << supCostumers << " costumers in the SuperLine\n";
	cout << expCostumers << " costumers in the ExpressLine\n";
	cout << stanCostumers << " costumers in the StandardLine\n";
	cout << "For an average of " << (supCostumers + expCostumers + stanCostumers) / 3.0 << " Costumers";
	cout << "Total procesed items: \n";
	cout << superItems << " items in the SuperLine\n";
	cout << expressItems << " items in the ExpressLine\n";
	cout << superItems << " items in the StandardLine\n";
	cout << "For an average of: " << (superItems + expressItems + superItems) / 3.0 << " items";
	cout << "Free time for each counter: \n";
	cout << freeSuper << " timeUNITS in the SuperLine\n";
	cout << freeExpress << " timeUNITS in the ExpressLine\n";
	cout << freeStan << " timeUNITS in the StandardLine\n";
	cout << "THATS ALL FOLKS!";

}
//Empties lines to end simulation
template < class ItemType>
void Market<ItemType>::endSimulation()
{
	while (counter != 0)
	{
		if (!(SuperLine->isEmpty()))
		{
			if (SuperLine->peekFront().getTime() == time)
			{
				SuperLine->dequeue();
				currentSuper--;
				counter--;
			}
		}
		if (!(ExpressLine->isEmpty()))
		{
			if (ExpressLine->peekFront().getTime() == time)
			{
				ExpressLine->dequeue();
				line1--;
				currentExpress--;
				counter--;
			}
		}
		if (!(ExpressLine2->isEmpty()))
		{
			if (ExpressLine2->peekFront().getTime() == time)
			{
				ExpressLine2->dequeue();
				line2--;
				currentExpress--;
				counter--;
			}
		}
		if (!(StandardLine->isEmpty()))
		{
			if (StandardLine->peekFront().getTime() == time)
			{
				StandardLine->dequeue();
				currentStandard--;
				counter--;
			}
		}
	}
}
*/