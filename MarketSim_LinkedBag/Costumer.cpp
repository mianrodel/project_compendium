#include "Costumer.h"
Costumer::Costumer()
{
	max_items = 30;
	itemsBrought = setItemsrand();
	time = itemsBrought * 5;
}
int Costumer::setItemsrand()
{
	int temp;
	temp = rand() % 30 + 1;
	return temp;
}
int Costumer::getTime()
{
	return time;
}
void Costumer::setItems(int a)
{
	itemsBrought = a;
}
void Costumer::setMax(int a)
{
	max_items = a;
}
int Costumer::getItems()
{
	return itemsBrought;
}
int Costumer::getMax()
{
	return max_items;
}
bool Costumer::operator <=(Costumer& entry)
{
	if (this->itemsBrought <= entry.getItems())
		return true;
	else
		return false;
}
bool Costumer::operator >=(Costumer& entry)
{
	if (this->itemsBrought >= entry.getItems())
		return true;
	else
		return false;
}
bool Costumer::operator ==(Costumer& entry)
{
	if (this->itemsBrought == entry.getItems())
		return true;
	else
		return false;
}
bool Costumer::operator >(Costumer& entry)
{
	if (this->itemsBrought > entry.getItems())
		return true;
	else
		return false;
}
bool Costumer::operator <(Costumer& entry)
{
	if (this->itemsBrought < entry.getItems())
		return true;
	else
		return false;
}