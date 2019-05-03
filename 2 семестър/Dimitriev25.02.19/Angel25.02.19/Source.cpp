#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int num;
	ofstream f;//pravim potoka
	f.open("C:/Users/Alex/Desktop/test.txt",ios::app);    // svurzvame potoka- davame mu put, ako ne zdadem put ->faila se pishe v direktoriqta na programata
	if (f.fail())
	{
		cout << "Error";
		return 1;
	}
	f << 45;
	f >> num;
	cout << num;
	f.close();
	system("pause");
	return 0;
}