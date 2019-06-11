#pragma once
class Figure {
private:
	double pointX;
	double pointY;
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	double length;
	virtual bool isPointIntFigure();
protected:
	double getDistBtwTwoPoints(double x1, double y1, double x2, double y2);
};
class Circle : public Figure
{
	Circle(double, double, double);
};
class Triangle :public Figure
{
	Triangle(double, double, double, double, double, double);
};
class Rectangle : public Figure
{
	Rectangle(double, double, double, double);
};