#pragma once
#include "bicycle.h"
#include "motorcar.h"
#include<iostream>
using namespace std;
class motorcycle :
	public bicycle
	,public motorcar
{
public:
	motorcycle(int height, int setnum, int maxspeed, int weight);
	~motorcycle()
	{
		cout << "motorcycle destructor called" << endl;
	}
};

