#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void maxSubArraySumIdx(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far
         << endl;
    cout << "Starting index: element" << start << endl
         << "Ending index: element " << end << endl;
}
 
#define ROW 4
#define COL 4
int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;
 
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if (*finish != -1)
        return maxSum;
    maxSum = arr[0];
    *start = *finish = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSubMatSum(int M[][COL])
{
    int maxSum = INT_MIN,
                 finalLeft,
                 finalRight,
                 finalTop,
                 finalBottom;
 
    int left, right, i;
    int temp[ROW], sum, start, finish;
 
    
    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < COL; ++right) {
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
            
            sum = kadane(temp, &start, &finish, ROW);
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
 
    
    cout << "(Top, Left) ("
         << finalTop << ", "
         << finalLeft
         << ")" << endl;
    cout << "(Bottom, Right) ("
         << finalBottom << ", "
         << finalRight << ")" << endl;
    cout << "Max sum is: " << maxSum << endl;
}

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"array comes as [";
    for(int x=0;x<n;x++)
    {
        if(x==n-1) {
            cout<<a[x]<<"]"<<endl;
        }
        else {
            cout<<a[x]<<" ";
        }
    }
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    maxSubArraySumIdx(a, n);
    
    int M[ROW][COL];
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            cin>>M[i][j];
        }    
    }
    findMaxSubMatSum(M);
    
    system("pause");
    return 0;
}