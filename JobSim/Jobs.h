#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <math.h> 
class jobs
{
private:
	int priority;
	int setPriority()//Randomizer

	{
		int temp = rand() % 8 + 1;
		return temp;
	}
	int timeToFix;
	int setTimetoFix()
	{
		int temp = setPriority();
		return pow(temp, temp);
	}
public:
	jobs()
	{
		priority = setPriority();
		timeToFix = setTimetoFix();
	}
	int getPrio()
	{
		return priority;
	}
	int getTime()
	{
		return timeToFix;
	}
	bool operator ==(const jobs&) const;
	//void operator = (const jobs&);
	bool operator >(const jobs&) const;
	bool operator <(const jobs&) const;
	bool operator >=(const jobs&) const;
	bool operator <=(const jobs&) const;
	bool operator !=(const jobs&) const;

};


