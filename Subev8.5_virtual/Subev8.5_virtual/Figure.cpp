#include<iostream>
#include <math.h>
#include "Figure.h"
double Figure::getDistBtwTwoPoints(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) +
		pow(y2 - y1, 2) * 1.0);
}
Circle::Circle(double x1, double y1, double radius) 
{

}