/*****************

An element in a sorted array can be found in O(log n) time via binary search.
But suppose I rotate the sorted array at some pivot unknown to you beforehand.
So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
Devise a way to find an element in the rotated array in O(log n) time.

LOGIC : Find the pivot point, divide the array in two sub-arrays and call binary search.

******************/
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *A,n,x;
	cin >> n >> x;

	A = (int *)malloc(n*sizeof(int));

	for(int i=0;i<n;i++)
		cin >> A[i];

	int low=0,high=n-1,mid;
		
	mid = low+(high-low)/2;
	while(A[mid]<=A[mid+1])
	{
		// for case where all elements are sorted.
		if(mid==n-2)	
		{
			mid=n-1;
			break;
		}

		if(A[mid]>A[low])
			low=mid+1;
		else
			high=mid-1;
		mid = low+(high-low)/2;
	}
 
	low=0;
	high=n-1;

	if(A[mid]>=x && A[low]<=x)	// element in first part
		high=mid;
	else        // element in second part
		low=mid+1;

	// binary search
	while(high>=low)
	{
		mid = low + (high-low)/2;
		if(A[mid]==x)
		{
			cout << mid << endl;
			break;
		}
		else if(A[mid]>x)
			high = mid-1;
		else
			low = mid+1;
	}		
	
	return 0;
}
