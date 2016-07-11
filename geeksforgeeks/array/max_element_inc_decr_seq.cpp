//=== FIND THE MAXIMUM ELEMENT IN INCREASING-DECREASING..

/*******
Given an array which is first increasing and then decreasing,
Find the maximum element in that array.
Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
Output: 50

Corner case (No decreasing part)
Input: arr[] = {10, 20, 30, 40, 50}
Output: 50

Corner case (No increasing part)
Input: arr[] = {120, 100, 80, 20, 0}
Output: 120

Logic :
Use binary search.
check element at mid and mid+1 ... and decide what to do..
look into code for more understanding.

TC : O(logn)
SC : O(1)
*******/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int low=0,high=n-1;
	while((high-low)>1)	// atleast 3 elements should be there because we are referring to mid and mid+1.
						// It can also be solved using mid and mid-1...
	{
		int mid = low + (high-low)/2;
		if(A[mid]>A[mid+1])	// decresing sequence found... answer is in left side...
			high=mid;	
		else			// increasing sequence found... answer is in right side...
			low=mid;
	}
	cout << max(A[low],A[high]) << endl;	// answer can be any of two so max of both...

	return 0;
}
