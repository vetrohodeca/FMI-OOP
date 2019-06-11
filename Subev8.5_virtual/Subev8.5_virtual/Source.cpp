#include<iostream>
#include<fstream>
#include<math.h>
#include <string>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("example.txt");
	myfile <<1<<" "<<2;
	myfile.close();
	string STRING;
	ifstream infile;
	infile.open("example.txt");
	while (!infile.eof) // To get you all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.
		cout << STRING; // Prints our STRING.
	}
	infile.close();
	system("pause");
	return 0;
}