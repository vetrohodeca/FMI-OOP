#include<iostream>
using namespace std;
class drink
{
private:
	char* mark;
	int ml;
	void CopyFrom(const drink& other)
	{
		int len = strlen(other.mark);
		mark = new char[len + 1];
		strcpy_s(mark,30, other.mark);
		ml = other.ml;
	}
	void Free()
	{
		delete[]mark;
		ml = 0;
	}
public:
	drink()
	{
		mark = new char[6];
		strcpy_s(this->mark,30, "Water");
		this->ml = 300;
	}
	drink(const char* mark, int ml)// vinagi kopirame kogato 
	{
		int len = strlen(mark);
		this->mark = new char[len + 1];
		strcpy_s(this->mark,30 , mark);

		this->ml = ml;
	}
	void setML(int ml)
	{
		if (ml < 100 || ml>1000)
		{
			ml = 500;
		}
		this->ml = ml;
	}
	int getML() const
	{
		return ml;
	}
	const char* getMark() const
	{
		return mark;
	}
	drink(const drink& other)
	{
		CopyFrom(other);
	}// operator = vrushta , copy constructor ne pravi
	drink& operator=(const drink& other)
	{
		if (this != &other)
		{
			Free();
			CopyFrom(other);
		}
		return *this;
	}
	~drink()
	{
		Free();		
	}
};
bool func(drink& d1, drink& d2)
{
	return false;
}
bool operator>(const drink& lhs, const drink& rhs)
{
	return (lhs.getML() > rhs.getML());
}
class AlcohilDrink : public drink
{
private:
	int percentAlcohol;
public:
	AlcohilDrink(const char* mark, int ml, int percentAlcohol) :drink(mark, ml)
	{
		setAlcohol(percentAlcohol);
	}
	void setAlcohol(int alcohol)
	{
		if (alcohol < 4 || alcohol>98)
		{
			alcohol = 20;
			percentAlcohol = alcohol;
		}
	}
};

// nasledqvane alcoholDrink->drink
int main()
{
	drink T1;
	cout << T1.getMark()<<endl;
	AlcohilDrink T("Spirt",100,98);
	
	
	
	
	
	
	/*drink T("Fanta", 500);
	drink T2("Coke", 500);
	cout<<(T > T2) << endl;*/
	system("pause");
	return 0;
}
//suzdavame alcoholdrink obekt, vikame negoviq kosntruktor, toi vika na drink konstruktora
//shawol copy