#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "ListQueue.h"
#include "Costumer.h"
#include "Market.h"

int main()
{
	srand(time(NULL));
	int size = rand() % 50 + 1;
	Costumer *Buyers = new Costumer[size];
	Market<Costumer> *object = new Market<Costumer>();
	for (int i = 0; i < size; i++)
		object->add(Buyers[i]);
	
	object->endSimulation();
	object->displayData();
	system("pause");
	return 0;
}
/*
Costumer joined the Express with 10 items
Costumer joined the Express with 8 items
Costumer joined the Express with 10 items
Costumer joined the SuperLinne with 2 items
Costumer joined the Standard with 19 items
Costumer joined the Standard with 16 items
Costumer joined the Standard with 20 items
Costumer joined the SuperLinne with 3 items
Costumer joined the Express with 13 items
Costumer left the SUPERLine in 10 timeUnites
Costumer left the SUPERLine in 15 timeUnites
Costumer left the ExpressLine in 50 timeUnites
Costumer left the ExpressLine in 51 timeUnites
Costumer left the ExpressLine in 52 timeUnites
Costumer left the ExpressLine in 65 timeUnites
Costumer left the StandardLine in 95 timeUnites
Costumer left the StandardLine in 96 timeUnites
Costumer left the StandardLine in 100 timeUnites
ECONO
'Donde mejor se compra'
-Mahatma Gandhi
AVerage waiting times:
SuperLine: 12 timeUNITS
ExpressLines: 51 timeUNITS
StandardLine: 91 timeUNITS
Overall: 56.1111
Maximum leangth of eac line:
SuperLine: 2 Costumers
ExpressLines: 4 Costumers
StandardLine: 3 Costumers
Econo recieved:
2 costumers in the SuperLine
4 costumers in the ExpressLine
3 costumers in the StandardLine
For an average of 3 Costumers
Total procesed items:
5 items in the SuperLine
41 items in the ExpressLine
55 items in the StandardLine
For an average of: 33.6667 items
Free time for each counter:
3 timeUNITS in the SuperLine
9 timeUNITS in the ExpressLine
4 timeUNITS in the StandardLine
THATS ALL FOLKS!Press any key to continue . . . 
*/