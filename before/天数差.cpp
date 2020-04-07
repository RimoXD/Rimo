#include <iostream>
using namespace std;

//���һ��ʱ����
class CTime
{
    int year, month, day, hour, minute, second;
    int count;//����һ��Կ��
public:
    CTime(int iyear, int imonth, int iday, int ihour=0, int iminute=0, int isecond=0);//���캯����ʱ�����ʼ��Ϊ0
    ~CTime();//��������
    CTime(const CTime& B);//���ƹ��캯��
    int dayDiff(CTime t);//������ʱ��������
    void showTime();//���ʱ��
    int isvalid();//�жϺϷ���
    int maxday(int &month, int &year);//�ж����������ж�����
};

CTime::CTime(int iyear, int imonth, int iday, int ihour, int iminute, int isecond)
{
    count = 1;//Կ��

    //�ж�������
    if (!(iyear % 400 == 0 || iyear % 100 != 0 && iyear % 4 == 0))//���������꣬����
    {
        if (imonth <= 0 || imonth > 12)//�ж��·��Ƿ���ȷ
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if (imonth == 2 && iday >= 29 || iday <= 0)//2�³���28�죬�������
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if ((imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12 )&& iday > 31 || iday <= 0)//����
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if (imonth == 2 || imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)
        {
            if (iday > 30 || iday <= 0)//С��
            {
                cout << "date error!" << endl;
                cout << "���캯��������" << endl;
                count = 0;
            }
        }
    }
    else//�������
    {
        if (imonth <= 0 || imonth > 12)//�ж��·��Ƿ���ȷ
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if (imonth == 2 && iday > 29 || iday <= 0)//2�³���29�죬�������
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if ((imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12 )&& iday > 31 || iday <= 0)//����
        {
            cout << "date error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
        else if (imonth == 2 || imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11 )
        {
            if (iday > 30 || iday <= 0)//С��
            {
                cout << "date error!" << endl;
                cout << "���캯��������" << endl;
                count = 0;
            }
        }
    }

    //�ж�ʱ����
    if (count)
    {
        if (ihour >23 || iminute > 59 || isecond > 59 || ihour < 0 || iminute < 0 || isecond < 0)
        {
            cout << "time error!" << endl;
            cout << "���캯��������" << endl;
            count = 0;
        }
    }

    if (count)
    {
        year = iyear, month = imonth, day = iday, hour = ihour, minute = iminute, second = isecond;
        cout << "���캯��������" << endl;
    }
    else//���ݴ��󣬳�ʼ��Ϊ0
    {
        year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    }
}

CTime::~CTime()
{
    cout << "��������������" << endl;
}

CTime::CTime(const CTime& B)
{
    year = B.year, month = B.month, day = B.day, hour = B.hour, minute = B.minute, second = B.second;
    cout << "�������캯��������" << endl;
}

int CTime::dayDiff(CTime t)
{
    int i=0;
    if ((year > t.year) || (year == t.year && month > t.month) || (year == t.year && month == t.month && day > t.day))//�жϴ���
    {
        while (!(year == t.year && month == t.month && day == t.day))//��������Ⱥ�����
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
        while (!(year == t.year && month == t.month && day == t.day))//��������Ⱥ�����
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

int CTime::maxday(int &month,int &year)//�ж����������ж�����
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
    CTime  t2(2000, 1, 1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00 
    if (t1.isvalid())          //������ں�ʱ��Ϸ������������ 
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "������֮�������" << days << "��" << endl;
        days = t2.dayDiff(t1);
        cout << "������֮�������" << days << "��" << endl;
    }
}
