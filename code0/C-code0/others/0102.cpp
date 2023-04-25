#include<stdio.h>
#include<iostream>
using namespace std;

int minimiza(int p[],int length)
{
    int mini=1;
    for(int i=0;i<length;i++) {
        if((p[i]<mini)&&(p[i]>0)) {
            mini=(p[i]);
        }
    }
    return mini;
}

int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int id=0;
	int judge=minimiza(a,n);
	while(judge!=0) {
		for(int i=0;i<n;i++) {
			a[i]-=judge;
			b[i]=a[i];
		}
		id+=1;
		judge=minimiza(b,n);
	}
	cout<<id<<endl;
	system("pause");
	return 0;
}