#include<iostream>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int y,int x)
	{
		this -> x = x;
		this->y = y;
	}
};
class Figure
{
	Point* points;
	int pointsCount;

	void CopyFrom(const Figure& other)
	{
		points = new Point[other.pointsCount];
	}
	void Free()
	{

	}
};
int main()
{

	return 0;
}