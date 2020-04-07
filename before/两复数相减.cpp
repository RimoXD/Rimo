#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a[4];
	int i;
	for(i=0;i<4;i++)cin>>a[i];
	void jian(double a[4]);
	jian(a);
//	cout<<a[0]-a[0]<<" "<<a[3]-a[1];
	return 0;
}

void jian(double a[4])
{
	cout<<fixed<<setprecision(2)<<(a[0]-a[2])<<" "<<fixed<<setprecision(2)<<(a[1]-a[3]);
}
