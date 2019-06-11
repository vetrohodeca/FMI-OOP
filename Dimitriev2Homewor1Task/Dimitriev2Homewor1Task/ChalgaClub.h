#pragma once
#include"Club.h"
#include"PartyAnimal.h"
class ChalgaClub : public Club {
private:
	int count = 0;
	const int capacity = 70;
	MyString singer;
public:
	Club* clone();
	bool peopleInput(PartyAnimal customer) ;
	ChalgaClub(MyString name, int vodkaPrice, int whiskeyPrice, MyString singer);
};
