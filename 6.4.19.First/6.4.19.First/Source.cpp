#include<iostream>
#define MAXSIZE 50
using namespace std;

class Deck
{
private:
	int deckWeight;
	char* manufacturerName;
	int getDeckWeight()
	{
		return deckWeight;
	}
	void setDeckWeigth(int deckWeight)
	{
		this->deckWeight = deckWeight;
	}
	char* getMacufacturerName()const
	{
		return manufacturerName;
	}
	void setManufacturerName(char* manufacturerName)
	{
		strcpy_s(this->manufacturerName, MAXSIZE, manufacturerName);
	}
};

class Rig {
private:
	int numberOfSails;
	double machtLength;
	double sailArea;
	char* sailManufacturerName;
public:
	Rig() {

	}
	
	Rig(double sailArea,const char* sailManufacturerName) {
		this->sailManufacturerName = new char[MAXSIZE];
		this->setSailManufacturerName(sailManufacturerName);
		this->setSailArea(sailArea);
	}
	int getNumberOfSails()
	{
		return numberOfSails;
	}
	void setNumberOfSails(int numberOfSails)
	{
		this->numberOfSails = numberOfSails;
	}
	double getmMchtLength()
	{
		return  machtLength;
	}
	void setMachtLength()
	{
		this->machtLength = machtLength;
	}
	double getSailArea()
	{
		return  sailArea;
	}
	void setSailArea(const int sailArea)
	{
		this->sailArea = sailArea;
	}
	char* getsailManufacturerName() const
	{
		return sailManufacturerName;
	}
	void setSailManufacturerName(const char* sailManufacturerName)
	{
		strcpy_s(this->sailManufacturerName, MAXSIZE, sailManufacturerName);
	}
};

class Boat {
	char* BoatName;
	Rig boatRig;
	Deck boatDeck;
	
public:
	Boat(const char* BoatName, double sailArea,const char* sailManufacturerName)
	{
		this->BoatName = new char[MAXSIZE];
		this->setBoatName(BoatName);

		this->boatRig = Rig(sailArea ,sailManufacturerName);
	}
	void setBoatName(const char* BoatName)
	{
		strcpy_s(this->BoatName, MAXSIZE, BoatName);
	}
	const char* getBoatName()
	{
		return BoatName;
	}
	Rig getRig() const
	{
		return this->boatRig;
	}
};

int main()
{
	Boat AlexBoat("AlexBoat", 5, "Nautivella");
	cout << AlexBoat.getBoatName() << endl;
	cout << AlexBoat.getRig().getSailArea() << endl;
	cout << AlexBoat.getRig().getsailManufacturerName() << endl;
	
	system("pause");
	return 0;
}