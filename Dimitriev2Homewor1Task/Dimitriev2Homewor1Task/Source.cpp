#include<iostream>
#include"Clubs.h"
#include"Club.h"
using namespace std;
int main()
{
	Clubs Studenski;
	cout << Studenski.addFolkClub("33", 35, 40, "Galena") << endl;
	cout << Studenski.addHouseClub("Yalta", 50, 50, 2) << endl;
	PartyAnimal Alex("Alex", 18, 180, 2, 2, "house");
	cout << endl;
	cout<<Studenski.addPerson(Alex, "Yalta")<<endl;
	cout<<Studenski.addPerson(Alex, "33")<<endl;
	cout<<Studenski.removePerson("Poli", "33")<<endl;
	cout<<Studenski.removePerson("Alex", "33")<<endl;
	system("pause");
	return 0;
}