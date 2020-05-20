#pragma once
#include<iostream>
using namespace std;
template <typename T>
class linkedList
{
public:
	linkedList();
	~linkedList()
	{

	}
	bool initiate();
	void insert(int val);
	void print();
	bool remove(int n, int& val);
	int Length();

	typedef struct MyStruct
	{
		T myval;
		MyStruct* next;
	}str;

private:
	str* head;
	str* plast;
	str* pnow;
	int len;
};

template<typename T>
inline linkedList<T>::linkedList()
{
	head = NULL;
	plast = NULL;
	pnow = NULL;
	len = 0;
}

template<typename T>
inline bool linkedList<T>::initiate()
{
	head = new str;
	plast = head;
	pnow = head;
	if (head != NULL)
		return true;
	else
		return false;
}

template<typename T>
inline void linkedList<T>::insert(int val)
{
	pnow->myval = val;
	plast = pnow;
	pnow->next = new str;
	pnow = pnow->next;
	pnow->next = NULL;
	len++;
}

template<typename T>
inline void linkedList<T>::print()
{	
	int i=0;
	str* p;
	p = head;
	while (i<len)
	{
		cout << p->myval <<" ";
		p = p->next;
		i++;
	}
	cout << endl;
}

template<typename T>
inline bool linkedList<T>::remove(int n, int& val)
{
	if (n > len)
	{
		cout << "pos > len, failed" << endl;
		return false;
	}
	if (n <= 0)
	{
		cout << "pos <= 0, failed" << endl;
		return false;
	}
	n--;
	int i;
	str* p,*last;
	p = last = head;
	for (i = 0;i < n;i++)
	{
		last = p;
		p = p->next;
	}
	if (n == len)
	{
		last->next = NULL;
		val = p->myval;
		delete p;
		len--;
	}
	else
	{
		last->next = p->next;
		val = p->myval;
		delete p;
		len--;
	}
	return true;
}

template<typename T>
inline int linkedList<T>::Length()
{
	return len;
}
