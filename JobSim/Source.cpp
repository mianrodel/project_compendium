#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Jobs.h"
#include "LinkedSortedList.h"
#include "JobTaker.h"
int main()
{

	
	srand(time(NULL));
	int jobAmount = rand() % 50 + 1;
	jobs* inserts = new jobs[jobAmount];
	JobTaker obj;
	for (int i = 0; i < jobAmount; i++)
	{
		obj.JobProcces(inserts[i]);
	}
	obj.emptyQueue();
	obj.print();


	system("pause");
	return 0;
}
/*
New job has been added to queue, currently at position: 1
New job has been added to queue, currently at position: 1
New job has been added to queue, currently at position: 3
New job has been added to queue, currently at position: 4
Job completed
New job has been added to queue, currently at position: 3
Job completed
New job has been added to queue, currently at position: 1
Job completed
New job has been added to queue, currently at position: 4
Job completed
New job has been added to queue, currently at position: 4
Job completed
New job has been added to queue, currently at position: 4
Job completed
New job has been added to queue, currently at position: 4
Job completed
Job completed
Job completed
Job completed
Total time to complete process: 13
Total jobs Proccesed: 10
Press any key to continue . . .
*/
