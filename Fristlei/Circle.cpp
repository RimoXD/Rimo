#include "Circle.h"
#include<iostream>
using namespace std;
float pi = 3.14;

Circle::Circle(int r, int ID):Shape(ID),R(r)
{
	cout << "Circle constructor called:" << this->Shape::getID() << endl;
}

Circle::~Circle()
{
	cout << "Circle destructor called:" << this->Shape::getID() << endl;
}

int Circle::getR()
{
	return R;
}

int Circle::getID()
{
	return this->Shape::getID();
}

void Circle::set(int ID, int r)
{
	this->Shape::setID(ID);
	R = r;
}

float Circle::getArea()
{
	return R*R*pi;
}
