#pragma once
#include"UnaryOperation.h"
#include<iostream>
UnaryOperation::UnaryOperation(char ch, BooleanExpression* operand)
{
	this->op = ch;
	this->operand = operand;
}
void UnaryOperation::Print()
{
	std::cout << op<<'(';
	operand->Print(); 
	std::cout << ")="  ;
}
UnaryOperation::~UnaryOperation()
{
	delete operand;
}
bool UnaryOperation:: Evaluate()
{
	if (operand->Evaluate() == true) return false;
	return true;
}