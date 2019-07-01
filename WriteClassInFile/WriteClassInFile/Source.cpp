#include<iostream>
#include"Header.hpp"
using namespace std;
int main()
{
	car A(1999, 140);
	car B(2006, 115);
	ofstream îutF("test.txt");
	A.print("text.txt");
	system("pause");
	return 0;
}