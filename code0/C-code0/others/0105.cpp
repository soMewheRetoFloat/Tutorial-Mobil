#include<iostream>
using namespace std;
int arr[41][41]={0};
int main()
{
    int n;
    cin>>n;
    int amount=1,row,column;
    while(amount<=(n*n))
    {
        if(amount==1)
        arr[row=1][column=(n+1)/2]=amount;
        else if(row==1) //k-1在第一行
        {
            if(column==n) //第一行最后一列
            {
                arr[++row][column]=amount;
            }
            else //不是最后一列
            {
                arr[row=n][++column]=amount;
            }
        }
        else if(column==n) //在最后一列
        {
            if(row!=1) //最后一列但不是第一行
            {
                arr[--row][column=1]=amount;
            }
        }
        else //啥也不是
        {
            if(arr[(row-1)][(column+1)]==0)
            {
            arr[--row][++column]=amount;
            }
            else
            {
                arr[++row][column]=amount;
            }
        }
        amount++;
    }
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
system("pause");
return 0;
}