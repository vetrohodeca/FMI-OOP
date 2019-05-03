#include<fstream>
#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	ofstream file("myTestFile.txt", ios::binary);
	{
		if (!file) {
			cerr << "File couldn’t be opened!\n";
			system("pause");
			return 1;
		}
		int N;
		cin >> N;
		int fn;
		char* name=new char[50];
		int* lenofNames = new int[N]; 
		for (int i = 0; i < N; i++)
		{
			cin >> fn;
			cin.ignore();
			file << fn;
			cin.getline(name,50);
			lenofNames[i] = strlen(name);
			int j = 0;
			while (j < lenofNames[i])
			{
				file << name[j];
				j++;
			}
		}
		file.close();
		ifstream file("myTestFile.txt", ios::binary);
		{
			if (!file) {
				cerr << "File couldn’t be opened!\n";
				system("pause");
				return 1;
			}
			for (int i = 0; i < N; i++)
			{
				char c1[5];
				char c2[1000];
				file.read(c1, 5);
				cout << c1[0] << c1[1] << c1[2] << c1[3] << c1[4];
				for (int  t= 0; t < lenofNames[i]; t++)
				{
					file.read(c2,i+ t);
					cout << c2[t+i];
				}
			}
		}
		system("pause");
		return 0;
	}
}