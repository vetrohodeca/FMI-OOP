#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Boat
{
private:
	char* name;
public:
	void setName(const char* name)// must be const
	{
		int len = strlen(name) + 1;
		this->name = new char[len+1];
		strcpy_s(this->name, len, name);
	}
	char* getName() const
	{
		return this->name;
	}
	Boat()
	{
		setName("NO NAME");
	}
	Boat(const char* name) // must be const
	{
		setName(name);
	}
	Boat(const Boat& other)// диса ми е дeстинция, а адър е това, от което взимаме данните
	{
		int len = strlen(other.name + 1);
		this->name = new char[len+1];
		strcpy(this->name, other.name);
	}

	Boat operator=(const Boat& other)
	{
		if (this != &other)
		{
			delete[] name;
			this->name = new char[strlen(other.name) + 1];
			strcpy(this->name, other.name);
		}
		return *this;
	}
	~Boat()
	{
		delete[] name;
	}
};
int main()
{
	Boat boat1("Alex"); // ne se vika operator ravno
	Boat boat2;
	boat2 = Boat("Vanesa");//vika se operator ravno
	cout << boat1.getName() << endl;
	cout << boat2.getName() << endl;

	system("pause");
	return 0;
}
