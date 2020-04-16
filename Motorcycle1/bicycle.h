#pragma once
#include "vehicle.h"
#include<iostream>
using namespace std;
class bicycle :
	virtual public vehicle
{
	int m_height;
public:
	bicycle(int height,int maxspeed,int weight);
	~bicycle()
	{
		cout << "bicycle destructor called. height:" << m_height << endl;
	}

};

