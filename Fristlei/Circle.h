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

/*Circle���shape��̳У����������³�Ա
1��˽�г�Աr
2������getter��setter
3�������������getArea()�����ؼ������;
4����������������*/