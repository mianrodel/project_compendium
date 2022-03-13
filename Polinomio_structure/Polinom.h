#pragma once
#include<iostream>
#include <assert.h>
using namespace std;
#include "Terminos.h"
#include "LinkedBag.h"
//template<class ItemType>
class poli
{
private:
	LinkedBag <term>* bagPtr = new LinkedBag<term>();
public:
	poli();
	int getSize() const;
	void add1(term&);
	void eliminate(term&);
	int eval(int);
	void display();
};
poli::poli()
{
	//bagPtr = new LinkedBag<term>();
}

int poli::getSize() const
{
	return bagPtr->getCurrentSize();
}
void poli::add1(term& entry)
{
	if (bagPtr->containsExpo(entry))
	{
		term obj, object = bagPtr->extract(entry);
		obj.setCoeff(entry.getCoeff() + object.getCoeff());
		obj.setExpo(entry.getExpo());
		entry = obj;
		bagPtr->remove(bagPtr->extract(entry));
	}
	if (bagPtr->getCurrentSize() == 0)
	{
		bagPtr->add(entry);
	}
	else
	{
		
		int i = 1;
		if (bagPtr->getNodeAt(i)->getItem().getExpo() < entry.getExpo())
		{

			bagPtr->anadido(entry, i);
		}

		else if (bagPtr->getNodeAt(i)->getItem().getExpo() > entry.getExpo() && bagPtr->getNodeAt(i + 1)->getItem().getExpo() < entry.getExpo())
		{
			bagPtr->anadido(entry, i + 1);
	
		}
		else
		{
			bagPtr->anadido(entry, bagPtr->getCurrentSize() + 1);
		}
		i++;
		
	}
}

void poli::eliminate(term& entry)
{
	bagPtr->remove(entry);
}

int poli::eval(int x)
{

	int sum = 0;
	for (int i = 0; i < bagPtr->getCurrentSize(); i++)
	{
		sum = sum + bagPtr->getNodeAt(i + 1)->getItem().getCoeff() * pow(x, bagPtr->getNodeAt(i + 1)->getItem().getExpo());
	}
	return sum;
}

void poli::display()
{
	for (int i = 0; i < bagPtr->getCurrentSize(); i++)
	{
		if (i < bagPtr->getCurrentSize() - 1)
			cout << bagPtr->getNodeAt(i + 1)->getItem().getCoeff() << "(x)^" << bagPtr->getNodeAt(i + 1)->getItem().getExpo() << " + ";
		else
			cout << bagPtr->getNodeAt(i + 1)->getItem().getCoeff() << "(x)^" << bagPtr->getNodeAt(i + 1)->getItem().getExpo();
	}
}