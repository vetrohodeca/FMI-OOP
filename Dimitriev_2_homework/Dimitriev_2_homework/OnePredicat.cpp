#pragma once
#include"OnePredicat.h"
#include<iostream>
OnePredicatOperation::OnePredicatOperation(char ch, BooleanExpression* operand)
{
	this->op = ch;
	this->operand = operand;
}
void OnePredicatOperation::Print()
{
	std::cout << op<<'(';
	operand->Print(); 
	std::cout << ")="  ;
}
OnePredicatOperation::~OnePredicatOperation()
{
	delete operand;
}
bool OnePredicatOperation:: Evaluate()
{
	if (operand->Evaluate() == true) return false;
	return true;
}