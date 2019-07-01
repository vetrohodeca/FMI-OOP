#include"Car.h"

void Car::setSpeed()
{
	if (this->speed < 180 || this->speed>240)
	{
		this->speed = 200;
	}
}
Vechicle* Car::clone()
{
	Car* copy = new Car(*this);
	return copy;
}
Car::Car(int speed, const char*name)
{
	this->type = 0;
	this->speed=speed;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
double Car::getHighwaySpeed()
{
	return speed;
}
double Car::getSpeedWaySpeed()
{
	return speed;
}
double Car::getSlowWaysSpeed()
{
	return speed;
}