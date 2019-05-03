#pragma once
#include"Deck.h"
#include<cstring>
#include"YuGiOhCard.h"
#include<iostream>


Deck::Deck()
{
	for (int i = 0; i < 40; i++)
	{
		YuGiOhCardList[i] = YuGiOhCard();
	}
}
int Deck::numberOfSpellCards() const
{
	int counter=40;
	for (int i = 0; i < 40; i++)
	{
		if (this->YuGiOhCardList[i].getIsMonster() == 1)
		{
			counter--;
		}
	}
	return counter;
}
int Deck::numberOfMonsterCards() const
{
	int counter = 0;
	for (int i = 0; i < 40; i++)
	{
		if (this->YuGiOhCardList[i].getIsMonster() == 1)
		{
			counter++;
		}
	}
	return counter;
}
void Deck::DeckSetTwoCards(int firstNumber, int secondNumber)
{
	char*name = new char[58];
	strcpy(name, "Wild Dragon");
	YuGiOhCardList[firstNumber] = YuGiOhCard(2500, 3000, name, true);// zashto ako tuka e "Neeshto si " ne stava
	strcpy(name, "Strong stench");
	YuGiOhCardList[secondNumber] = YuGiOhCard(0, 0, name, false);
}
bool Deck::getIsMonster(int i) const
{
	return this->YuGiOhCardList[i].getIsMonster();
}
char* Deck::getYuGiOhCardListName(int i) const
{
	return this->YuGiOhCardList[i].getName();
}
void Deck::setYuGiOhCardListName(char*name, int i)
{
	YuGiOhCardList[i].SetName(name);
}
void Deck::printDeck()
{
	for (int i = 0; i < 40; i++)
	{
		YuGiOhCardList[i].print();
	}
}
//void Deck::ChangeCard(char*name, Deck deck)
//{
//	for (int i = 0; i < 40; i++)
//	{
//		if (strcmp(YuGiOhCardList[i].getName(), name) == 0)
//		{
//			char newName[58];
//			std::cout << "Input new name";
//			std::cin.getline(newName, 58);
//			YuGiOhCardList[i] = YuGiOhCard(0, 0, newName, 0);
//		}
//	}
//}
void Deck::ChangeCard(char*name, Deck deck)
{
	for (int i = 0; i < 40; i++)
	{
		if (strcmp(YuGiOhCardList[i].getName(), name) == 0)
		{
			if (deck.getIsMonster(i) == true)
			{
				int newAtPoints;
				std::cout << "Input new Attack Points: ";
				std::cin >> newAtPoints;
				int newDefPoints;
				std::cout << "Input new Defence Points ";
				std::cin >> newDefPoints;
				char newName[58];
				std::cin.ignore();
				std::cout << "Enter new name: ";
				std::cin.getline(newName, 57);
				YuGiOhCardList[i] = YuGiOhCard(newAtPoints, newDefPoints, newName, true); break;
			}
			else
			{
				char newName[58];
				std::cin.getline(newName, 58);
				YuGiOhCardList[i] = YuGiOhCard(0, 0, newName, 0);
			}
		}
	}
}