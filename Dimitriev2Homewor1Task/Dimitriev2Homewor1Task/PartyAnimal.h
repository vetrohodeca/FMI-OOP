#pragma once
#include"String.h"
typedef unsigned short int;
class PartyAnimal
{
private:
	MyString name;
	int years;
	int money;
	int whiskeyNumber;
	int vodkaNumber;
	MyString prefer;
public:
	PartyAnimal();
	PartyAnimal(MyString name, int years, int money, int whiskeyNumber, int vodkaNumber, MyString prefer);
	MyString getPrefer() const;
	MyString getName() ;
	int getMoney() const;
	int getVodkaNumber() const;
	int getWhiskeyNumber() const;
	int getYears() const;
	void setName(MyString name);
	void setYears(int years);
	void setMoney(int money);
	void setWhiskeyNumber(int whiskeyNumber);
	void setVodkaNumber(int vodkaNumber);
	void setPrefer(MyString prefer);
};