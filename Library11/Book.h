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


#endif //LIBRARY_BOOK_H
