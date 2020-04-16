#pragma once
#include<iostream>
using namespace std;
class vehicle
{
	int m_maxspeed, m_weight;
public:
	vehicle(int maxspeed,int weight);
	~vehicle(){
		cout << "vehicle destructor called. maxspeed:" << m_maxspeed << "; weight" << m_weight << endl;
	}
	void run() {
		cout << "vehicle run" << endl;
	}
	void stop() {
		cout << "vehicle stop" << endl;
	}

};

