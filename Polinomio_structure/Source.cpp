#include <iostream>
using namespace std;
#include "Polinom.h"
#include "Terminos.h"
int main()
{
	term obj1;
	int coeff, expo, entry, x = 1, choice, evaluate;
	poli obj;
	cout << "Enter the number of terms: ";
	cin >> entry;
	for (int i = 0; i < entry; i++)
	{
		cout << "Enter the coeff: ";
		cin >> coeff;
		obj1.setCoeff(coeff);
		cout << "Enter the expo: ";
		cin >> expo;
		obj1.setExpo(expo);
		obj.add1(obj1);
	}
	obj.display();
	while (x == 1)
	{
		cout << "\nWhat would you like to do?";
		cout << "\n1) Evaluate\n";
		cout << "2) Add";
		cout << "\n3) Remove";
		cout << "\n4) Exit\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter number you wish to evaluate: ";
			cin >> evaluate;
			cout << obj.eval(evaluate) << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter the coeff: ";
			cin >> coeff;
			obj1.setCoeff(coeff);
			cout << "Enter the expo: ";
			cin >> expo;
			obj1.setExpo(expo);
			obj.add1(obj1);
			obj.display();
		}
		else if (choice == 3)
		{
			cout << "Enter the coeff you would like to remove: ";
			cin >> coeff;
			obj1.setCoeff(coeff);
			cout << "Enter the expo you would like to remove: ";
			cin >> expo;
			obj1.setExpo(expo);
			obj.eliminate(obj1);
			obj.display();
		}
		else if (choice == 4)
			x = 0;
	}
	system("pause");
	return 0;
}
/*
Enter the number of terms: 3
Enter the coeff: 3
Enter the expo: 4
Added
Enter the coeff: 5
Enter the expo: 6
Inserting!
Enter the coeff: 7
Enter the expo: 8
Inserting!
7(x)^8 + 5(x)^6 + 3(x)^4
What would you like to do?
1) Evaluate
2) Add
3) Remove
4) Exit
2
Enter the coeff: 6
Enter the expo: 6
Inserting!
7(x)^8 + 11(x)^6 + 3(x)^4
What would you like to do?
1) Evaluate
2) Add
3) Remove
4) Exit
1
Enter number you wish to evaluate: 2
2544

What would you like to do?
1) Evaluate
2) Add
3) Remove
4) Exit
3
Enter the coeff you would like to remove: 11
Enter the expo you would like to remove: 6
7(x)^8 + 3(x)^4
What would you like to do?
1) Evaluate
2) Add
3) Remove
4) Exit
1
Enter number you wish to evaluate: 1
10

What would you like to do?
1) Evaluate
2) Add
3) Remove
4) Exit
4
Press any key to continue . . .
*/