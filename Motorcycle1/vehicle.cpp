#include "vehicle.h"
#include<iostream>
using namespace std;
vehicle::vehicle(int maxspeed, int weight)
{
	m_maxspeed = maxspeed;
	m_weight = weight;
	cout << "vehicle constructor called. maxspeed:" << maxspeed << "; weight" << weight << endl;
}
