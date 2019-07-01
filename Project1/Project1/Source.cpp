#include"Suitcase.hpp"
int main()
{

	Suitcase<int> c;
	Suitcase<int >d;
	Suitcase<int >e;
	c.Add(1);
	c.Add(2);
	c.Add(3);
	c.Add(4);
	d.Add(5);
	d.Add(6);
	e = d + c;
	//c.print();
	//c.Get();
	d.print();
	system("pause");
	return 0;
}