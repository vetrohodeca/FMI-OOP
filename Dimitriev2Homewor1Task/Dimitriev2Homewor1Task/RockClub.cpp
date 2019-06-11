#include"Rockclub.h"
Club* RockClub::clone()
{
	RockClub* copy = new RockClub(*this);
	return copy;
}
RockClub::RockClub(MyString name, int vodkaPrice, int whiskeyPrice)
{
	setName(name);
	setVodkaPrice(vodkaPrice);
	setWhiskeyPrice(whiskeyPrice);
}
bool RockClub::peopleInput(PartyAnimal customer)
{
	if (this->countOfVisitors > this->capacity)
	{
		return false; // purvo proverqvame kapaciteta
	}
	if (customer.getPrefer() == "chalga")
	{
		return false; // posle tipa na muzikata
	}
	if (customer.getVodkaNumber()*this->getVodkaPrice() + customer.getWhiskeyNumber()*this->getWhiskeyPrice() > customer.getMoney())
	{
		return false; // nqma kinti
	}

	visitorsNameList[countOfVisitors] = customer.getName();
	countOfVisitors++;
	return true;
}
