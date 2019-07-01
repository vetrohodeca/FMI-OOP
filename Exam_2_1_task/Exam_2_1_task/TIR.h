#pragma once
#include"Vechicle.h"
class TIR : public Vechicle
{
private:

public:
	void setSpeed();
	Vechicle* clone();
	TIR(int speed, const char* name);
	double getHighwaySpeed();
	double getSpeedWaySpeed();
	double getSlowWaysSpeed();
};