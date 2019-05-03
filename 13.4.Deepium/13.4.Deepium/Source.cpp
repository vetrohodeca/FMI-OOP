#include<iostream>
/*#include"Header.h"
#include "Header.h"
using namespace std;


Banitsa::Banitsa() : size(100), calories(200), Manufacturer(new char[10])
{
	strcpy_s(this->Manufacturer, 10, "Unknown");
}

//initializer list test

Banitsa::~Banitsa()
{
	cout << Manufacturer;
	delete Manufacturer;

}
int main()
{

	Banitsa* b = new Banitsa();

	cout << b->getManufacturer() << endl;
	delete b;
	system("pause");
	return 0;
}*/
class Point
{
private:
	double x;
	double y;

public:
	double getX() const
	{
		return x;
	}
	double getY() const
	{
		return y;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	Point();
	Point(double x , double y)
	{
		setX(x);
		setY(y);
	}
	Point& operator=(const Point&);
	Point operator+(const Point&);
	Point operator-(const Point&);
	bool operator==(const Point&);
};


int main()
{
	Point p(1, 2);
	Point d(3, 4);
	p = p + d;
	std::cout << p.getX() << "  " << p.getY() << std::endl;
		system("pause");
	return 0;
}
Point::Point() : x(0), y(0) {};

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->setX(other.getX());
		this->setY(other.getY());
	}
	return *this;
}
Point Point::operator+(const Point& p)
{
	Point newPoint;
	newPoint.setX(this->getX() + p.getX());
	newPoint.setY(this->getY() + p.getY());
	return newPoint;
}
Point Point::operator-(const Point& p)
{
	Point newPoint;
	newPoint.setX(this->getX() - p.getX());
	newPoint.setY(this->getY() - p.getY());
	return newPoint;
}
bool Point::operator==(const Point& p)
{

	if (this == &p)
	{
		return 1;
	}
	else return 0;
}