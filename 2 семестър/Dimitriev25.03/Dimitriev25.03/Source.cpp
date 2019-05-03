#include<iostream>
#include<fstream>
using namespace std;
class Beer
{
public:
	char *mark;
	int ml;
private:
};
void SaveBeerToFile(const Beer& b, ofstream& f)
{
	int markNameLength = strlen(b.mark);
	f.write((const char*)&markNameLength, sizeof(int));// save len of the string
	f.write(b.mark, markNameLength);// save the string
	f.write((const char*)&b.ml, sizeof(int));// save ml
}
int main()
{
	Beer t;
	t.mark = new char[8];
	strcpy_s(t.mark,8, "Zagorka");
	Beer t2;
	t2.mark = new char[10];
	t2.ml = 500;
	strcpy_s(t.mark, 7, "Ariana");
	ofstream f1("beer.txt",ios::binary);
	SaveBeerToFile(t, f1);
	SaveBeerToFile(t2, f1);
	f1.close();
	ifstream f("Beer3.bat", ios::binary);
	Beer b;
	int markLen = 0;
	f.read((char*) &markLen, 4);
	b.mark = new char[markLen + 1];
	f.read(b.mark, markLen);
	b.mark[markLen] = '\0';
	f.read((char*)&b.ml, sizeof(int));
	cout << markLen << endl;
	system("pause");
	return 0;
}