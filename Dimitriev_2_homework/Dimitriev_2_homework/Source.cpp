#include<iostream>
#include"Expression.h"
#include"Num.h"
#include"BinaryOperation.h"
#include"UnaryOperation.h"
using namespace std;
int main()
{
	BooleanExpression* l = new Num (0);
	BooleanExpression* r = new Num(0);
	BooleanExpression* final1 = new BinaryOperation(l, 'n', r);
	final1->Print();
	cout<<final1->Evaluate();
	cout << endl;
	BooleanExpression* p = new Num(1);
	BooleanExpression* final2 = new UnaryOperation('n', p);
	final2->Print();
	cout << final2->Evaluate();
	delete final1, final2;
	system("pause");
	return 0;
}