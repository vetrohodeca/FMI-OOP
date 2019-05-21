#include<iostream>
#include"Header.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std; 
int main()
{
	General G = General("Dimo", 999, 9999, 1);
	G.print();
	G.printGeneralName();
	system("pause");
	return 0;
}