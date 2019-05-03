#pragma once
#include"YuGiOhCard.h"
class Deck
{
private:
	YuGiOhCard YuGiOhCardList[40];
public:
	Deck();
	Deck(const char*);
	int numberOfSpellCards() const;
	int numberOfMonsterCards() const;
	void DeckSetTwoCards(int, int);
	void printDeck();
	void ChangeCard(char*, Deck deck);
	char* getYuGiOhCardListName(int i) const;
	bool getIsMonster(int i) const;
	void setYuGiOhCardListName(char* name, int i);
	void saveIntoFile(const char*);
	//int getNumberOfMagicCards();
	//int getNumberOfMonsterCards();

};