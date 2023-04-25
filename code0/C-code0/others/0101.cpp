#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int min(int p[],int length)
{
    int mini=1;
    for(int i=0;i<length;i++) {
        if((p[i]<mini)&&(p[i]>0)) {
            mini=p[i];
        }
    }
    return mini;
}

int kadane(int a[])
{
    int sf=0,end=0,top=0,bot=0;
    for(int i=0;i<(_msize(a)/sizeof(a[0]));i++) {
        end+=a[i];
        if(end>sf) {
            sf=end;
            top=i;
        }
        if(end<=0) {
            end=0;
            bot=i+1;
        }
    }
    return sf;
}

int main()
{
int N,nuu=0,id=0;
cin>>N;
int *a=new int[N];

for(int x=0;x<N;x++) {
    a[x]=0;
    cin>>a[x];
}

for(int i=1;i<10001;i++) {
    for(int x=0;x<N;x++) {
        if(*(a+x)==i) {
            id+=1;
            break;
        }
    }
}    
cout<<"total use "<<id<<endl;
cout<<"kadane:"<<kadane(a)<<endl;
delete[]a;
system("pause");
return 0;
}
