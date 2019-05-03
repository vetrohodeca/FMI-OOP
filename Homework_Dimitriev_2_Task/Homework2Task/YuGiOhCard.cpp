#pragma once
#include<cstring>
#include<iostream>
#include "YuGiOhCard.h"
#define MAXN 58
using namespace std;


YuGiOhCard::YuGiOhCard(int attackPoints, int deffencePoints, char* name, bool isMonster)
{
	setAttP(attackPoints);
	setDefP(deffencePoints);
	SetName(name);
	setIsMonster(isMonster);

}
YuGiOhCard::YuGiOhCard()
{
	setAttP(0);
	setDefP(0);
	SetName("token");
	setIsMonster(1); 
	

}
int YuGiOhCard::getDefP() const
{
	return this->deffecePoints;
}
bool YuGiOhCard::getIsMonster() const
{
	return this->isMonster;
}
int YuGiOhCard::getAttP() const
{
	return this->attackPoints;
}
char* YuGiOhCard::getName() const
{
	char* arr = new char(58);
	strcpy(arr,this->name);
	return arr;
}
void YuGiOhCard::setDefP(int defP)
{
	if (attackPoints > 5000)
	{
		attackPoints = 0;
	}
	this->deffecePoints = defP;
}
void YuGiOhCard::setAttP(int attP)
{
	if (attackPoints > 5000)
		attackPoints = 0;
	this->attackPoints = attP;
}
void YuGiOhCard::SetName(const char* name)
{
		strcpy_s(this->name, strlen(name) + 1, name);
	
}
void YuGiOhCard::setIsMonster(bool isMonster)
{
	this->isMonster = isMonster;
}
void YuGiOhCard::print() const
{
	if (this->getIsMonster() == true)
	{
		cout << this->getName() << "  " << this->getAttP()
			<< "  " << this->getDefP()
			<< "  " << "Monster" << endl;
	}
	else
	{
		cout << this->getName()<<"  " << "Spell" << endl;
	}
}
