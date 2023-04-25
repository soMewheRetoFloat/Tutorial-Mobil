#include<iostream>
#include<string.h>
using namespace std;

bool foldsearch(int bot,int top,bool isprime[])
{
    for(int t=bot;t<=top;t++) {
        if(isprime[t]) {
            return true;
        }
    }
    return false;
}

bool isprime[11000010]; ///筛质数力！

int main()
{
    
for(int i=0;i<=11000009;i++) {
    isprime[i]=true;
}

for(int i=2;i*i<=11000009;i++) {
    if(isprime[i]) {
        for(int j=i*i;j<=11000009;j+=i) {
            isprime[j]=false;
        }
    }
}

int T,r;
cout<<"Enter T and r\n";
cout<<"_____ _____\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
cin>>T>>r;
int xn[10010]={0};
for(int i=1;i<=T;i++) {
    cin>>xn[i];
}

for(int i=1;i<=T;i++) {
    int bot1=xn[i]-r,top1=xn[i]-1,bot2=xn[i]+1,top2=xn[i]+r;
    if(bot1<=0) {
        bot1=1;
    }
    if((foldsearch(bot1,top1,isprime))||(foldsearch(bot2,top2,isprime))) {
        cout<<"T"<<endl;
    }
    else {
        cout<<"F"<<endl;
    }
}
system("pause");
return 0;
}