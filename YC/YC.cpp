#include <iostream>
#include <typeinfo>
#include <string> 
#include <exception>
#include "MyException1.h"
#include "MyException2.h"
using namespace std;

int divide(int a, int b)
{
    if (b == 0)
    {
        throw b;
    }
    return a / b;
}

int  main()
{
    int  id, k;
    cin >> id;
    char  a;
    string  s = "hello";
    try
    {
        switch (id)
        {
        case  1:
            throw  MyException1();
            break;
        case  2:
            throw  MyException2();
            break;
        case  3:
            k = divide(8, 0);
            break;
        case  4:
            a = s.at(10);
            cout << a << endl;
            break;
        default:
            break;
        }
    }
    catch (MyException1 & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (MyException2 & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (int& e)
    {
        cout << "exception:  " << e << endl;
    }
    catch (exception & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    cout << "Return  to  main()" << endl;
    return  0;
}