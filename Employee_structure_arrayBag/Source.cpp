#include <iostream>
#include <string>
#include "Employee.h"
#include "ArrayBag.h"
int main()
{
	int x = 0, size, age, id;
	string name, dep, position;
	cout << "How many employees would you like to register?: ";
	cin >> size;
	Employee obj;
	ArrayBag<Employee> *bag = new ArrayBag<Employee>;
	for (int i = 0; i < size; i++)
	{
		cin >> obj;
		bag->add(obj);
	}
	bag->organizeArray();
	cout << "Employees will ber organized from oldest to youngest: \n";
	cout << "Name\tID Number\tDepartment\tPosition\tAge" << endl;
	bag->getPrint();
	system("pause");
	return 0;
}
/*
How many employees would you like to register?: 5
Enter employee's name: Miguel
Enter employee's ID: 123456
Enter employee's age: 19
Enter employee's department: IngComp
Enter employee's position: Student

Enter employee's name: Angel
Enter employee's ID: 239439
Enter employee's age: 20
Enter employee's department: IngComp
Enter employee's position: Student

Enter employee's name: Obama
Enter employee's ID: 838832
Enter employee's age: 47
Enter employee's department: ExPrez
Enter employee's position: Prez

Enter employee's name: Trump
Enter employee's ID: 123456
Enter employee's age: 67
Enter employee's department: WhiteH
Enter employee's position: Prez

Enter employee's name: Jan
Enter employee's ID: 345678
Enter employee's age: 45
Enter employee's department: HR
Enter employee's position: Representative

Employees will ber organized from oldest to youngest:
Name    ID Number       Department      Position        Age
Trump   123456          WhiteH          Prez            67
Obama   838832          ExPrez          Prez            47
Jan     345678          HR              Representative          45
Angel   239439          IngComp         Student         20
Miguel  123456          IngComp         Student         19
Press any key to continue . . .
*/