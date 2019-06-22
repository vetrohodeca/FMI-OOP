#pragma once
#include"Vechicle.h"
#include"Car.h"
#include"Bus.h"
#include"TIR.h"
class  Garage
{
private:
	Vechicle** vechicleList;
	int len;
	int capacity;
	void resize();
	void Free();
	void CopyFrom(const Garage& other);
	bool AddVechicle(Vechicle* vechicle);
public:
	int numberOfSuitableVechicles(int highWay, int speedWay, int slowWay, double timeInHours);
	Garage();
	Garage( Garage& other);
	Garage& operator=(Garage&other);
	bool addCar(int speed,const char*name);
	bool addTIR(int speed, const char*name);
	bool addBus(int speed, const char*name);
};