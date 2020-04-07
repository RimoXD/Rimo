//
// Created by Rimo on 2020/4/7.
//

#include "Book.h"

Book::Book()
{
	m_ID = 0;
	m_Page = 0;
}

Book::Book(const Book& other)
{
	m_ID = other.m_ID;
	m_Name = other.m_Name;
	m_Introduction = other.m_Introduction;
	m_Author = other.m_Author;
	m_Date = other.m_Date;
	m_Page = other.m_Page;
}

Book::~Book()
{

}

int Book::GetID()
{
	return m_ID;
}

void Book::SetID(int id)
{
	m_ID = id;
}

string Book::GetName()
{
	return m_Name;
}

void Book::SetName(const string &name)
{
	m_Name = name;
}

string Book::GetIntroduction()
{
	return m_Introduction;
}

void Book::SetIntroduction(const string &introduction)
{
	m_Introduction = introduction;
}
string Book::GetAuthor()
{
	return m_Author;
}

void Book::SetAuthor(const string &author)
{
	m_Author = author;
}

string Book::GetDate()
{
	return m_Date;
}

void Book::SetDate(const string &date)
{
	m_Date = date;
}

int Book::GetPage()
{
	return m_Page;
}

void Book::SetPage(int page)
{
	m_Page = page;
}