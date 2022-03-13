#include "Employee.h"

istream& operator >> (istream& in, Employee& obj) //Enter information
{
	cout << "Enter employee's name: ";
	getline(in, obj.name);
	in >> obj.name;
	cout << "Enter employee's ID: ";
	in >> obj.id;
	cout << "Enter employee's age: ";
	in >> obj.age;
	cout << "Enter employee's department: ";
	in >> obj.department;
	cout << "Enter employee's position: ";
	in >> obj.position;
	cout << endl;
	return in;
}
ostream& operator <<(ostream & out, Employee & obj) //Print info
{
	out << obj.getName() << "\t" << obj.getId() << "\t\t" << obj.getDep() << "\t\t" << obj.getPos() << "\t\t" << obj.getAge() << endl;
	return out;
}

bool Employee::operator ==(const Employee& obj) const
{
	if (name == obj.name && department == obj.department && age == obj.age && position == obj.position && id == obj.id)
		return true;
	else
		return false;
}
void Employee::operator = (const Employee& obj)
{
	name = obj.name;
	department = obj.department;
	age = obj.age;
	position = obj.position;
	id = obj.id;
	//return obj;
}
bool Employee::operator >(const Employee& obj) const
{
	if (age > obj.age)
		return true;
	else
		return false;
}
bool Employee::operator <(const Employee& obj) const
{
	if (age > obj.age)
		return true;
	else
		return false;
}
bool Employee::operator >=(const Employee& obj) const
{
	if (age >= obj.age)
		return true;
	else
		return false;
}
bool Employee::operator <=(const Employee& obj) const
{
	if (age <= obj.age)
		return true;
	else
		return false;
}