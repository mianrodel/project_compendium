#pragma once
#include <iostream>
using namespace std;
#include "Jobs.h"
#include "SL_PriorityQueue.h"

class JobTaker
{
	private:
		int time = 0;
		int timePerJob = 0;
		int jobsdone = 0;
		int exit = 0;
		SL_PriorityQueue<jobs> *object;
	public:
		JobTaker()
		{
			object = new SL_PriorityQueue<jobs>();
		}
		void JobProcces(jobs& obj)
		{
			object->enqueue(obj);
			cout << "New job has been added to queue, currently at position: " << object->position(obj) << endl;
			
			time++;
			timePerJob++;
			jobsdone++;
			if (time >= object->peekFront().getTime())
			{
				object->dequeue();
				cout << "Job completed" << endl;
				timePerJob = 0;
			}
		}
		void emptyQueue()
		{
			
			while (!(object->isEmpty()))
			{
				time++;
				timePerJob++;
				if (time >= object->peekFront().getTime())
				{
					object->dequeue();
					cout << "Job completed" << endl;
					timePerJob = 0;
				}
			}
		}
		void print()
		{
			cout << "Total time to complete process: " << time << endl;
			cout << "Total jobs Proccesed: " << jobsdone << endl;
		}

};























