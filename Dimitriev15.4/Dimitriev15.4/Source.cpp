#include<iostream>
using namespace std;
class Complex
{
	int real;
	int im;
public:
	Complex(int real, int im)
	{
		this->real = real;
		this->im = im;
	}
	void print()
	{
		cout << this->real<<" + " << this->im<<"i"<<endl;
	}
	Complex& operator+=(const Complex& other)
	{
		real += other.real;
		im += other.im;
		return *this;
	}
};
int main()
{
	Complex c(3, 5);
	c.print();
	c += c;
	c.print();
	system("pause");
	return 0;
}