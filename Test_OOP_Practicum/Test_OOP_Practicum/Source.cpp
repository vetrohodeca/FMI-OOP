#include<iostream>
#include<fstream>
const int MAXSIZE = 256;
using namespace std;
class Plane
{
private:
	long long ID;
	char plane[256];
	char type[256];
	long long  flights;
public:
	long long getID() const
	{
		return ID;
	}
	long long getFlights() const
	{
		return flights;
	}
	char* getPlane()
	{
		return plane;
	}
	char* getType()
	{
		return type;
	}
	void setID(int ID)
	{
		this->ID = ID;
	}
	void setfType(const char* type)
	{
		for (size_t i = 0; i < 255; i++)
		{
			this->type[i] = type[i];
		}
	}
	void setPlane(const char* type)
	{
		for (size_t i = 0; i < 255; i++)
		{
			this->plane[i] = plane[i];
		}
	}
	void setFlights(int flights)
	{
		this->flights = flights;
	}
	Plane(long long ID, char* plane, char* type, long long flights)
	{
		setID(ID);
		setPlane(plane);
		setfType(type);
		setFlights(flights);
	}
	Plane()
	{
		setID(0);
		setPlane(" ");
		setfType(" ");
		setFlights(0);
	}
	void print(const char* fileName, Plane p);
};
void Plane::print(const char* fileName, Plane p)
{
	ofstream oFile(fileName, ios::binary);
	if (!oFile) {
		cerr << "Error!\n";
	}
	oFile.write((const char*)&p, sizeof(Plane));
	if (!oFile.good())
	{
		cout << "Error occurred while writing the file";
	}
	oFile.close();
}
int main()
{
	char input[MAXSIZE];
	
	while ((strcmp(input, "exit") != 0))
	{
		cin >> input;
		if (strcmp(input, "create") == 0)
		{
			Plane p;
			long long ID;
			cout << "ID: ";
			cin >> ID;
			long long flights;
			cout << "Flights: ";
			cin >> flights;
			char plane[256];
			cout << "Plane: ";
			cin >> plane;
			char type[256];
			cout << "Type: ";
			cin >> type;
			p = Plane(ID, plane, type, flights);
			p.print("file.txt", p);
		}
	}
	return 0;
}