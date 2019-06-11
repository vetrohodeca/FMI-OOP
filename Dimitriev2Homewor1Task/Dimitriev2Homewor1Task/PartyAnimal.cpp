#include"PartyAnimal.h"

PartyAnimal::PartyAnimal()
{
	setName("Pesho");
	setMoney(69);
	setPrefer("everythig");
	setVodkaNumber(0);
	setWhiskeyNumber(0);
	setYears(20);
}
PartyAnimal::PartyAnimal(MyString name, int years, int money, int whiskeyNumber, int vodkaNumber, MyString prefer)
{
	setName(name);
	setMoney(money);
	setPrefer(prefer);
	setVodkaNumber(vodkaNumber);
	setWhiskeyNumber(whiskeyNumber);
	setYears(years);
}
void  PartyAnimal::setName(MyString name)
{
	this->name = name;
}
void  PartyAnimal::setYears(int years)
{
	this->years = years;
}
void  PartyAnimal::setMoney(int money)
{
	this->money = money;
}
void  PartyAnimal::setWhiskeyNumber(int whiskeyNumber)
{
	this->whiskeyNumber = whiskeyNumber;
}
void PartyAnimal::setVodkaNumber(int vodkaNumber)
{
	this->vodkaNumber = vodkaNumber;
}
void PartyAnimal::setPrefer(MyString prefer)
{
	this->prefer = prefer;
}
MyString PartyAnimal::getPrefer() const
{
	return prefer;
}
int PartyAnimal::getMoney() const
{
	return this->money;
}
int PartyAnimal::getVodkaNumber() const
{
	return this->vodkaNumber;
}
int PartyAnimal::getWhiskeyNumber() const
{
	return this-> whiskeyNumber;
}
MyString PartyAnimal::getName() 
{
	return this -> name;
}
int PartyAnimal::getYears() const
{
	return years;
}