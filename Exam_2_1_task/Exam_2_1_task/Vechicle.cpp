#include"Vechicle.h"
#include<iostream>
void Vechicle::Free()
{
	delete name;
}
void Vechicle::CopyFrom(Vechicle& other)
{
	this->speed = other.speed;
	this->type = other.type;
	int len = strlen(other.name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Vechicle::Vechicle(Vechicle& other)
{
	CopyFrom(other);
}
Vechicle& Vechicle::operator=(Vechicle& other)
{
	if (this != &other)
	{
		delete name;
		CopyFrom(other);
	}
	return *this;
}
Vechicle::Vechicle()
{
	this->speed = 0;
	this->type = -1;
	this->name = nullptr;
}
Vechicle::Vechicle(int speed, const char* name, int type)
{
	this->type = type;
	this->speed = speed;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
double Vechicle::getSpeed() const
{
	return this->speed;
}
int Vechicle::getType() const
{
	return this->type;
}
void Vechicle::setType(int type)
{
	this->type = type;
}