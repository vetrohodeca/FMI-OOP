#pragma once
#include"PartyAnimal.h"
const int maxDiscos = 100;
#include"Club.h"
class Clubs{
protected:
	int countOfClubs=0;
	Club** clubs;
	void Free();
	void CopyFrom(const Clubs& other);
public:
	
	bool addPerson(PartyAnimal customer, MyString name);
	 bool removePerson(MyString customer, MyString clubName);
	Clubs();
	Clubs(const Clubs& other);
	Clubs& operator=(const Clubs& other);
	~Clubs();
	bool addFolkClub(MyString name, int vodkaPrice, int whiskeyPrice, MyString singer);
	bool addRockClub(MyString name, int vodkaPrice, int whiskeyPrice);
	bool addHouseClub(MyString name, int vodkaPrice, int whiskeyPrice, int numberOfDJ);
	int getCount() const;

};
