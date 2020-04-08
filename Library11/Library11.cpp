#include  <iostream>
#include <string>
#include "Book.h"
#include "Store.h"

using namespace std;


int main() {
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "第一本书入库" << endl;
    s.in(b1);
    cout << "第二本书入库" << endl;
    s.in(b2);
    cout << "第三本书入库" << endl;
    s.in(b3);
    cout << "现有库存书籍数量：" << s.GetCount() << endl;
    cout << "查找并出库图书：离散数学" << endl;
    Book  tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
    {
        s.out("离散数学");
        cout << "离散数学  已成功出库" << endl;
    }
    else
        cout << "没有找到name为离散数学的书" << endl;
    cout << "现有库存书籍数量：" << s.GetCount() << endl;

    cout << "查找图书  ID：3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
    else
        cout << "没有找到ID为" << 3 << "的书" << endl;

    cout << "查找图书  name：离散数学" << endl;
    tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
        cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
    else
        cout << "没有找到name为离散数学的书" << endl;

    cout << "输出所有库存图书的信息" << endl;
    s.printList();
    cout << "程序运行结束" << endl;
    return  0;
}
