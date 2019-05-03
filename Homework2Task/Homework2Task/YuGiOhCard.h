#pragma once


class YuGiOhCard
{
private:
	bool isMonster;
	char name[58] ;
	int attackPoints;
	int deffecePoints;
public:
	YuGiOhCard();
	YuGiOhCard(int, int, char*, bool);
	int getDefP() const;
	int getAttP() const;
	char* getName() const;
	bool getIsMonster() const;
	void setDefP(int defP);
	void setAttP(int attP);
	void SetName(const char* name);
	void setIsMonster( bool isMonster);
	void print() const;

};