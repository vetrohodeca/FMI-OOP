#pragma once
#include<fstream>
class car {
public:
	int year;
	int power;
	friend std::ostream& operator<< (std::ostream &out,car c);
	car(int year, int power);
	void print(const char*filename);
};
car::car(int year, int power)
{
	this->year = year;
	this->power = power;
}
std::ostream& operator<<(std::ostream &out, car c)
{
	out << c.year << "\n" <<c.power << std::endl;
	return out;
}
void car::print(const char* filename)
{
	std::ofstream oFile(filename);
	if (!oFile)
	{
		std::cout << "Error";
	}
	oFile <<"power "<< power <<"     year:  "<< year;
		oFile.close();	
}