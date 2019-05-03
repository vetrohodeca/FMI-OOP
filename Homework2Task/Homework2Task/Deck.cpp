#pragma once
#include"Deck.h"
#include<cstring>
#include"YuGiOhCard.h"
#include<iostream>
#include<fstream>

using namespace std;

Deck::Deck()
{
	for (int i = 0; i < 40; i++)
	{
		YuGiOhCardList[i] = YuGiOhCard();
	}
}
int Deck::numberOfSpellCards() const
{
	int counter = 40;
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
char* serializeCard(YuGiOhCard yugiohCard) {
	// 58 bytes - name, 4 bytes - attackPoints, 4 bytes - defencePoints, 1 byte - isMonster
	char* data = new char[67];
	for (int i = 0; i < 58; i++)
	{
		data[i] = yugiohCard.getName()[i];
	}
	int attackPoints = yugiohCard.getAttP();
	int deffencePoints = yugiohCard.getDefP();
	data[61] = attackPoints;
	data[60] = attackPoints >> 8;
	data[59] = attackPoints >> 16;
	data[58] = attackPoints >> 24;
	data[65] = deffencePoints;
	data[64] = deffencePoints >> 8;
	data[63] = deffencePoints >> 16;
	data[62] = deffencePoints >> 24;
	data[66] = yugiohCard.getIsMonster();
	return data;
}
void Deck::saveIntoFile(const char* fileName) {
	ofstream deckFile(fileName, ios::out | ios::binary);
	for (int i = 0; i < 40; i++)
	{
		char* data = serializeCard(YuGiOhCardList[i]);
		deckFile.write(data, 67);
	}
	deckFile.close();
}

YuGiOhCard deserializeCard(char* data) {
	YuGiOhCard yugiohcard;
	char name[58];
	for (int i = 0; i < 58; i++)
	{
		name[i] = data[i];
	}
	yugiohcard.SetName(name);
	int attackPoints = data[58] | ((int)data[59] << 8) | ((int)data[60] << 16) | ((int)data[61] << 24);
	int deffencePoints = data[62] | ((int)data[63] << 8) | ((int)data[64] << 16) | ((int)data[65] << 24);
	bool isMonster = data[66];
	yugiohcard.setAttP(attackPoints);
	yugiohcard.setDefP(deffencePoints);
	yugiohcard.setIsMonster(isMonster);
	return yugiohcard;
}
Deck::Deck(const char* fileName) {
	char data[67];
	ifstream deckFile(fileName, ios::in | ios::binary);
	int i = 0;
	if (deckFile.good()) {
		while (!deckFile.read(data, 67)) {
			YuGiOhCardList[i] = deserializeCard(data);
			i++;
		}
	}
}