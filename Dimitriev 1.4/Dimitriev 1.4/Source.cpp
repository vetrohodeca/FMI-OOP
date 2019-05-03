#include<iostream>
using namespace std;
bool hashDigits(const char* str, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (!str[i] >= '0'&&str[i] <= '9')
			return true;
	}
}
class IS {
	char *name;
	int fn;
public :
	IS(const IS& other)
	{
		int len = strlen(other.name);
		name = new char[len + 1];
		strcpy(name, other.name);
		fn = other.fn;
	}
	IS(const char*name, int fn)
	{
		setName(name);
		setFn(fn);
	}
	void setFn(int fn)
	{
		this->fn = fn;
	}
	void setName(const char*name)
	{
		int len = strlen(name);
		if (len > 9)
		{
			this->name[0] = '\0';
			return;
		}
		this->name = new char[len + 1];
		strcpy(this->name,name);
	}
	const char* getName() const {
		return name;
	}
	int getFn() const
	{
		return fn;
	}
	void printStudent()
	{
		cout << name << " " << fn << endl;
	}
private:
	
};
int main()
{
	IS s("Test", 12456);
	IS s2("Stamat", 1245);
	s = s2;
	s.printStudent();
	system("pause");
	return 0;
}
//ako imame ukazatelo razpisvame copy constructor, ako ne default vurshi rabota
// kopi konstruktora raboti i za nesuzdadeni obekti, a ravno samo za suzdadeni
