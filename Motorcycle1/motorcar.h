#pragma once
#include "vehicle.h"
#include<iostream>
using namespace std;
class motorcar :
	virtual public vehicle
{
	int m_seatnum;
public:
	motorcar(int seatnum,int maxspeed,int weight);
	~motorcar()
	{
		cout << "motorcar destructor called. seatnum:" << m_seatnum << endl;
	}
};

