#include<iostream>
using namespace std; 

int main()
{
	char a[8];
	int b=36,i,j,count=1;
	cin>>a;
	for (i=0;i<8;i++)
	{
		for(j=i+1;j<8;j++)
		{
			if((a[i]-a[j])==0||(a[j]-a[i])==(j-i)||(a[j]-a[i])==(i-j)){
				cout<<"No Answer"<<endl;
				count=0;
				break;
			}
		}
		if(!count)break;
	}
	i=0;
	if(count){
	while(1)
	{
		if(a[i]!='*')
		{
			b=b-(a[i]-48);
		}
		i++;
		if(i==8)break;
	 } 
	cout<<b<<endl;
	}
	return 0;
 } 



