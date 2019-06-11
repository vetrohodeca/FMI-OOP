#pragma once
#define MAXPEOPLEONHOUSE 99999
#include"Club.h"
class HouseClub:public Club{
	short numberOfDJs;
	int count = 0;
public:
	bool peopleInput(PartyAnimal customer);
	HouseClub(MyString name, int vodkaPrice, int whiskeyPrice,int numberOfDJs);
	void setNumberOfDJs(int numberOfDJs);
	Club* clone();
};