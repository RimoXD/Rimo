#pragma once
#include <iostream>
#include "Book.h"
using namespace std;
class Store
{
	Book* m_pBook;//ָ������new������̬������Book����
	unsigned int m_Count;//��ʾ�����ͼ�������
public:
	Store();
	Store(int n);
	Store(const Store& other);
	~Store();
	int GetCount() {
		return m_Count;
	};
	void SetCount(int n);
	void in(Book& b);
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();


};

