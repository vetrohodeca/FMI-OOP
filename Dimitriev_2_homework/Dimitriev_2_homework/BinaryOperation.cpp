#include"BinaryOperation.h"
#include<iostream>
BinaryOperation::BinaryOperation(BooleanExpression* left, char ch, BooleanExpression* right)
{
	this->op = ch;
	this->left = left;
	this->right = right;
	isANumber = 0;
}
void BinaryOperation::Print()
{
	 std::cout << '(';
	left->Print();
	std::cout << op;
	right->Print();
	std::cout << ')' << '=';
}
BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}
bool BinaryOperation::Evaluate()
{
	bool value1 = left ->Evaluate();
	bool value2 = right->Evaluate();
	if (op == 'x')
	{
		if (value1 !=value2)
			return true;
		return false;
			
	}
	else if (op=='o')
	{
		if (value1 == 1 || value2 == 1)
		{
			return true;
		}
		return false;
	}
	else if (op == 'i')
	{
		if (value1==1&&value2==0)
		{
			return false;
		}
		return true;
	}
	if (op == 'a') {
		if (value1==1&&value2==1)
		{
			return true;
		}
		return false;
	}
	if (op=='b')
	{
		if (value1==value2)
		{
			return true;
		}
		return false;
	}
	if (op=='n')
	{
		if (value2==1)
		{
			return false;
		}
		return true;
	}
}