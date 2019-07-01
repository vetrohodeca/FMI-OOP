#include<iostream>
#include"Garage.h"
using namespace std;
int main()
{
	Garage garage;
	garage.addCar(218, "Visokoto naprejenie");
	garage.addBus(160, "Na Vaseto busa");
	garage.addTIR(150, "Geely-to");
	cout<<garage.numberOfSuitableVechicles(75, 0, 0,1 )<<endl;
	system("pause");
	return 0;
}