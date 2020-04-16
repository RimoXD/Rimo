#include "motorcycle.h"
#include<iostream>
using namespace std;

motorcycle::motorcycle(int height, int setnum, int maxspeed, int weight):
	vehicle(maxspeed,weight),bicycle(height,maxspeed,weight),motorcar(setnum,maxspeed,weight)
{
	cout << "motorcycle constructor called" << endl;
}
