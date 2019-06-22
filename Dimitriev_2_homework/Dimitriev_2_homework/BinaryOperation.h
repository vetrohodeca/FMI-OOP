#pragma once
//x- xor
//b- biimplication
//i- implication
//o- V
//a-&&
//n- negation
#include"Expression.h"
class BinaryOperation : public BooleanExpression {
	BooleanExpression* left;
	char op;
	BooleanExpression* right;
public:
	BinaryOperation(BooleanExpression* left, char ch, BooleanExpression* right);
	void Print();
	~BinaryOperation();
	bool Evaluate();
};
