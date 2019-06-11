#include"Club.h"
#define DEFAULTARRSIZE 10
void Club::setName(MyString name)
{
	this->name = name;
}
void Club::setVodkaPrice(int vodkaPrice)
{
	this->vodkaPrice = vodkaPrice;
}
void Club::setWhiskeyPrice(int whiskeyPrice)
{
	this->whiskeyPrice = whiskeyPrice;
}

int Club:: getVodkaPrice() const
{
	return this->vodkaPrice;
}
int Club::getWhiskeyPrice() const
{
	return this->whiskeyPrice;
}
MyString Club::getName() const
{
	return this->name;
}

Club::Club()
{
	setName("Default");
	setVodkaPrice(50);
	setWhiskeyPrice(50);
	MyString* visitorsNameList = new MyString[DEFAULTARRSIZE];
}
Club::Club(MyString name, int vodkaPrice, int whiskeyPrice, int numberOfElements)
{
	setName(name);
	setVodkaPrice(vodkaPrice);
	setWhiskeyPrice(whiskeyPrice);
	visitorsNameList = new MyString[numberOfElements];
}

void Club::Free()
{
	delete visitorsNameList;
}
void Club::CopyFrom(const Club& other)
{
	this->vodkaPrice = other.vodkaPrice;
	this->whiskeyPrice = other.whiskeyPrice;
	this->countOfVisitors = other.countOfVisitors;
	this->name = other.name;
	this->visitorsNameList = new MyString[other.countOfVisitors];
	for (size_t i = 0; i < countOfVisitors; i++)
	{
		this->visitorsNameList[i] = other.visitorsNameList[i];
	}
}
Club::Club(const Club& other)
{
	CopyFrom(other);
}
Club& Club::operator=(const Club& other)
{
	if(this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Club::~Club()
{
	Free();
}
bool Club::peopleOutput(MyString customer)
{
	for (size_t i = 0; i < countOfVisitors; i++)
	{
		if (visitorsNameList[i] == customer)
		{
			for (int j = i; j < countOfVisitors ; j++)
			{
				visitorsNameList[j] = visitorsNameList[j + 1];
			}
			countOfVisitors--;
			return true;
		}
	}
	return false;
}