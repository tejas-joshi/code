//===== FIND THE PEAK ELEMENT

/***

Given an array of integers. Find a peak element in it. 
* An array element is peak if it is NOT smaller than its neighbors. 
* For corner elements, we need to consider only one neighbor. 
* For example, for input array {5, 10, 20, 15}, 20 is the only peak element. 
* For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. 
* Note that we need to return any one peak element.

Following corner cases give better idea about the problem.
1) If input array is sorted in strictly increasing order, the last element is always a peak element. For example, 50 is peak element in {10, 20, 30, 40, 50}.
2) If input array is sorted in strictly decreasing order, the first element is always a peak element. 100 is the peak element in {100, 80, 60, 50, 20}.
3) If all elements of input array are same, every element is a peak element.

Logic : 

We can use Divide and Conquer to find a peak in O(Logn) time. The idea is Binary Search based, we compare middle element with its neighbors. 
* If middle element is greater than both of its neighbors, then we return it. 
* If the middle element is smaller than the its left neighbor, then there is always a peak in left half (Why? take few examples). 
* If the middle element is smaller than the its right neighbor, then there is always a peak in right half (due to same reason as left half).

TC : O(logn)
SC : O(1)

****/

#include<iostream>
using namespace std;

int findPeakElement(int n,int *A)
{
	int mid,low=0,high=n-1;
	
	while(1)
	{
		mid = low + (high-low)/2;
		
		// YOU WILL THINK FOR THIS CONDITIONS FOR SOME TIME THEN GET THE LOGIC
		// Compare middle element with its neighbours (if neighbours exist)
		if(	(mid==0 || A[mid-1]<=A[mid]) && (mid==n-1 || A[mid]>=A[mid+1]) )	
			return mid;
		// If middle element is not peak and its left neighbor is greater than it
		// then left half must have a peak element
		else if(mid>0 && A[mid-1]>A[mid])
			high = mid-1;
		// If middle element is not peak and its right neighbor is greater than it
		// then right half must have a peak element
		else
			low = mid+1;
	}	
}

int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	cout << findPeakElement(n,A) << endl;
	
	return 0;	
}	
