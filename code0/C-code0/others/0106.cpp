#include<iostream>
using namespace std;
int zdz(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
/*
bool IsLeap(int x)
{
    if(((x%4==0)&&(x%100!=0))||(x%400==0))
    return true;
    else
    return false;
}
int year(int y)
{
    int n=0;
    for(int x=2023;x<y;x++)
    {
        if(IsLeap(x))
        {
            n+=366;
        }
        else
        {
            n+=365;
        }
    }
    return n;
}
void month(int y)
{
    int n=0;
    for(int x=1;x<=12;x++)
    {
        if((x==1)&&(x==3)&&(x==5)&&(x==7)&&(x==8)&&(x==10)&&(x==12))
        {
            n=31;
        }
        else if(x==2)
        {
            if(IsLeap(y))
            {
                n=29;
            }
            else
            {
                n=28;
            }
        }
        else
        {
            n=30;
        }
    }
}
void space(int m)
{
    while(m>0)
    {
        cout<<"     ";
        m--;
    }
}
void CalenderX()
{
        int y,m,d;
    cout<<"请输入年\n"<<"please press in yyyy"<<endl;
    cin>>y;
    cout<<"       日   一   二   三   四   五   六 "<<endl;
    int nx=year(y);
    int dx=nx%7;
    int n=0,tabform=0;
    for(int x=1;x<=12;x++)
    {
        if((x==1)||(x==3)||(x==5)||(x==7)||(x==8)||(x==10)||(x==12))
        {
            n=31;
        }
        else if(x==2)
        {
            if(IsLeap(y))
            {
                n=29;
            }
            else
            {
                n=28;
            }
        }
        else
        {
            n=30;
        }
        if(x==1)
        {
            cout<<"01     ";
            space(dx);
            tabform=7-dx;
        }
        for(int dayexa=1;dayexa<=n;dayexa++)
        {
            if(dayexa<10)
            {
                cout<<" ";
            }
            cout<<dayexa<<"   ";
            tabform--;
            if(tabform==0)
            {
                cout<<endl;
                if((n-dayexa)/7==0)
                {
                    if(x<10)
                    {
                        cout<<"0";
                    }
                    cout<<x<<"     ";
                }
                else
                {
                    cout<<"       ";
                }
                tabform=7;
            }
        }
    }
    cout<<endl;
}

void portable()
{
    int n,amount=1,row,column;
    cin>>n;
    int arr[41][41];
    for(int x=0;x<=40;x++)
    {
        for(int y=0;y<=40;y++)
        {
            arr[x][y]=0;
        }
    }
    while(amount<=n*n)
    {
        if(amount==1)
        arr[row=1][column=(n+1)/2]=amount++;
        else if(row==1) //k-1在第一行
        {
            if(column==n) //第一行最后一列
            {
                arr[++row][column]=amount++;
            }
            else //不是最后一列
            {
                arr[row=n][++column]=amount++;
            }
        }
        else if(column==n) //在最后一列
        {
            if(row!=1) //最后一列但不是第一行
            {
                arr[--row][column=1]=amount++;
            }
            else //啥也不是
            {
                if(arr[(row-1)][(column+1)]==0)
                {
                    arr[--row][++column]=amount++;
                }
                else
                {
                    arr[++row][column]=amount++;
                }
            }
        }
    }
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}
*/
int p1[100];
int p2[100];
int result[100];
int Length(char num[])
{
    int tmp=0,i=0;
    while(num[i]!='\0')
    {
        tmp++;
        i++;
    }
    return tmp;
}
void transmiss(char num[],int numi[100])
{
    
    int i=0;
    int t=Length(num);
    while(num[i]!='\0')
    {
        numi[100-t+i]=int(num[i])-48;
        i++;
    }
}
int main()
{
    char p1c[101]={'\0'};
    char p2c[101]={'\0'};
    cin>>p1c>>p2c;
    transmiss(p1c,p1);
    transmiss(p2c,p2);
    int last=99,tx=0;
    while(tx<=zdz(Length(p1c),Length(p2c)))
    {
        result[last]=p1[last]+p2[last]+result[last];
        while(result[last]>=10)
        {
            result[last]-=10;
            result[(last-1)]+=1;
        }
        last--;
        tx++;
    }
    for(int re=last+2;re<=99;re++)
    {
        cout<<result[re];
    }
    cout<<endl;
    system("pause");
    return 0;
}