#include<iostream> 
#include<iomanip> 
#include<cmath> 
using  namespace  std; 

//�и�������Ҫ����һ���û�������򣬹���Ҫ�����£�
//1����¼�û����˺š��������Ա����䡢���д��
//2�����Զ�̬�����û��Ĵ��
//��1�����û���Ǯʱ�������ӵ����д����
//  (2�����û�ȡǮʱ���������˻��п۳�
//  (3)  ���ȡǮ�������д���ܾ�ȡǮ������
//  (4) ���¼��Ϊ100.897Ԫ����Ϊ��Ч���룬Ӧ�þܾ�������ԭ��¼����������ԡ�Ԫ��Ϊ��λ��������С��λ�Ƿ֡���ͬѧ�ǿ���һ�£��������ЧӦ���������⡣


class Account  //����һ���û����� 
{
	public:
		void init(char num[20],char nam[20],char xxbb[100],int ag,float mone);
		void printmoney();
		void deposit(float put);
		void withdraw(double get);
	private:
		char number[20],name[20],xb[100];
		int age;
		float money;
};

//�����ʼ���� 
void Account::init(char num[20],char nam[20],char xxbb[100],int ag,float mone)
{
	int i=0;
	for(;num[i]!=NULL;i++)
	number[i]=num[i];
	i=0;
	for(;nam[i]!=NULL;i++)
	name[i]=nam[i];
	i=0;
	for(;xxbb[i]!=NULL;i++)
	xb[i]=xxbb[i];
	age=ag;
	money=mone;
	if((100*mone-(int)(100*mone))>0)
	{
		cout<<"������Ľ��Ϸ�"<<endl;
		money=0;
	}
}

//������д�� 
void Account::printmoney()
{
		cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl;
}

//������ 
void Account::deposit(float put)
{
	if((100.0*put-(int)(100.0*put))>0)
	{
		cout<<"������Ľ��Ϸ�"<<endl;
	}
	else {
		money+=put;
	}		
}

//ȡ����� 
void Account::withdraw(double get)
{
	if((100.0*get-(int)(100.0*get))>0)
	{
		cout<<"������Ľ��Ϸ�";
		cout<<endl;
	}
	else if(money<get)
		cout<<"���Ĵ�����"<<endl;
	else {
		money-=get;
	}	
}

int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X","Tom  Black","��",19,2000.89); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(89.471);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(10000); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.9);//��������Ĵ����� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        Account  jerry; 
        jerry.init("320203200910116569","Jerry  Black","Ů",11,100.956);//�����������Ľ��Ϸ� 
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
}
