#include "Shape.h"
#include<iostream>
using namespace std;

Shape::Shape(int ID)
{
	m_ID = ID;
	cout << "Shape constructor called:"<<ID<<endl;
}

Shape::~Shape()
{
	cout << "Shape destructor called:" << m_ID << endl;
}

int Shape::getID()
{
	return m_ID;
}

void Shape::setID(int ID)
{
	m_ID = ID;
}

int Shape::getArea()
{

	return 0;
}
