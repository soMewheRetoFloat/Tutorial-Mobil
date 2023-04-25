#include <cstdio>
#include<iostream>
#include <cstring>
 
using namespace std;
typedef long long ll;
 
ll sum, mark;
 
void test(ll row, ll ld, ll rd)
//row表示已经有皇后的行
//ld、rd分别表示已经有皇后的左右斜列，每一位表示该列中可以摆放皇后的位置，1表示可以摆放，0表示不可以摆放。row在每查找下一列时不用改动，ld、rd需要分别左移和右移一位。
{
    if(row != mark) //当所有行都有皇后时说明摆放完毕
    {
        ll pos = mark & ~(row | ld | rd); //pos的每一位表示该列中可以摆放皇后的位置，1表示可以摆放，0表示不可以摆放
        while(pos) //如果pos中还有可以摆放的位置
        {
            ll p = pos & -pos; //p为pos中最末一个可以摆放的位置
            pos -= p; //将p从可摆放位置去掉
            test(row + p, (ld + p) << 1, (rd + p) >> 1); //对下一列进行判断
        }
    }
    else
        sum++;
}
 
int main()
{
    int n;
    cin>>n;
    sum = 0, mark = 1;
    mark = (mark << n) - 1; //有多少个皇后，就有多少bit被置1。（从低位到高位）
    test(0, 0, 0);
    cout<<sum<<endl;
    system("pause");
    return 0;
}