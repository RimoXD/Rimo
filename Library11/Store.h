#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;
class Store
{
	vector<Book> m_Books;// 指向利用new操作动态创建的Book数组
	unsigned int m_Count;//表示库存中图书的数量
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


Store::Store()
{
    m_Count = 0;
    cout << "Store default constructor called!" << endl;
}

Store::Store(int n)
{
    m_Count = n;
    vector<Book>book(n);
    m_Books.swap(book);
    cout<< "Store constructor with (int n) called!"<<endl;
}

Store::Store(const Store& other)
{
    vector<Book>book(other.m_Books);
    m_Books.swap(book);
    cout << "Store copy constructor called!" << endl;
}

Store::~Store()
{
    m_Count = 0;
    cout << "Store destructor called!" << endl;

}

void Store::SetCount(int n)
{
    m_Count = n;
}

void Store::in(Book& b)
{
    m_Books.insert(m_Books.end(),b);
    //m_Book.push_back(b);
    m_Count++;
}

void Store::out(string name)
{
    unsigned int i,j;
    for (i = 0;i < m_Count;i++)
    {
        if (m_Books[i].GetName() == name)
        {
            m_Books.erase(m_Books.begin() + i);
            break;
        }
    }
    m_Count--;
}

Book Store::findbyID(int ID)
{
    Book pBook;
    //vector <Book>::iterator it;
    int i;
    for (i = 0;i < m_Count;i++)
    {
        if (m_Books[i].GetID() == ID)
        {
            pBook.SetName(m_Books[i].GetName());
            pBook.SetAuthor(m_Books[i].GetAuthor());
            pBook.SetDate(m_Books[i].GetDate());
            pBook.SetID(m_Books[i].GetID());
            pBook.SetIntroduction(m_Books[i].GetIntroduction());
            pBook.SetPage(m_Books[i].GetPage());
            break;
        }
    }
    return pBook;
}

Book Store::findbyName(string name)
{
    Book pBook;
    unsigned int i;
    vector <Book>::iterator it;
    for (it = m_Books.begin();it != m_Books.end();it++)
    {
        if ((*it).GetName() == name)
        {
            pBook.SetName((*it).GetName());
            pBook.SetAuthor((*it).GetAuthor());
            pBook.SetDate((*it).GetDate());
            pBook.SetID((*it).GetID());
            pBook.SetIntroduction((*it).GetIntroduction());
            pBook.SetPage((*it).GetPage());
            break;
        }
    }
    if ((*(m_Books.end() - 1)).GetName() == name)
    {
        pBook.SetName((*it).GetName());
        pBook.SetAuthor((*it).GetAuthor());
        pBook.SetDate((*it).GetDate());
        pBook.SetID((*it).GetID());
        pBook.SetIntroduction((*it).GetIntroduction());
        pBook.SetPage((*it).GetPage());
    }
    return pBook;
}

void Store::printList()
{
    unsigned int i;
    cout << "There are totally " << m_Count << "  Books:" << endl;
    for (i = 0;i < m_Count;i++)
    {
        cout << "ID=" << m_Books[i].GetID() << ";  Name:" << m_Books[i].GetName();
        cout<< ";  Author:" << m_Books[i].GetAuthor() << ";  Date:" << m_Books[i].GetDate() << ";" << endl;
    }
}


