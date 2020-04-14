#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
	int R;
public:
	Circle(int R,int ID);
	~Circle();
	int getR();
	int getID();
	void set(int ID,int r);
	int getArea();
};

/*Circle类从shape类继承，并派生以下成员
1）私有成员r
2）公有getter和setter
3）计算面积函数getArea()，返回计算面积;
4）构造与析构函数*/