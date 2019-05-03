#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	ofstream myTestFile("C:/Users/Alex/Desktop/myTestFile.txt", ios::binary);
	if (!myTestFile) {
		cerr << "File couldnТt be opened!\n";
		system("pause");
		return 1;
	}
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		myTestFile << num;
	}                        
	myTestFile.close();// има ли нужда да затвар€м -da!
	cout << endl;
	ifstream myTestFile1("C:/Users/Alex/Desktop/myTestFile.txt", ios::binary);
	char c1[1];
	int index=0;
	while (!myTestFile1.eof())// dokato ne stigna end of file
	{
		myTestFile1.read(c1, 1);// read priema char* i duljina, get- char
		index++;
		if  (index % 3 == 0)cout <<c1[0]<< " ";
	}
	cout << endl;
	myTestFile1.close();
	myTestFile.open("C:/Users/Alex/Desktop/myTestFile.txt", ios::app);
	{
		myTestFile << 666;
	}
	myTestFile.close();
	system("Pause");
	return 0;
}