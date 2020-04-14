#include "Rectangle.h"

Rectangle::Rectangle(int chang, int kuan, int ID):Shape(ID),m_Chang(chang),m_Kuan(kuan)
{
	cout << "Rectangle constructor called:" << this->Shape::getID() << endl;
}

Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:"<< this->Shape::getID() << endl;
}

void Rectangle::set(int chang, int kuan, int ID)
{
	m_Chang = chang;
	m_Kuan = kuan;
	this->Shape::setID(ID);
}

int Rectangle::getArea()
{
	return m_Chang*m_Kuan;
}
