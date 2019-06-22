#pragma once
#include"Vechicle.h"
class Car : public Vechicle
{
private:

public:
	Car(int speed, const char* name);
	void setSpeed();
	Vechicle* clone();
};