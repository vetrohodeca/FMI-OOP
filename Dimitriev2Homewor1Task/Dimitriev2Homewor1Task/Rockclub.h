#pragma once
#include"Club.h"
#include"PartyAnimal.h"
class RockClub : public Club {
private:
	const int capacity = 30;
	int count = 0;
public:
	bool peopleInput(PartyAnimal customer);
	RockClub(MyString name, int vodkaPrice, int whiskeyPrice);
	Club* clone();
};