#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#define MAXSIZE 50
using namespace std;
class Employee {
private:
	char* name;
	int age;
	char* postion;
	char*email;
	double salary;
public:
	int getSalary()const
	{
		return salary;
	}
	int getAge()const
	{
		return age;
	}
	
	Employee(const char* name,  const char* position,const  char* email, int age, double salary)
	{
		this->name = new char[strlen(name)+1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->email = new char[strlen(email)+1];
		strcpy_s(this->email, strlen(email) + 1, email);
		this->postion = new char[strlen(position)+1];
		strcpy_s(this->postion, strlen(position) + 1, position);
		this->age = age;
		this->salary = salary;
	}
	char* getPosition()
	{
		return postion;
	}
	Employee()
	{
		name = new char[51];
		strcpy_s(this->name, MAXSIZE, "No name");
		email = new char[51];
		strcpy_s(this->email, MAXSIZE, "No mail");
		postion = new char[51];
		strcpy_s(this->postion, MAXSIZE, "No pos");
		this->age = 0;
		this->salary = 0;
	}
	void printEmployee(Employee E)
	{
		cout << "Name: " << E.name << endl;
		cout << "Position: " << E.postion << endl;
		cout << "E-mail: " << E.email << endl;
		cout << "Age: " << E.age << endl;
		cout << "Salary: " <<fixed<< setprecision(2)<< E.salary << endl;
	}
	char* searchHighestPrice(Employee* E, int N)// return section 
	{
 		int maxSalary = 0;
		char Section[MAXSIZE] ;
		for (int i = 0; i < N; i++)
		{
			if (E[i].salary > maxSalary)
			{
				maxSalary = E[i].salary;
				strcpy_s(Section[i],strlen(Section[i]) ,E[i].postion);
			}
		}
		return Section;
	}
	void sortBysalaries(Employee*E, int N)
	{
		Employee tempEmployee;
		for (int i = 0; i <  N-1; i++)
		{
			for(int j=i+1;j<N;j++)
				if (E[i].salary < E[j].salary)
				{
					tempEmployee = E[i] ;
					E[i] = E[j];
					E[j] = tempEmployee;
				}
		}
	}
};
int main()
{
	int N;
	cin >> N;
	Employee* employeeList = new Employee[N];
	char name[MAXSIZE];
	char position[MAXSIZE];
	char email[MAXSIZE];
	int age;
	double salary;
	for (int i = 0; i < N; i++)
	{
		cout << "Name: " << endl;
		cin.ignore();
		cin.getline(name, MAXSIZE);
		cout << "Position: " << endl;
		cin >> position;
		cout << "E-mail: " << endl;
		cin >> email;
		cout << "Age: " << endl;
		cin >> age;
		cout << "Salary: " << endl;
		cin >> salary;
		employeeList[i] = Employee(name, position, email, age, salary);
	}
	char* highPaidSector= new char[30];// presmqtame koi shte e visokoplateniq sektor
	highPaidSector = employeeList->searchHighestPrice(employeeList, N);
	employeeList[0].printEmployee(employeeList[0]);
	employeeList->sortBysalaries(employeeList, N  );
	//sortirame po zaplata nizhodqshto
	for (int i = 0; i < N; i++)// printim samo ot visokoplateniq sektor
	{
		if (strcmp(highPaidSector, employeeList[i].getPosition()) == 0)
		{
			employeeList[i].printEmployee(employeeList[i]);
		}
	}
	delete[]employeeList;
	system("pause");
	return 0;
}