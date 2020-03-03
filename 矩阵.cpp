#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],c[9]={0};
	int i,j,k,p=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>a[i][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>b[i][j];	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				c[p]=c[p]+a[i][k]*b[k][j];
			}
			p++;
		}
	}
	for(i=0;i<9;i++)
	{
		cout<<c[i];
		cout<<" ";
		if((i+1)%3==0)cout<<"\n"<<endl;
	}
	return 0;
}
