#pragma once
#include"Garage.h"
Garage::Garage()
{
	this->capacity = 8;
	this->len = 0;
	this->vechicleList = new Vechicle*[capacity];
}
void Garage::resize() 
{
	Vechicle** save = this->vechicleList;
	capacity *= 2;
	this->vechicleList = new Vechicle*[this->capacity];
	for (int i = 0; i < this->len; i++) {
		this->vechicleList[i] = save[i];
	}
	delete[] save;
}
void Garage::Free()
{
	for (size_t i = 0; i < len; i++)
	{
		delete vechicleList[i];
	}
	delete[] vechicleList;
}
void Garage::CopyFrom(const Garage& other)
{
	vechicleList = new Vechicle	*[other.len];
	for (size_t i = 0; i < other.len; i++)
	{
		vechicleList[i] = other.vechicleList[i]->clone();
	}
	this->capacity = other.capacity;
	this->len = other.len;
}
 Garage::Garage(Garage& other)
{
	CopyFrom(other);
}
 Garage& Garage::operator=(Garage& other)
 {
	 if (this != &other)
	 {
		 Free();
		 CopyFrom(other);
	 }
	 return *this;
 }
 void Garage::AddVechicle(Vechicle* vechicle)
{
	if (capacity == len)
		resize();
	vechicleList[len++]=vechicle ;
}
void Garage::addCar(int speed, const char*name)
{
	Car* c = new Car(speed, name);
	c->setType(0);
	AddVechicle(c);
}
void Garage::addTIR(int speed, const char*name)
{
	TIR* c = new TIR(speed, name);
	c->setType(2);
	AddVechicle(c);
}
void Garage::addBus(int speed, const char*name)
{
	Bus* c= new Bus(speed, name);
	c->setType(1);
	AddVechicle(c);
}
int Garage::numberOfSuitableVechicles(int highWay, int speedWay, int slowWay, double time)
{
	int count=0;
	for (size_t i = 0; i < len; i++)
	{
		double currTime = 0;
		currTime = highWay / vechicleList[i]->getHighwaySpeed() + 
			speedWay / vechicleList[i]->getSpeedWaySpeed() +
			slowWay / vechicleList[i]->getSlowWaysSpeed();
		if (currTime <= time)
		{
			count++;
		}
	}
	return count;
}