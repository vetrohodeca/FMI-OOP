#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct  Point
{
	int x;
	int y;
	Point(const int x, const int y)
	{
		this->x= x;
		this->y=y;
	}
	void Print()
	{
		cout <<x << " " <<y << endl;
	}
};
double GetDist(const Point& p1, const Point& p2)
{
	return sqrt((p1.x + p2.x)*(p1.x + p2.x) + (p1.y + p2.y)*(p1.y + p2.y));
}
int main()
{
	Point p(5,12);
	p.Print();
	system("pause");
	return 0;
}
/*ofstream f;
	f.open("test", ios::binary);
	if (!f.is_open())
	{
		cout << "Error! " << endl;
		return 1;
	}
	int a = 665;
	f.write((char*)&a, sizeof(int)); // ukazatel kum dannite, koito shte zapishem ot tip char*
	int b = 9999;
	f.write((char*)&b, sizeof(int));
	f.close();
	ifstream p;
	int num=5;
	p.read((char*)&num, sizeof(int));
	cout << num<<endl;
	p.close();*/