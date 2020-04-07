#include <iostream>
using namespace std;

//设计一个时间类
class CTime
{
    int year, month, day, hour, minute, second;
    int count;//设置一个钥匙
public:
    CTime(int iyear, int imonth, int iday, int ihour=0, int iminute=0, int isecond=0);//构造函数，时分秒初始化为0
    ~CTime();//析构函数
    CTime(const CTime& B);//复制构造函数
    int dayDiff(CTime t);//计算两时间天数差
    void showTime();//输出时间
    int isvalid();//判断合法性
    int maxday(int &month, int &year);//判断这个月最多有多少天
};

CTime::CTime(int iyear, int imonth, int iday, int ihour, int iminute, int isecond)
{
    count = 1;//钥匙

    //判断年月日
    if (!(iyear % 400 == 0 || iyear % 100 != 0 && iyear % 4 == 0))//若不是闰年，进入
    {
        if (imonth <= 0 || imonth > 12)//判断月份是否正确
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if (imonth == 2 && iday >= 29 || iday <= 0)//2月超过28天，输出错误
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if ((imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12 )&& iday > 31 || iday <= 0)//大月
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if (imonth == 2 || imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)
        {
            if (iday > 30 || iday <= 0)//小月
            {
                cout << "date error!" << endl;
                cout << "构造函数被调用" << endl;
                count = 0;
            }
        }
    }
    else//闰年进入
    {
        if (imonth <= 0 || imonth > 12)//判断月份是否正确
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if (imonth == 2 && iday > 29 || iday <= 0)//2月超过29天，输出错误
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if ((imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12 )&& iday > 31 || iday <= 0)//大月
        {
            cout << "date error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
        else if (imonth == 2 || imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11 )
        {
            if (iday > 30 || iday <= 0)//小月
            {
                cout << "date error!" << endl;
                cout << "构造函数被调用" << endl;
                count = 0;
            }
        }
    }

    //判断时分秒
    if (count)
    {
        if (ihour >23 || iminute > 59 || isecond > 59 || ihour < 0 || iminute < 0 || isecond < 0)
        {
            cout << "time error!" << endl;
            cout << "构造函数被调用" << endl;
            count = 0;
        }
    }

    if (count)
    {
        year = iyear, month = imonth, day = iday, hour = ihour, minute = iminute, second = isecond;
        cout << "构造函数被调用" << endl;
    }
    else//数据错误，初始化为0
    {
        year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    }
}

CTime::~CTime()
{
    cout << "析构函数被调用" << endl;
}

CTime::CTime(const CTime& B)
{
    year = B.year, month = B.month, day = B.day, hour = B.hour, minute = B.minute, second = B.second;
    cout << "拷贝构造函数被调用" << endl;
}

int CTime::dayDiff(CTime t)
{
    int i=0;
    if ((year > t.year) || (year == t.year && month > t.month) || (year == t.year && month == t.month && day > t.day))//判断大年
    {
        while (!(year == t.year && month == t.month && day == t.day))//两日期相等后跳出
        {
            t.day++;
            i++;
            if (t.day > maxday(t.month,t.year))
            {
                t.month++;
                t.day = 1;
            }
            if (t.month > 12)
            {
                t.year++;
                t.month = 1;
            }
        }
    }
    else
    {
        while (!(year == t.year && month == t.month && day == t.day))//两日期相等后跳出
        {
            day++;
            i++;
            if (day > maxday(month,year))
            {
                month++;
                day = 1;
            }
            if (month > 12)
            {
                year++;
                month = 1;
            }
        }
    }
    return i;
}

void CTime::showTime()
{
    cout << year << "/" << month << "/" << day <<" "<< hour << ":" << minute << ":" << second <<endl;
}

int CTime::isvalid()
{
    return count;
}

int isrun(int year)
{
    int i=1;
    if (!(year % 400 == 0 || year % 100 != 0 && year % 4 == 0))
        i = 0;
    return i;
}

int CTime::maxday(int &month,int &year)//判断这个月最多有多少天
{
    int maxday;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        maxday = 31;
    }
    else if (month == 2)
    {
        if (isrun(year))
        {
            maxday = 29;
        }
        else maxday = 28;
    }
    else maxday = 30;
    return maxday;
}

int main()
{
    int  year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime  t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00 
    if (t1.isvalid())          //如果日期和时间合法，则计算天数 
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days = t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}
