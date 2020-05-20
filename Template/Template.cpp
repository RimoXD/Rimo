#include <iostream>
#include <iomanip>
#include "linkedList.h"
using namespace std;


int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if (!L1.initiate())
        return 0;

    cin >> n;//输入链表中数据个数
    for (int i = 0; i < n; i++) //输入n个数，并插入链表
    {
        cin >> val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：";
    L1.print();//打印链表

    cin >> n;//输入需要删除的数据的位置
    if (L1.remove(n, val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout << "Delete the data at position(" << n << "):" << val << endl;
        cout << "New Length：" << L1.Length() << endl;//输出链表长度
        cout << "data：";
        L1.print();//打印链表
    }

    return 0;
}
