#include<iostream>
using namespace std;
class Point
{
public:
	int x;
	int y;
	double DistTo(const Point& other)
	{
		int dx = x - other.x;
		int dy = y - other.y;
		return sqrt(dx*dx + dy * dy);
	}
};
class Triangle
{
public:
	Point p1;
	Point p2;
	Point p3;
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		p1.x - x1;
		p1.y = y1;
		p2.x = x1;
		p2.y = y2;
		p3.x = x3;
		p3.y = y3;
	}
	double getPer()
	{
		return p1.DistTo(p2) + p2.DistTo(p3) + p3.DistTo(p1);
	}
};
int main()
{
	
	while (true);
	return 0;
}