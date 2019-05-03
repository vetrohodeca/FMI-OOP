#include<iostream>

#define MAXSIZE 50
using namespace std;
class Person {
private:
	int age;
	char* name;
public:
	Person() {
		this->name = new char[MAXSIZE];
	}
	int getAge() const
	{
		return age;
	}
	char* getName() const
	{
		return name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	void setName(char* name)
	{
		this->name = new char[strlen(name)+1];//mamito
		strcpy_s(this->name, MAXSIZE, name);
	}
	void printPersonList(Person p)
	{
		cout << p.getName() << " - " << p.getAge() << endl;
	}
	Person(int age, char* name)
	{
		setAge(age);
		setName(name);
	}
	void swapTwoPersons(Person* p, int index1, int index2)
	{
		int tempAge;
		char* temp=new char[MAXSIZE];
		if (strlen(p[index1].name) >= strlen(p[index2].name))
		{
			char* temp = new char[strlen(p[index1].name+1)];
		}
		else
		{
			char* temp = new char[strlen(p[index2].name+1)];
		}
		tempAge = p[index1].age;
		p[index1].age = p[index2].age;
		p[index2].age = tempAge;
		strcpy_s(temp ,MAXSIZE ,p[index1].name);
		strcpy_s(p[index1].name ,MAXSIZE, p[index2].name);
		strcpy_s(p[index2].name ,MAXSIZE, temp);
		delete[]temp;
	}
};
int main()

{

	int N;
	cout << "N: ";
	cin >> N;
	Person* personList = new Person[N + 1];
	for (int i = 0; i < N; i++)
	{
		int age;
		cout << "Age: ";
		cin >> age;
		cin.ignore(1, EOF);
		char* name = new char[40];
		cout << "Name: ";
		cin >> name;
		personList[i] = Person(age, name);
		/*
		cout << "Age: ";
		cin >> age;
		cin.ignore(1, EOF);
		personList[i].setAge(age);
		cout << "Name: ";
		cin.getline(name, 49);
		personList[i].setName(name);*/
	}
	for (int i = 0; i < N; i++)
	{
		if (personList[i].getAge() < 30)
		{
			personList[i].setAge(-1);
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (strcmp(personList[i].getName(), personList[j].getName()) > 0)//функция са ебава нещо
			{
				personList->swapTwoPersons(personList, i, j);
			}
		}
	}
	cout << endl;
for (int i = 0; i < N; i++)
{
	if (personList[i].getAge() != -1)
	{
		personList->printPersonList(personList[i]);// тука фърга грешка  
	}
}

delete[]personList;

system("Pause");
return 0;
}