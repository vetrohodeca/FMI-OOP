#include<iostream>
#include<fstream>
using namespace std;
class Beer
{
public:
	Beer(const char* mark, int ml)
	{
		setMl(ml);// pravq setfunciton vmesto da pisha pak
		strcpy_s(this->mark, mark);
	}
	void printBeer()
	{
		cout << mark << endl;
	}
	void printMl()
	{
		cout <<"Golemina: "<< ml<<endl;
	}
	int getMl()
	{
		return ml;
	}
	const char* getMark()// vinagi vrushtam sus const
	{
		return mark;
	}
	void setMl(int ml)
	{
		if (ml < 330)
		{
			ml = 330;
		}
		this->ml = ml;
	}
	void setMark(const char* mark)
	{
		int len = strlen(mark);
		if (len > 20 || len < 0)
		{
			this->mark[0] = '\0';
		}
		else strcpy_s(this->mark, mark);
	}
private:
	char mark[21];// max len of tring- 10;
	int ml;
};
int main()
{
	//cout << sizeof(Beer);
	Beer t("Zagorka", 200);
	Beer* t2 = new Beer("Stolichno", -6);// ot ravnoto nadqsno suzdava nov obekt, no ne go zapzva
	//cout << endl;
	t.printMl();
	t.printBeer();
	delete t2;
	system ("pause");
	return 0;
}















/*
struct test
{
	int a;
	int b;
};
struct test2
{
	char a;
	int b;	
};
int GetFileLen(ifstream& f)
{
	f.seekg(0, ios::end);// otidi nakraq na faila
	int size = f.tellg();// na koq poziciq e pointera
	f.seekg(0, ios::beg);
	return size;
}
int main()
{
	ofstream f("C:/Users/Alex/Desktop/TestFile.bat", ios::binary);
	test obj = { 3,4 };
	test2 obj4 = {'a',5 };
	test2 obj1 = { 'b',6 };
	test2 obj2 = { 'c',7 };
	test2 obj3 = { 'd',8 };

	f.write((char*)&obj, sizeof(test));
	f.write((char*)&obj1, sizeof(test));
	f.write((char*)&obj2, sizeof(test));
	f.write((char*)&obj3, sizeof(test));
	f.close();
	ifstream f1("C:/Users/Alex/Desktop/TestFile.bat", ios::binary);
	f1.read((char*)&obj, 4);

	cout << obj4.a<<endl;
	f1.close;
	system("pause");
	return 0;
}*/