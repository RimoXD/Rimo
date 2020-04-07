#include "Store.h"

Store::Store()
{
	m_Count = 0;
	m_pBook = NULL;
	cout << "Store default constructor called!" << endl;
}

Store::Store(int n)
{
	m_Count = n;
	m_pBook = new Book[n];
	cout<< "Store constructor with (int n) called!"<<endl;
}

Store::Store(const Store& other)
{
	m_Count = other.m_Count;
	unsigned int i;
	m_pBook = new Book[m_Count];
	for (i = 0;i < m_Count;i++)
	{
		m_pBook[i] = other.m_pBook[i];
	}
	cout << "Store copy constructor called!" << endl;
}

Store::~Store()
{
	m_Count = 0;
	if (m_pBook != NULL)
	{
		delete[] m_pBook;
		cout << "Store destructor called!" << endl;
	}
}

void Store::SetCount(int n)
{
	m_Count = n;
}

void Store::in(Book& b)
{
	unsigned int i,count=0;
	Book* pBook;
	pBook = new Book[m_Count + 1];
	if (m_Count!= 0)
	{
		for (i = 0;i < m_Count;i++)
		{
			pBook[i] = m_pBook[i];
		}
		if (m_Count == 1)
			delete m_pBook;
		else if (m_Count >= 2)
			delete[] m_pBook;
		pBook[i].SetName(b.GetName());
		pBook[i].SetAuthor(b.GetAuthor());
		pBook[i].SetDate(b.GetDate());
		pBook[i].SetID(b.GetID());
		pBook[i].SetIntroduction(b.GetIntroduction());
		pBook[i].SetPage(b.GetPage());
		m_pBook = pBook;
	}
	else
	{
		m_pBook = new Book(b);
	}
	m_Count++;
}

void Store::out(string name)
{
	unsigned int i,j;
	Book* pBook;
	pBook = new Book[m_Count - 1];
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetName()==name)
		{
			j = i;
			for (i = 0;i < j;i++)
			{
				pBook[i] = m_pBook[i];
			}
			for (;i < m_Count-1;i++)
			{
				pBook[i] = m_pBook[i+1];
			}
			if (m_Count == 1)
				delete m_pBook;
			else if (m_Count >= 2)
				delete[] m_pBook;
			m_pBook = pBook;
			break;
		}
	}
	m_Count--;
}

Book Store::findbyID(int ID)
{
	Book* pBook=new Book[1];
	unsigned int i;
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetID() == ID)
		{
			pBook[0].SetName(m_pBook[i].GetName());
			pBook[0].SetAuthor(m_pBook[i].GetAuthor());
			pBook[0].SetDate(m_pBook[i].GetDate());
			pBook[0].SetID(m_pBook[i].GetID());
			pBook[0].SetIntroduction(m_pBook[i].GetIntroduction());
			pBook[0].SetPage(m_pBook[i].GetPage());
			break;
		}
	}
	return *pBook;
}

Book Store::findbyName(string name)
{
	Book* pBook;
	unsigned int i;
	Book book0;
	pBook = &book0;
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetName() == name)
		{
			Book book1(m_pBook[i]);
			pBook = &book1;
			break;
		}
	}
	return *pBook;
}

void Store::printList()
{
	unsigned int i;
	cout << "There are totally " << m_Count << "Books:" << endl;
	for (i = 0;i < m_Count;i++)
	{
		cout << "ID=" << m_pBook[i].GetID() << ";Name:" << m_pBook[i].GetName();
		cout<< ";Author:" << m_pBook[i].GetAuthor() << ";Date:" << m_pBook[i].GetDate() << ";" << endl;
	}
}