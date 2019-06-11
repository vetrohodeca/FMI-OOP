#include"Num.h"
Num::Num(bool number)
{
	this->number = number;
	isANumber = 1;
}
void Num::Print()
{
	std::cout << number;
}
bool Num::Evaluate() 
{
	return number;
}