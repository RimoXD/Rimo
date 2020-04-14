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

/*Rectangle类从shape类继承，并派生以下成员
1）私有成员h, w
2）公有getter和setter
3）计算面积函数getArea()，返回计算面积;
4）构造与析构函数 */