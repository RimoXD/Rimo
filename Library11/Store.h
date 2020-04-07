#pragma once
#include <iostream>
#include "Book.h"
using namespace std;
class Store
{
	Book* m_pBook;//指向利用new操作动态创建的Book数组
	unsigned int m_Count;//表示库存中图书的数量
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

