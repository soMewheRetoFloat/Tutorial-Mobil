#include<iostream>
#include<cmath>
#include<algorithm> 
#include<time.h>
using namespace std;
int b3[56], b3f[56];
void x()
{
	cout<<"    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16"<<endl;
}
int main()
{ 
    int y1,y2,sum1=0,sum2=0;
	srand((unsigned)time(NULL));
	b3[0] = rand() % 160 + 1;
	for (int i = 1; i < 56; i++)
		{
			b3[i] = rand() % 160 + 1;
			for (int j = 0; j < i; j++)
			{

				for (; b3[i] == b3[j];)
				{
					b3[i] = rand() % 160 + 1;
				}
			}
			b3f[i] = b3[i];
		}

    cout<<"规则：这是一个10乘16的地雷阵，约有35%的雷，所有隐藏的格子均显示为@,每次可以选择一个格子并显示其周围的雷数，你可以输入1标记隐藏格并使之显示为#，输入0结束标记操作，注意所有选择操作均须输入坐标并用空格隔开，让我们开始吧"<<endl;
	int a1[10][16];
	char a2[10][16];
	for(int c1=1;c1<=10;c1++)
	for(int c2=1;c2<=16;c2++)
	{
	a2[c1-1][c2-1]='@';
	a1[c1-1][c2-1]=0;
    }
	for(int c3=1;c3<=56;c3++)
	{
		int d1=b3[c3-1]/10,d2=b3[c3-1]-d1*10;
		a1[d2][d1]=1;
	}
	for(int g1=1;g1<=10;g1++)
	for(int g2=1;g2<=16;g2++)
	if(a1[g1-1][g2-1]==1)
	sum1++;
	cout<<"共有35个雷"<<endl; 
	for(;;)
	{
		x();
		for(int c4=1;c4<=10;c4++)
		{
			if(c4<10)
			cout<<c4<<" ";
			else
			cout<<10;
			for(int c5=1;c5<=16;c5++)
			if(a2[c4-1][c5-1]=='@'||a2[c4-1][c5-1]=='#')
			cout<<"  "<<a2[c4-1][c5-1];
			else
			cout<<"  "<<(int)a2[c4-1][c5-1];
			cout<<endl;
		}
		cout<<"请排除一颗雷"<<endl;
		cin>>y1>>y2;
		int y3=a1[y1-1][y2-1];
		if(y3==1)
		{
			cout<<"踩雷了你个**，游戏结束"<<endl;
			break; 
		}
		else
		{
			sum2++;
			if(sum2==sum1)
			{
				cout<<"恭喜小机灵鬼，扫雷成功，游戏结束"<<endl;
				break;
			}
			int sum=0; 
			if(a1[y1-2][y2-2]==1)
			sum++;
			if(a1[y1-2][y2-1]==1)
			sum++;
			if(a1[y1-2][y2]==1)
			sum++;
			if(a1[y1-1][y2-2]==1)
			sum++;
			if(a1[y1-1][y2]==1)
			sum++;
			if(a1[y1][y2-2]==1)
			sum++;
			if(a1[y1][y2-1]==1)
			sum++;
			if(a1[y1][y2]==1)
			sum++;
			char e=(char)sum;
			a2[y1-1][y2-1]=e;
		x();
		for(int c4=1;c4<=10;c4++)
		{
			if(c4<10)
			cout<<c4<<" ";
			else
			cout<<10;
			for(int c5=1;c5<=16;c5++)
			if(a2[c4-1][c5-1]=='@'||a2[c4-1][c5-1]=='#')
			cout<<"  "<<a2[c4-1][c5-1];
			else
			cout<<"  "<<(int)a2[c4-1][c5-1];
			cout<<endl;
		}
			for(;;){
			cout<<"请问你要标记吗"<<endl;
			bool f;
			cin>>f;
			if(f)
			{
				cout<<"请开始标记"<<endl;
				cin>>y1>>y2;
				a2[y1-1][y2-1]='#';
			}
			else
			break;
		    } 
		}
	}
	return 0;
}
