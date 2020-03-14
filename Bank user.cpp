#include<iostream> 
#include<iomanip> 
#include<cmath> 
using  namespace  std; 

//有个银行需要开发一个用户管理程序，功能要求如下：
//1、记录用户的账号、姓名、性别、年龄、现有存款
//2、可以动态管理用户的存款
//（1）当用户存钱时将金额添加到现有存款内
//  (2）当用户取钱时，从现有账户中扣除
//  (3)  如果取钱金额超过现有存款，则拒绝取钱操作。
//  (4) 如果录入为100.897元，即为无效输入，应该拒绝操作。原因：录入的数据是以“元”为单位，金额的最小单位是分。请同学们考虑一下，如果能有效应对这类问题。


class Account  //定义一个用户的类 
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

//填入初始数据 
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
		cout<<"您输入的金额不合法"<<endl;
		money=0;
	}
}

//输出现有存款 
void Account::printmoney()
{
		cout<<name<<"的存款为"<<fixed<<setprecision(2)<<money<<endl;
}

//存入存款 
void Account::deposit(float put)
{
	if((100.0*put-(int)(100.0*put))>0)
	{
		cout<<"您输入的金额不合法"<<endl;
	}
	else {
		money+=put;
	}		
}

//取出存款 
void Account::withdraw(double get)
{
	if((100.0*get-(int)(100.0*get))>0)
	{
		cout<<"您输入的金额不合法";
		cout<<endl;
	}
	else if(money<get)
		cout<<"您的存款金额不足"<<endl;
	else {
		money-=get;
	}	
}

int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X","Tom  Black","男",19,2000.89); 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(89.471);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(10000); 
        tom.printmoney();//输出：Tom  Black的存款为12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.123);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.9);//输出：您的存款金额不足 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        Account  jerry; 
        jerry.init("320203200910116569","Jerry  Black","女",11,100.956);//输出：您输入的金额不合法 
        jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}
