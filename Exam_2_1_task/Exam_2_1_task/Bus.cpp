#include"Bus.h"
void Bus::setSpeed()
{
	if (this->speed < 120 || this->speed>160)
	{
		this->speed = 120;
	}
}
Vechicle*Bus::clone()
{
	Bus* copy = new Bus(*this);
	return copy;
}
Bus::Bus(int speed, const char* name)
{
	this->speed = speed;
	this->type = 1;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
double Bus::getHighwaySpeed()
{
	return speed;
}
double Bus::getSpeedWaySpeed()
{
	return speed / 2;
}
double Bus::getSlowWaysSpeed()
{
	return speed / 2.5;
}