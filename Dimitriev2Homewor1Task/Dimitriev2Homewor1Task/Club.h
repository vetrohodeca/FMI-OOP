#pragma once
#include"String.h"
#include"PartyAnimal.h"
class Club
{
protected: 
	int countOfVisitors;
	MyString* visitorsNameList;
	MyString name;
	int vodkaPrice;
	int whiskeyPrice;
public:
	void Free();
	void CopyFrom(const Club& other);
	Club();
	Club(const Club& other);
	Club& operator=(const Club& other);
	~Club();
	virtual Club* clone() = 0;
	virtual bool peopleInput(PartyAnimal customer) = 0;
	bool peopleOutput(MyString customer);
	void setName(MyString name);
	void setVodkaPrice(int vodkaPrice);
	void setWhiskeyPrice(int whiskeyPrice);
	int getVodkaPrice() const;
	int getWhiskeyPrice() const ;
	MyString getName() const;
	Club(MyString name, int vodkaPrice, int whiskeyPrice,int numberOfelements);
};

