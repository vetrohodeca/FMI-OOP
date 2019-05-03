#include<iostream>
#include "CardType.h"
#include "YuGiOhCard.h"
#include"Deck.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define MAXN 58
//Different Dimension Demon Super Doom King Purple / Bright Armageddon - the card with longest name 57 characters
// source: https://www.reddit.com/r/yugioh/comments/9moiue/what_is_the_top_10_longest_card_name_in_yugioh/

using namespace std;

int main()
{
	YuGiOhCard card1;
	char*name = new char[58];
	strcpy(name,"karta1");
	card1 = YuGiOhCard(500, 4000, name, false);
	card1.print();
	Deck deck; 
	deck = Deck();
	deck.printDeck();
	cout << endl;
	deck.DeckSetTwoCards(0, 1);
	deck.printDeck();
	cout << endl;
	cout <<"Spell cards: "<< deck.numberOfSpellCards()<<endl;
	cout << "Monster cards: " << deck.numberOfMonsterCards() << endl;
	char nameOfCardToChange[58];
	cout << "Input name of card to change: ";
	cin.getline(nameOfCardToChange, 58);
	deck.ChangeCard(nameOfCardToChange, deck);
	
	
	deck.printDeck();
	system("pause");
	return 0;
}