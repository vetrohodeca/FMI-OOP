#pragma once
class Solder {
private:
	char* name;
	int combatSkills;
	unsigned int salary;
public:
	void setName(const char*name);
	void setSkills(int skills);
	void setSalary(unsigned int salary);
	void CopyFrom(const Solder& other);
	Solder(const char*, int, unsigned int);
	Solder(const Solder& other);
	Solder();
	Solder& operator=(const Solder& other);
	~Solder();
	void Free();
	void print();
};
class Commander
{
private:
	bool difference;
	char* name;
	int combatSkills;
	unsigned int salary;
	int numberOfSolders;
public:
	Solder** solderList;

	void setName(const char*name);
	void setSkills(int skills);
	void setSalary(unsigned int salary);
	void setNumberOfSolders(int number);
	Commander(const char*name, int skills, unsigned int salary, int numberOfSoliders);
	Commander(const char*name, int skills, unsigned int salary, int numberOfSoliders, bool difference);
	Commander(const Commander& other);
	Commander& operator=(const Commander& other);
	Commander();
	~Commander();
	void Free();
	void CopyFrom(const Commander& other);
	void print();
};
class General
{
protected:

	char* name;
	char* description;
	int combatSkills;
	unsigned int salary;
	int numberOfCommanders;
	Commander** comanderList;
public:
	General();
	void setNumberOfCommanders(int number);
	void setName(const char*name);
	void setSkills(int skills);
	void setSalary(unsigned int salary);
	General(const char*name, int skills,unsigned int salary, int numberOfCommanders);
	General(const General& other); 
	General& operator=(const General& other);
	~General();
	void CopyFrom(const General& other);
	void Free();
	void print();
	void printGeneralName();
	 
	void setDescription(char*);
};
	