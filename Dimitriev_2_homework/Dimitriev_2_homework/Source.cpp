#include<iostream>
#include"Expression.h"
#include"Num.h"
#include"Operation.h"
#include"OnePredicat.h"
using namespace std;
int main()
{
	BooleanExpression* l = new Num (0);
	BooleanExpression* r = new Num(0);
	BooleanExpression* final1 = new Operation(l, 'n', r);
	final1->Print();
	cout<<final1->Evaluate();
	cout << endl;
	BooleanExpression* p = new Num(1);
	BooleanExpression* final2 = new OnePredicatOperation('n', p);
	final2->Print();
	cout << final2->Evaluate();
	delete final1, final2;
	system("pause");
	return 0;
}