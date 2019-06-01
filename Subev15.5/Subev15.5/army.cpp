#include "Header.h"
#include<iostream>
#define MAXSOLIDERNAME 50
#pragma warning (disable:4996)

// PRI SETERI VINAGI CONST PARAMETRI
using namespace std;
Solder::Solder()
{
	setName("");
	setSkills(0);
	setSalary(0);
}
Solder::Solder(const char* name, int combatSkills, unsigned int salary)
{
	setName(name);
	setSkills(combatSkills);
	setSalary(salary);
}
void Solder::CopyFrom(const Solder &other)
{
	this->combatSkills = other.combatSkills;
	this->salary = other.salary;
	int len = strlen(other.name);
	this->name = new char[len + 1];
	strcpy(this->name, other.name);
}
void Solder::setName(const char*name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
void Solder::setSalary(unsigned int salary)
{
	this->salary = salary;
}
void Solder::setSkills(int skills)
{
	this->combatSkills = skills;
}
Solder::Solder(const Solder& other)
{
	Solder::CopyFrom(other);
}
Solder& Solder::operator=(const Solder& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
void Solder::Free()
{
	delete[]name;
}
Solder::~Solder()
{
	Free();
}
void Solder::print()
{
	cout << "Solider name: " << name << endl << "Solider skills: " << combatSkills << endl << "Solider Salary: " << salary << endl;
}

void Commander::setName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
void Commander::setSalary(unsigned int salary)
{
	this->salary = salary;
}
void Commander::setSkills(int skills)
{
	this->combatSkills = skills;
}
void Commander::setNumberOfSolders(int number)
{
	this->numberOfSolders = number;
}
void Commander::Free()
{
	delete[] name;
	for (size_t i = 0; i < numberOfSolders; i++)
	{
		delete[] solderList[i];
	}
	delete[] solderList;
}
void Commander::CopyFrom(const Commander& other)
{
	this->combatSkills = other.combatSkills;
	this->salary = other.salary;
	this->numberOfSolders = other.numberOfSolders;
	int len = strlen(other.name);
	this->name = new char[len + 1];
	strcpy(this->name, other.name);
}
Commander::Commander(const char*name, int skills, unsigned int salary, int numberOfSoliders, bool difference)
{
	setName(name);
	setSkills(skills);
	setSalary(salary);
	setNumberOfSolders(numberOfSoliders);
	solderList = new Solder*[numberOfSoliders];
}
Commander::Commander(const char*name, int skills, unsigned int salary, int number)
{
	setName(name);
	setSkills(skills);
	setSalary(salary);
	setNumberOfSolders(number);
	solderList = new Solder*[number];
		for (size_t i = 0; i < number; i++)
		{
			cout << i + 1 << " solider" << endl;
			char solderName[50];
			int solderCombatSkills;
			unsigned int solderSalary;
			cout << "Solider name: ";
			cin >> solderName;
			cout << "Solider skills: ";
			cin >> solderCombatSkills;
			cout << "Solider salary: ";
			cin >> solderSalary;
			solderList[i] = new Solder(solderName, solderCombatSkills, solderSalary);
		}
}
Commander::Commander(const Commander& other)
{
	CopyFrom(other);
}
Commander& Commander::operator=(const Commander& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Commander::~Commander()
{
	Free();
}
Commander::Commander()
{
	setName("NoName");
	setSkills(0);
	setSalary(0);
	setNumberOfSolders(0);
}
void Commander::print()
{
	cout << "Commander name: " << name << endl << "Commander combat skills: " << combatSkills << endl << "Commander salary: " << salary << endl;
	cout << "Comander " << name << " soliders: " << endl;
	for (size_t i = 0; i < numberOfSolders; i++)
	{
		cout << "   Solider" << i << endl;
		solderList[i]->print();
	}
}


void General::setNumberOfCommanders(int numberOfCommanders)
{
	this->numberOfCommanders = numberOfCommanders;
}
void General::setName(const char* name)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
void General::setSalary(unsigned int salary)
{
	this->salary = salary;
}
void General::setSkills(int skills)
{
	this->combatSkills = skills;
}
void  General::Free()
{
	delete[] name;
	for (size_t i = 0; i < numberOfCommanders; i++)
	{
		comanderList[i]->Free();
	}
	delete[] comanderList;
	delete[] description;
}
void General::CopyFrom(const General& other)
{
	this->combatSkills = other.combatSkills;
	this->salary = other.salary;
	int len = strlen(other.name);
	this->name = new char[len + 1];
	strcpy(this->name, other.name);
}
General::General(const char*name, int skills, unsigned int salary, int numberOfCommanders)
{
	setNumberOfCommanders(numberOfCommanders);
	setSkills(skills);
	setName(name);
	setSalary(salary);
	comanderList = new Commander*[numberOfCommanders];
	for (int i = 0; i < numberOfCommanders; i++)
	{
		cout << i + 1 << " Commander" << endl;
		char commanderName[50];
		int commanderCombatSkills;
		unsigned int commanderSalary;
		cout << "Commander name: ";
		cin >> commanderName;
		cout << "Commander skills: ";
		cin >> commanderCombatSkills;
		cout << "Commander salary: ";
		cin >> commanderSalary;
		int numberOfSoliders;
		cout << "Number of Soliders: ";
		cin >> numberOfSoliders;
		comanderList[i] = new Commander(commanderName, commanderCombatSkills, commanderSalary, numberOfSoliders,1);
		// hit a problem: когато използвам конструктора на командер, той се качва горе и трябва да въвеждам два ппъти
		//данните за войниците. ако пък ползвам дефолтния конструктор, не може да се инициализира командор листа и после 
		//гърми. ако махна другия конструктор не може да направи командорлиста и гърми..
		//тъпото решение е да направя втори конструткор, който се различава само по една булева променлива и да го ползвам тука
		comanderList[i]->solderList = new Solder*[numberOfSoliders];
		for (size_t j = 0; j < numberOfSoliders; j++)
		{
			cout << j + 1 << " solider" << endl;
			char solderName[50];
			int solderCombatSkills;
			unsigned int solderSalary;
			cout << "Solider name: ";
			cin >> solderName;
			cout << "Solider skills: ";
			cin >> solderCombatSkills;
			cout << "Solider salary: ";
			cin >> solderSalary;
			comanderList[i]->solderList[j] = new Solder(solderName, solderCombatSkills, solderSalary);
		}
	}
}
General::General(const General& other)
{
	CopyFrom(other);
}
General& General::operator=(const General& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
General::General()
{
	setName("Default");
	setNumberOfCommanders(0);
	setSkills(0);
	setSalary(0);
}
General::~General()
{
	Free();
}

void General::print()
{
	cout << endl << endl;
	cout << "General name: " << name << endl << "General combat skills: " << combatSkills << endl
		<< "General salary: " << salary << endl;
	cout << "General " << name << " commanders: " << endl;
	for (size_t i = 0; i < numberOfCommanders; i++)
	{
		comanderList[i]->print();
	}
}

void General::printGeneralName()
{
	cout << "This is " <<name<<" army"<<endl;
}
