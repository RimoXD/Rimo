#include<iostream>
#include  <cmath> 
using namespace std; 

int  isPrime(long  num) 
{ 
	int i;
	for(i=2;i<num;i++){
		if(num%i==0)return 0;
	}
	return 1;
} 

//计算质因素分解， 
void  factorization(long  n,long factor[100],int &count) 
{ 
	int i;
	if(isPrime(n)){
		cout<<n;
	}
	while(!isPrime(n)){
		for(i=2;i<n;i++){
			if(n%i==0){
				factor[count]=i;
				n/=i;
				count++;
				break;}
		}
		if(isPrime(n)){
			factor[count]=n;
			count++;
		}
	}
} 

int  main() 
{ 
        long  n; 
        long  factor[100]; 
        int  numofFactor  =  0; 
        cin  >>  n; 
        factorization(n,factor,numofFactor); 
        for  (int i=0;i<numofFactor;i++) 
        { 
            cout<<factor[i]<<"  "; 
        } 
        cout<<endl;
        return 0; 
}
