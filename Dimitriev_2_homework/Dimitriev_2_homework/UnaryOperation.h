#pragma once
#include"BinaryOperation.h"
class UnaryOperation : public BooleanExpression {
	BooleanExpression* operand;
	char op;

public:
	UnaryOperation( char ch, BooleanExpression* operand);
	void Print();
	~UnaryOperation();
	bool Evaluate();
};