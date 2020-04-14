#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
using namespace std;

int main()
{
    Shape  s(1);//1表示ID 
    Circle  c(4, 2);//4表示半径，2表示ID 
    Rectangle  r(4, 5, 3);//4和5表示长和宽，3表示ID 
    cout << "Shape的面积" << s.getArea() << endl;
    cout << "Circle的面积" << c.getArea() << endl;
    cout << "Rectangle的面积" << r.getArea() << endl;
}

/*shape类有以下成员
1）私有成员m_ID
2）公有getter和setter
3）计算面积函数getArea()，返回0;
4）构造与析构函数
Circle类从shape类继承，并派生以下成员
1）私有成员r
2）公有getter和setter
3）计算面积函数getArea()，返回计算面积;
4）构造与析构函数
Rectangle类从shape类继承，并派生以下成员
1）私有成员h, w
2）公有getter和setter
3）计算面积函数getArea()，返回计算面积;
4）构造与析构函数*/