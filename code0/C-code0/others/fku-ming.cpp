#include<iostream>
#include<stdlib.h>
using namespace std;

struct num{
    int b;
    int e;
    int begin;
    int end;
    int s;
};

int main()
{
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    for(int i=0;i<n;i++) {
    cin>>a[i];
    }

    int sum[n];//前缀和

    sum[0]=a[0];

    for(int i=1;i<n;i++) {
        sum[i]=sum[i-1]+a[i];
    }

    int sumk[n-k+1]; //区间和
    sumk[0]=sum[k-1];
    for(int i=1;i<n-k+1;i++) {
    sumk[i]=sum[i+k-1]-sum[i-1];
    }

    num total[n-2*k+1];

    total[0].begin=sumk[0];
    total[0].b=0;
    for(int i=1;i<n-2*k+1;i++)
    if(sumk[i] < total[i-1].begin){
        total[i].begin = sumk[i];
        total[i].b = i;
    }
    else{
        total[i].begin = total[i-1].begin;
        total[i].b = total[i-1].b;
    }
    total[n-2*k].end = sumk[n-k];
    total[n-2*k].e=n-k;
    for(int i=n-2*k-1;i>=0;i--) {
        if(sumk[i+k]<=total[i+1].end){
            total[i].end=sumk[i+k];
            total[i].e=i+k;
        }
        else{
            total[i].end=total[i+1].end;
            total[i].e=total[i+1].e;
        }
    }
    int res=1e9;
    int b0,e0;
    for(int i=0;i<n-2*k+1;i++){
    total[i].s=total[i].begin+total[i].end;
    if(total[i].s<res)
    {
        res=total[i].s;
        b0=total[i].b+1;
        e0=total[i].e+1;
    }}
    cout<<b0<<" "<<e0<<endl;
    return 0;
}
