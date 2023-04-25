#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;

int car[10010]={0},a[10010]={0},b[10010]={0},g[10010]={0},h[10010]={0};
for(int i=1;i<=n;i++) {
    cin>>a[i]>>b[i]>>g[i]>>h[i];
}

int xa,ya,finish;
cin>>xa>>ya;
for(int i=n;i>=1;i--) {
    int xs=a[i],xe=a[i]+g[i],ys=b[i],ye=b[i]+h[i];
    if((xa>=xs)&&(xa<=xe)&&(ya>=ys)&&(ya<=ye)) {
        cout<<i<<endl;
        break;
    }
    if(i==1) {
        int xisn=-1;
        cout<<xisn<<endl;
    }
}
system("pause");
return 0;
}