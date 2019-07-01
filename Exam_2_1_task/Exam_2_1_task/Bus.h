#pragma once
#include"Vechicle.h"
class Bus : public Vechicle
{
private:

public:
	double getHighwaySpeed();
	double getSpeedWaySpeed();
	double getSlowWaysSpeed();
	void setSpeed();
	Vechicle* clone();
	Bus(int speed,const char* name);
};