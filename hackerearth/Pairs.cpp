// Given N numbers , [N<=10^5] we need to count the total pairs of numbers that have a difference of K. [K>0 and K<1e9] 

// TC : O(nlogn)

#include<iostream>
#include<stdlib.h>
using namespace std;
typedef long long int LL;

int compare(const void *a,const void *b)
{
	return (* (LL *)a) - (* (LL *)b);
}

// Counts the occurences of the number left of ith index in the array A
int countElementLeft(LL *A,LL i,LL n,LL d)
{
	int l=0,h=i-1,mid;
	while(l<=h)
	{
		mid = l + (h-l)/2;
		if(d==A[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return i-l;
}

// Counts the occurences of the number right of ith index in the array A
int countElementRight(LL *A,LL i,LL n,LL d)
{
	int l=i+1,h=n-1,mid;
	while(l<=h)
	{
		mid = l + (h-l)/2;
		if(A[mid]==d)
			l=mid+1;
		else
			h=mid-1;
	}
	return h-i;
}

int main()
{
	LL N,*A,K,d;
	int count=0;
	cin >> N;
	cin >> K;
	A = new LL[N];

	for(int i=0;i<N;i++)
		cin >> A[i];

	qsort(A,N,sizeof(LL),compare);

	int l,h,mid;
	for(int i=0;i<N;i++)
	{
		l=i+1;
		h=N-1;
		d = A[i]+K;
		
		while(l<=h)
		{
			mid = l + (h-l)/2;
			if(A[mid]==d)	
			{
				// here if it is mentioned that all the numbers are distinct then we dont need to call countleft and countright function
				// if elements can be repeated then we have to call the function to count all the occurences of the element..
				count = count + countElementLeft(A,mid,N,d) + countElementRight(A,mid,N,d) + 1;
				break;
			}
			else if(A[mid]<d)
				l=mid+1;
			else
				h=mid-1;
		}
	}
	cout << count << endl;
	return 0;
}
