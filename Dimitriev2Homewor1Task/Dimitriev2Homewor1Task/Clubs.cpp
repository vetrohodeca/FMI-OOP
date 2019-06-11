#include"Clubs.h"
#include"ChalgaClub.h"
#include"HouseClub.h"
#include"Rockclub.h"
const int MINVODKAPRICECHALGA = 20;
const int MINWHISKEYPRICECHALGA = 35;
const int MINVODKAPRICEROCK = 40;
const int MINWHISKEYPRICEROCK = 30;
const int MINVIDKAPRICEHOUSE = 30;
const int MINWHISKEYPRICEHOUSE = 40;

int Clubs::getCount() const
{
	return this->countOfClubs;
}

void Clubs::Free()
{
	for (size_t i = 0; i < countOfClubs; i++)
	{
		delete clubs[i];
	}
	delete[] clubs;
}

void Clubs::CopyFrom(const Clubs& other)
{
	clubs = new Club*[other.countOfClubs];
	for (int i = 0; i < other.countOfClubs; i++)
		clubs[i] = other.clubs[i]->clone();
	countOfClubs = other.countOfClubs;
}

Clubs::Clubs(const Clubs& other)
{
	CopyFrom(other);
}

Clubs::Clubs()
{
	clubs = new Club*[maxDiscos];
	countOfClubs= 0;
}

Clubs& Clubs ::operator=(const Clubs& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Clubs::~Clubs()
{
	Free();
}

bool Clubs::addFolkClub(MyString name, int vodkaPrice, int whiskeyPrice, MyString singer)
{
	ChalgaClub* chalgaClub  = new ChalgaClub( name,  vodkaPrice,  whiskeyPrice, singer);
	if (chalgaClub->getVodkaPrice() < MINVODKAPRICECHALGA || chalgaClub->getWhiskeyPrice() < MINWHISKEYPRICECHALGA)
		return false;
	clubs[countOfClubs] = chalgaClub;
	countOfClubs++;
	return true;
}
bool Clubs::addHouseClub(MyString name, int vodkaPrice, int whiskeyPrice,int numberOfDJ)
{
	HouseClub* houseClub = new HouseClub( name,  vodkaPrice,  whiskeyPrice,numberOfDJ);
	if (houseClub->getVodkaPrice() < MINVIDKAPRICEHOUSE || houseClub->getWhiskeyPrice() < MINWHISKEYPRICEHOUSE)
		return false;
	clubs[countOfClubs] = houseClub;
	countOfClubs++;
	return true;
}
bool Clubs::addRockClub(MyString name, int vodkaPrice, int whiskeyPrice)
{
	RockClub* rockClub = new RockClub( name,  vodkaPrice,  whiskeyPrice);
	if (rockClub->getVodkaPrice() < MINVODKAPRICEROCK || rockClub->getWhiskeyPrice() < MINWHISKEYPRICEROCK)
		return false;
	clubs[countOfClubs] = rockClub;
	countOfClubs++;
	return true;
}
bool Clubs::addPerson(PartyAnimal customer, MyString name)
{
	for (size_t i = 0; i <countOfClubs;i++)
	{
		if (name == clubs[i]->getName()&& clubs[i]->peopleInput(customer)==true)
		{
			return true;
		}
	}
	return false;
}
bool Clubs::removePerson(MyString customer, MyString clubName)
{
	for (size_t i = 0; i < countOfClubs; i++)
	{
		if (clubName == clubs[i]->getName()&& clubs[i]->peopleOutput(customer)==true)
		{
			return true;
		}
	}
	return false;
}