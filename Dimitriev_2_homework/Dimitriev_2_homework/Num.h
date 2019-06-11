#include"Expression.h"
#include<iostream>
class Num : public BooleanExpression{
public:


	bool Evaluate() ;
	Num(bool number);
	int number;
	void Print();
};