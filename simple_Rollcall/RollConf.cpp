#include <string>
#include <iostream>
using namespace std;
int idConfirm(int);
class Student
{
private:
	string name;
	int studentId;
	double studentScore;
	/*
	name = Nombre del estudiante
	studentId = Id del estudiante
	studentScore = Puntuacion del estudiante
	*/
public:
	//Seran descritas en su implementacion
	Student();
	Student(string, int, double);
	void setName(string);
	void setId(int);
	void setScore(double);
	string getName();
	int getId();
	double getScore();
	void getData();
};
Student::Student()
{
	name = '\0';
	studentId = 0;
	studentScore = 0;
}
//Overloaded constructor
Student::Student(string n, int I, double S)
{
	name = n;
	studentId = I;
	studentScore = S;
}
//Setter
void Student::setName(string n)
{
	name = n;
}
//Setter
void Student::setId(int I)
{
	studentId = I;
}
//Setter
void Student::setScore(double S)
{
	studentScore = S;
}
string Student::getName()
{
	return name;
}
//Retorna studentId
int Student::getId()
{
	return studentId;
}
//Retorna Score
double Student::getScore()
{
	return studentScore;
}
//Impprime la data guardada en las variables
void Student::getData()
{
	//Determina la nota que sera presentada al lado del la puntuacion
	string grade;
	if (studentScore >= 93.0)
		grade = "A";
	else if (studentScore >= 90.0 && studentScore <= 92.0)
		grade = "A+";
	else if (studentScore >= 87.0 && studentScore <= 89)
		grade = "B+";
	else if (studentScore >= 83 && studentScore <= 86)
		grade = "B";
	else if (studentScore >= 80 && studentScore <= 82)
		grade = "B-";
	else if (studentScore >= 77 && studentScore <= 79)
		grade = "C+";
	else if (studentScore >= 73 && studentScore <= 76)
		grade = "C";
	else if (studentScore >= 70 && studentScore <= 72)
		grade = "C-";
	else if (studentScore >= 67 && studentScore <= 69)
		grade = "D+";
	else if (studentScore >= 60 && studentScore <= 66)
		grade = "D";
	else if (studentScore >= 0 && studentScore <= 59)
		grade = "F";
	cout << name << "\t\t" << studentId << "\t\t" << studentScore << "/" << grade << endl << endl;
}
int main()
{
	const int amStudents = 5;
	//amStudent = candtidad de miembros en el object array 
	int opc, id;
	/*
	opc = Opcion del menu principal
	id = id del estudiante que desea anadir, eliminar o imprimir sus datos
	*/
	string name;
	//name = nombre del estudiante
	double score, scoreSum = 0.0, e = 0.0;
	/*
	score = puntuacion del estudiante en las pruebas
	scoreSum = Obtiene los valores de todas las pruebas para obtener promedio
	*/

	Student St[amStudents] = { Student("Miguel A. Rodriguez", 120383, 100.0),
							  Student("Ramon J. Ortiz", 787448, 78),
							  Student("Jessica Delgado", 719321, 60),
							  Student("Federico Delfin", 567432, 87)
	};
	//Loop del menu principal
	do
	{
		cout << "Enter a number based on the following choices:\n";
		cout << "1. Display a students data based on Id\n";
		cout << "2. Enter the data for a new student\n";
		cout << "3. Remove a student\n";
		cout << "4. Display the class average\n";
		cout << "5. Exit\n";
		cin >> opc;
		while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5)
		{
			cout << "Invalid number, please re-enter: ";
			cin >> opc;
		}
		if (opc == 1)
		{
			//Busca al estudiante basado en Id
			cout << "Enter and Id number: ";
			cin >> id;
			//Exepcion Handle
			id = idConfirm(id);
			if (id == St[0].getId())
				St[0].getData();
			else if (id == St[1].getId())
				St[1].getData();
			else if (id == St[2].getId())
				St[2].getData();
			else if (id == St[3].getId())
				St[3].getData();
			else if (id == St[4].getId())
				St[4].getData();
			else
				cout << "No student matches the Id Provided\n";
			id = 0;
		}
		else if (opc == 2)
		{
			//Loop busca el espacio vacio en el array de objetos
			for (int i = 0; i < 5; i++)
			{
				//Se llena el espacio vacio
				if (St[i].getId() == 0)
				{
					cout << "Enter the students name: ";
					cin >> name;
					St[i].setName(name);
					cout << "Enter the sudents Id: ";
					cin >> id;
					//Exepcion handle
					id = idConfirm(id);
					St[i].setId(id);
					cout << "Enter the sudents score: ";
					cin >> score;
					St[i].setScore(score);
					break;
				}
			}
		}
		//Resetea el objeto de el estudiante seleccionado
		else if (opc == 3)
		{
			cout << "Enter the id of the student you would like to remove: ";
			cin >> id;
			//Exepcion Handle
			id = idConfirm(id);
			if (id == St[0].getId())
			{
				St[0].setId(0);
				St[0].setName("");
				St[0].setScore(0.0);
			}
			else if (id == St[1].getId())
			{
				St[1].setId(0);
				St[1].setName("");
				St[1].setScore(0.0);
			}
			else if (id == St[2].getId())
			{
				St[2].setId(0);
				St[2].setName("");
				St[2].setScore(0.0);
			}
			else if (id == St[3].getId())
			{
				St[3].setId(0);
				St[3].setName("");
				St[3].setScore(0.0);
			}
			else if (id == St[4].getId())
			{
				St[4].setId(0);
				St[4].setName("");
				St[4].setScore(0.0);
			}
			else
				cout << "No student matches the Id Provided\n";
			id = 0;
		}
		//Suma todos las puntuaciones y luego saca promedio
		else if (opc == 4)
		{
			cout << "The class Average is: ";
			for (int i = 0; i < 5; i++)
			{
				scoreSum += St[i].getScore();
			}
			//Cuenta la cantidad de espacios llenos para luego usar el numero resultante
			for (int i = 0; i < 5; i++)
			{
				if (St[i].getId() != 0)
					e++;
			}
			cout << scoreSum / e << endl << endl;
		}
	} while (opc != 5);
	system("pause");
	return 0;
}
//Exepcion function
int idConfirm(int id)
{
	if (id < 0)
	{
	
		cout << "Id must be possitive int: ";
		cin >> id;
	}
	return id;
}
/*
Enter a number based on the following choices:
1. Display a students data based on Id
2. Enter the data for a new student
3. Remove a student
4. Display the class average
5. Exit
1
Enter and Id number: -120383
Id must be possitive int: 120383
Miguel A. Rodriguez             120383          100/A

Enter a number based on the following choices:
1. Display a students data based on Id
2. Enter the data for a new student
3. Remove a student
4. Display the class average
5. Exit
5
Press any key to continue . . .
*/