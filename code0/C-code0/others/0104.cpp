#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;
int b3[56],b3f[56];
int main()
{ 
    srand((unsigned)time(NULL));
	b3[0]=rand() % 160 + 1;
    cout<<b3[0]<<" ";
    for(int i=1;i<56;i++)
    {
        b3[i]=rand() % 160 + 1;
        for(int j=0;j<i;j++)
        {
            
            for(;b3[i]==b3[j];)
            {
                b3[i]=rand() % 160 + 1;
            }
        }
        b3f[i]=b3[i];
	    cout << b3[i] << " ";
   }

cout<<endl;
system("pause");
return 0;
}