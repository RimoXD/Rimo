#include "motorcar.h"
#include<iostream>
using namespace std;

motorcar::motorcar(int seatnum, int maxspeed, int weight):
	vehicle(maxspeed,weight)
{
	m_seatnum = seatnum;
	cout << "motorcar constructor called. seatnum:" << m_seatnum << endl;
}
