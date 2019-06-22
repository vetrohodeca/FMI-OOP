#pragma once
#include"Vechicle.h"
class Bus : public Vechicle
{
private:

public:
	void setSpeed();
	Vechicle* clone();
	Bus(int speed,const char* name);
};