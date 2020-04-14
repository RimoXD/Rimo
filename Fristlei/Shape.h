#pragma once
class Shape
{
	int m_ID;
public:
	Shape(int ID);
	~Shape();
	int getID();
	void setID(int ID);
	int getArea();
};


/*shape类有以下成员
1）私有成员m_ID
2）公有getter和setter
3）计算面积函数getArea()，返回0;
4）构造与析构函数*/
