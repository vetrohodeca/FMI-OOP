#pragma once
#include"Operation.h"
class OnePredicatOperation : public BooleanExpression {
	BooleanExpression* operand;
	char op;

public:
	OnePredicatOperation( char ch, BooleanExpression* operand);
	void Print();
	~OnePredicatOperation();
	bool Evaluate();
};