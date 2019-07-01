#include"TIR.h"
void TIR::setSpeed()
{
	if (this->speed < 80 || this->speed>150)
	{
		this->speed = 80;
	}
}
Vechicle* TIR::clone()
{
	TIR* copy = new TIR(*this);
	return copy;
}
TIR::TIR(int speed, const char*name)
{
	this->type = 2;
	this->speed = speed;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
double TIR::getHighwaySpeed()
{
	return speed / 2;
}
double TIR::getSpeedWaySpeed()
{
	return speed / 4;
}
double TIR::getSlowWaysSpeed()
{
	return 20;
}