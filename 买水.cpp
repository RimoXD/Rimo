#include<iostream>
using namespace std;

void exchange();
int money,number,body,gai;

int main()
{
	cin>>money;
	number=body=gai=money;
	exchange();
	cout<<number;
	return 0;
 } 
 
void exchange()
{
	int eb,eg;
//��ƿ�� 
	number=number+body/2;
	eb=body/2;
	body=body%2;
//������ 
	number=number+gai/3;
	eg=gai/3;
	gai=gai%3;
//ʣ��ƿ�͸� 
	body=body+eb+eg;
	gai=gai+eb+eg;
	while(body>=2||gai>=3)
	exchange();
}
