#pragma once
#include "Shape.h"
#include<iostream>
using namespace std;
class Rectangle :
	public Shape
{
	int m_Chang, m_Kuan;
public:
	Rectangle(int chang, int kuan, int ID);
	~Rectangle();
	int getchang() {
		return m_Chang;
	}
	int getkuan() {
		return m_Kuan;
	}
	int getID() {
		return this->Shape::getID();
	}
	void set(int chang,int kuan,int ID);
	int getArea();
};

/*Rectangle���shape��̳У����������³�Ա
1��˽�г�Աh, w
2������getter��setter
3�������������getArea()�����ؼ������;
4���������������� */