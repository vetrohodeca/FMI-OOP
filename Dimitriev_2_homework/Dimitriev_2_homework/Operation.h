#pragma once
//x- xor
//b- biimplication
//i- implication
//o- V
//a-&&
//n- negation
#include"Expression.h"
class Operation : public BooleanExpression {
	BooleanExpression* left;
	char op;
	BooleanExpression* right;
public:
	Operation(BooleanExpression* left, char ch, BooleanExpression* right);
	void Print();
	~Operation();
	bool Evaluate();
};
