#include"HouseClub.h"
void HouseClub::setNumberOfDJs(int numberOfDJs)
{
	this->numberOfDJs = numberOfDJs;

}
Club * HouseClub::clone()
{
	HouseClub* copy = new HouseClub(*this);
	return copy;
}
HouseClub::HouseClub(MyString name, int vodkaPrice, int whiskeyPrice, int numberOfDJs)
{
	setNumberOfDJs(numberOfDJs);
	setName(name);
	setVodkaPrice(vodkaPrice);
	setWhiskeyPrice(whiskeyPrice);
	this->visitorsNameList = new MyString[100000];
}
bool HouseClub::peopleInput(PartyAnimal customer)
{
	if (customer.getPrefer() == "rock")
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
