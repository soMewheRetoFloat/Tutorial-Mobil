#include <bits/stdc++.h>
using namespace std;
const int MAX_VERTEX_NUM = 100; //图论常数

//以下排序

void quicksort(int arr[], int begin, int end)
{
	int i, j, t, pivot;
	if (begin > end)
		return;

	pivot = arr[begin];
	i = begin;
	j = end;
	while (i != j)
	{
		while (arr[j] >= pivot && i < j)
			j--;
		while (arr[i] <= pivot && i < j)
			i++;
		if (i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[begin] = arr[i];
	arr[i] = pivot;
	quicksort(arr, begin, i - 1);
	quicksort(arr, i + 1, end);
}

void mergesort1(int arr[], int n)
{
	int l=n/2,r=n-l;
    mergesort1(arr,l);
    mergesort1(arr+l,r);
    int *pn=new int[n];

    int i=0,j=l,k=0;
    while(i<l&&j<n) {
        if(arr[i]>arr[j]) {
            pn[k++]=arr[j++];
        }
        else {
            pn[k++]=arr[i++];
        }
    }
    for(;i<l;i++) pn[k++]=arr[i++];
    for(;j<n;j++) pn[k++]=arr[j++];
    for(int x=0;x<n;x++) {
        arr[x]=pn[x];
    }
    delete []pn;
}

void mergesort2_do(int a[], int b[], int begin, int end)
{
	if(begin >= end) {
		return;
	}
	else {
		int len = end - begin;
		int mid = (len / 2) + begin;
		mergesort2_do(a, b, begin, mid);
		mergesort2_do(a, b, mid + 1, end);
		int i = begin,j = mid + 1,jishu = begin;
		while(i <= mid && j <= end) {
			if(a[i] > a[j]) {
				b[jishu++] = a[j++];
			}
			else {
				b[jishu++] = a[i++];
			}
		}
		while(i <= mid) {
			b[jishu++] = a[i++];
		}
		while(j <= end) {
			b[jishu++] = a[j++];
		}
		for(int id = begin;id <= end; ++id) {
			a[id] = b[id];
		}
	}
}
inline void mergesort2(int *a, int length)
{
	int *reg=new int[length];
	mergesort2_do(a, reg, 0, length-1);
	delete[] reg;
}

int main () {
	return 0;
}