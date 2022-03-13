#ifndef _COSTUMER
#define _COSTUMER
#include <stdlib.h>
#include <time.h>
class Costumer
{
	private:
		int max_items;
		int itemsBrought;
		int time;	
		int setItemsrand();
	public:
		Costumer();
		void setItems(int a);
		void setMax(int a);
		int getItems();
		int getMax();
		int getTime();
		bool operator <=(Costumer& entry);
		bool operator >=(Costumer& entry);
		bool operator ==(Costumer& entry);
		bool operator >(Costumer& entry);
		bool operator <(Costumer& entry);
}; 
#endif