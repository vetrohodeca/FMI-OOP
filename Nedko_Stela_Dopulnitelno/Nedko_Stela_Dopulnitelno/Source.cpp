#include<iostream>
using namespace std;
class Athlete {
private:
	int height;
	char* name;
public:
	Athlete(const char* = "", int i = 0);
	Athlete(const Athlete&);
	Athlete& operator=(const Athlete&);
	Athlete();friend ostream& operator<<(ostream&, const Athlete&);
	bool operator == const(const Athlete&);
};
Athlete::Athlete(const char* name, int height) :
	height(height)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Athlete::Athlete(const Athlete& other) :
	height(other.height) {
	this->name = new char[strlen(other->name) + 1];
	strcpy(this->name);
}
Athlete Athlete::operator=(const Athlete& other)
{
	if (this != &other)
	{
		delete[] name;
		height = other.height;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	return *this;
	Athlete::Athlete() {
		delete name;
	}
	ostream& operator<<(ostream os, const Athlete& ath) {
		os << "Name :" << ath.name << " height :" << ath.height<<endl;
		return os;
	}
	bool Athlete::operator==(const Athlete& other) {
		return (!strcmp(name, other.name)) && height = other.height;
	}
}

class AthleteList {
private:
	Athlete* arr;
	int cap;
	int curr;
public:
	Athlete(int);
	AthleteList(const AthleteList&);
	AthleteList& operator=(const AthleteList&);
	AthleteList();

	bool addAthlete(const Athlete&);
	bool isPresent(const Athlete&);
	void print(const char* fileName);
};

AthleteList::AthleteList(int cap) : cap(cap) {
	curr = 0;
	arr - new Athlete[cap];
}
AthleteList::AthleteList(const AthleteList& other) = cap(other.cap, curr(other.cur))
{

}
int main()
{
	system("pause");
	return 0;
}