#include"ChalgaClub.h"
#include<iostream>
Club * ChalgaClub::clone()
{
	ChalgaClub* copy = new ChalgaClub(*this);
	return copy;
}
ChalgaClub::ChalgaClub(MyString name, int vodkaPrice, int whiskeyPrice, MyString singer)
{
	setName(name);
	setVodkaPrice(vodkaPrice);
	setWhiskeyPrice(whiskeyPrice);
	this->singer = singer;
	this->visitorsNameList = new MyString[70];
}
bool ChalgaClub::peopleInput(PartyAnimal customer)
{
	if (this->countOfVisitors > this->capacity)
	{
		return false; // purvo proverqvame kapaciteta
	}
	if (customer.getPrefer() == "rock")
	{
		return false; // posle tipa na muzikata
	}
	if (customer.getYears() >= 18)
	{
		if (customer.getVodkaNumber()*this->getVodkaPrice() + customer.getWhiskeyNumber()*this->getWhiskeyPrice() > customer.getMoney())
		{
			return false; // nqma kinti
		}
	}
	else
	{
		if (customer.getVodkaNumber()*this->getVodkaPrice() + customer.getWhiskeyNumber()*this->getWhiskeyPrice() > customer.getMoney() - 20)
		{
			return false; // nqma kinti
		}
	}
	visitorsNameList[countOfVisitors] = customer.getName();
	countOfVisitors++;
	return true;
}