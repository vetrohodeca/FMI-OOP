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
	this->vechicleList = new Vechicle*[this->capacity*2];
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
bool Garage::AddVechicle(Vechicle* vechicle)
{
	if (capacity == len)
		resize();
	vechicleList[len++]=vechicle ;
	return true;
}
bool Garage::addCar(int speed, const char*name)
{
	Car* c = new Car(speed, name);
	c->setType(0);
	if (!AddVechicle(c))
	{
		delete c;
		return false;
	}
}
bool Garage::addTIR(int speed, const char*name)
{
	TIR* c = new TIR(speed, name);
	c->setType(2);
	if (!AddVechicle(c))
	{
		delete c;
		return false;
	}
}
bool Garage::addBus(int speed, const char*name)
{
	Bus* c= new Bus(speed, name);
	if (!AddVechicle(c))
	{
		delete c;
		return false;
	}
}
int Garage::numberOfSuitableVechicles(int highWay, int speedWay, int slowWay, double time)
{
	int count=0;
	for (size_t i = 0; i < len; i++)
	{
		double currTime = 0;
		if (vechicleList[i]->getType() == 0)// car
		{
			currTime = (highWay + speedWay + slowWay) / (vechicleList[i]->getSpeed());
			if (currTime <= time)
			{
				count++;
			}
		}
		else if (vechicleList[i]->getType() == 1)// bus
		{
			currTime = (highWay/vechicleList[i]->getSpeed()+ speedWay / (vechicleList[i]->getSpeed()/2) + slowWay/(vechicleList[i]->getSpeed()/2.5));
			if (currTime <= time)
			{
				count++;
			}
		}
		else if (vechicleList[i]->getType() == 2)//TIR
		{
			currTime = (highWay / (vechicleList[i]->getSpeed() / 2)  + speedWay / (vechicleList[i]->getSpeed() / 4) + slowWay / 20);
			if (currTime <= time)
			{
				count++;
			}
		}
		else std::cout << "Error with Vechicle";
	}
	return count;
}