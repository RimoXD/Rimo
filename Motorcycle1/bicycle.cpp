#include "bicycle.h"
#include<iostream>
using namespace std;

bicycle::bicycle(int height, int maxspeed, int weight):
	vehicle(maxspeed,weight)
{
	m_height = height;
	cout << "bicycle constructor called. height:" << m_height << endl;
}
