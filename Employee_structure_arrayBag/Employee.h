#ifndef _EMP
#define _EMP
#include <string>
#include <iostream>
using namespace std;
class Employee 
{
	private:
		string name;
		string department;
		int age;
		string position;
		int id;
	public:
		Employee()
		{
			name = "";
			department = "";
			age = 0;
			position = "";
		}
		Employee(const Employee &obj)
		{
			name = obj.name;
			department = obj.department;
			age = obj.age;
			position = obj.position;
			id = obj.id;
		}
		void setName(string x)
		{
			name = x;
		}
		void setId(int x)
		{
			id = x;
		}
		void setDep(string x)
		{
			department = x;
		}  
		void setAge(int x)
		{
			age = x;
		}
		void setPos(string x)
		{
			position = x;
		}
		string getName()
		{
			return name;
		}
		int getId()
		{
			return id;
		}
		string getDep()
		{
			return department;
		}
		int getAge()
		{
			return age;
		}
		string getPos()
		{
			return position;
		}
		friend istream& operator >>(istream& input, Employee&); //Enter information
		friend ostream& operator <<(ostream&, Employee&);
		bool operator ==(const Employee&) const;
		void operator = (const Employee&);
		bool operator >(const Employee&) const;
		bool operator <(const Employee&) const;
		bool operator >=(const Employee&) const;
		bool operator <=(const Employee&) const;
		//void operator <<(const Employee&) const;

};
#endif