#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;
class Store
{
	vector<Book> m_Books;// ָ������new������̬������Book����
	unsigned int m_Count;//��ʾ�����ͼ�������
public:
	Store();
	Store(int n);
	Store(const Store& other);
	~Store();
	unsigned int GetCount() {
		return m_Count;
	};
	void SetCount(int n);
	void in(Book& b);
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
};

