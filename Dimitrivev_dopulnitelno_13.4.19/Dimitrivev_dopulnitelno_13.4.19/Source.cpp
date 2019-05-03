#include<iostream>
using namespace std;
const int maxCM = 99;
const int minCM = 0;
const int minM = 0;
const int maxM = 999;
const int minKM = 0;
class Distance {
private:
	int cm;
	int m;
	int km;
public:
	int getCm();
	int getM() ;
	int getKM();
	void setCm(int cm);
	void setM(int m);
	void setKm(int km);
	void print();
	Distance();
	Distance(int km, int m, int cm);
	int Compare(const Distance& d1, const Distance&);
};
void Distance::setCm(int cm)
{
	if (cm<minCM || cm>maxCM)
	{
		cm = minCM;
	}
	this->cm = cm;
}
void Distance::setM(int m)
{
	if (cm<minM || cm>maxM)
	{
		cm = minM;
	}
	this->m = m;
}
void Distance::setKm(int km)
{
	if (km<minKM )
	{
		km = minKM;
	}
	this->km = km;
}
Distance::Distance()
{
	setKm(0);
	setM(0);
	setCm(0);
}
Distance::Distance(int km,int m,int cm)
{
	setKm(km);
	setM(m);
	setCm(cm);
}
void Distance::print()
{
	cout << "Km: " << km<<"   M:" << "  Cm: " << cm;
}

int Distance::getCm()
{
	return cm;
}
int Distance::getM()
{
	return m;
}
int Distance::getKM()
{
	return km;
}
/*int Compare(const Distance& d1, const Distance&)
{
	if(d1.getKM>d2.getKm)

}*/
int main()
{

	system("pause");
	return 0;
}
