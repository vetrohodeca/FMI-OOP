#pragma once
#include<iostream>
#pragma warning(disable :4996)
class Vechicle {
protected:
	int type;// 1 is for car, 2 is for bus, 3 is for tir
	char*name;
	int speed;
	void CopyFrom( Vechicle& other);
	void Free();
public:
	void setName(const char* name);
	void setType(int type);
	int getType() const;
	double getSpeed() const;
	Vechicle();
	Vechicle(int speed, const char* name, int type);
	Vechicle( Vechicle& other);
	Vechicle& operator=( Vechicle& other);// pri virtualni funkcii operator ravno trqbva da vrushta samo referenciq
	virtual Vechicle* clone() = 0;
	virtual void setSpeed()=0;
	virtual double getHighwaySpeed()=0;
	virtual double getSpeedWaySpeed()=0;
	virtual double getSlowWaysSpeed()=0;
}; 