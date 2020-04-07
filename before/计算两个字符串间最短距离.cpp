#include <iostream>
using namespace std;
int main ()
{
	char a[10],b[10];
	int i,j,min=25;
	cin>>a>>b;
	for(i=0;a[i];i++)
	{
		if(a[i]>64&&a[i]<91)a[i]=a[i]+32;
	}
		for(i=0;b[i];i++)
	{
		if(b[i]>64&&b[i]<91)b[i]=b[i]+32;
	}
	for(i=0;a[i];i++)
	{
		for(j=0;b[j];j++)
		{
			if((a[i]-b[j])>=0&&(a[i]-b[j])<min)min=a[i]-b[j];
			if((b[j]-a[i])>=0&&(b[j]-a[i])<min)min=b[j]-a[i];
		}
	}
	cout<<min;
	return 0;
}
