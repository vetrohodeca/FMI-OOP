#include<iostream>
using namespace std;
class Hero
{
public:
	Hero()
	{
		this->hp = 10;
	}
	int hp;
	virtual void attack(int hp)
	{
		this->hp=0;
	}
};

class Mage : public Hero {
public:
	Mage() : Hero::Hero()
	{
	}
};
class Healer : public Hero {
public:
	Healer() : Hero::Hero()
	{
	}
	void attack(int hp) override {
		this->hp += hp;
	}
};
class Archer : public Hero {
public:
	void attack(int hp) override {
		this->hp -= hp;
	}
	Archer() : Hero::Hero()
	{
	}
};
void proces(Hero* hero) {
	hero->attack(5);
	cout << hero->hp<<endl;
}
int main()
{
	Hero* heroArr[3];
	heroArr[0] = new Archer();
	heroArr[1] = new Healer();
	heroArr[2] = new Mage();
	for (int i  = 0; i <3; i++)
	{
		proces(heroArr[i]);
	}
	system("pause");
	return 0;
}