//
// Created by Rimo on 2020/4/7.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
using namespace std;

class Book {
private:
    unsigned int m_ID;//±àºÅ
    string m_Name;
    string m_Introduction;
    string m_Author;
    string m_Date;
    unsigned int m_Page;//Ò³Êý
public:
    Book();

    Book(const Book& other);

    ~Book();

    int GetID();

    void SetID(int id);

    string GetName();

    void SetName(const string &name);

    string GetIntroduction();

    void SetIntroduction(const string &introduction);

    string GetAuthor();

    void SetAuthor(const string &author);

    string GetDate();

    void SetDate(const string &date);

    int GetPage();

    void SetPage(int page);
};

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


#endif //LIBRARY_BOOK_H
