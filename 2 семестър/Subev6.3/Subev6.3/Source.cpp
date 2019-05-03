#include<iostream>
#include<cmath>
using namespace std;
struct Point
{
	double x;
	double y;

	void setX(double x)
	{
		this->x = x;
	}
	void getX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void getY(double y)
	{
		this->y = y;
	}
	double length;
	double distanceToOtherPoint;
}
Point distTo0(Point p)
{
	p.length = sqrt((point1.x*point1.x) + (point1.y*point1.y));
	return p.length;
}
int main()
{
	
	Point point1;
	Point point2;
	cin >> point1.x;
	cin >> point1.y;
	cin >> point2.x;
	cin >> point2.y;
	cout << point1.x<<" ";
	cout << point1. y<<endl;
	
	point1.distanceToOtherPoint= sqrt((point1.x - point2.x)*(point1.x-point2.x) + (point1.y-point2.y)*(point1.y - point2.y));
	cout << point1.length << endl;
	cout << point1.distanceToOtherPoint;
	int stop;
	cin >> stop;
	return 0;
}