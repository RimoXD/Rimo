// 油桶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
using namespace std;
#define PI 3.1415926

class sylinder//建立一个油桶类 
{
    public:
        sylinder(double dd, double hh);//构造函数 
        ~sylinder();//析构函数 
        double getvolumn();//求体积 
        double getarea();//求面积 
    private:
        double r, h;
};

sylinder::sylinder(double hh, double dd)
{
    r = dd;
    h = hh;
    cout << "构造函数被调用" << endl;
}

sylinder::~sylinder()
{
    cout << "析构函数被调用" << endl;
}

double sylinder::getvolumn()
{
    return r*r*PI*h;
}

double sylinder::getarea()
{
    double s;
    s =2.0*r*r*PI+r*2.0*h*PI;
    return s;
}

int main()
{
    double d, h;
    cin >> d >> h;
    sylinder can(h, d / 2);
    cout << fixed << setprecision(6);
    cout << "油桶的容积是" << can.getvolumn() << " " << endl;
    cout << "铁皮的面积是" << can.getarea() << endl;
}

