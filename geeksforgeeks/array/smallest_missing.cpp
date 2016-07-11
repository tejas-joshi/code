//=== FIND THE MINIMUM MISSING NUMBER FROM SORTED ARRAY

/****
Given a sorted array, find the minimum missing number from it.
Array starting from 0. 
Input: {0, 1, 2, 6, 9}, n = 5
Output: 3

Input: {4, 5, 10, 11}, n = 4
Output: 0

Input: {0, 1, 2, 3}, n = 4
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9
Output: 8

Logic : 
Use binary search to check the element and index.
If element and index don't match then answer is not left side otherwise answer is on right side.
Look into code for more clarity..

TC : O(logn)
SC : O(1)
*****/

// YOUR PROGRAM IS NOT HANDLING THE CASE WHERE THERE ARE TWO ELEMENTS... E.G. 0 1

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
	while((high-low)>1)
	{
		if(A[low]!=low) // corner case : first number is missing
		{
			low--;
			break;
		}
		else if(A[high]==high)	// all the numbers exist.. missing is next to high...
		{
			low = high;
			break;
		}
	
		int mid = low + (high-low)/2;	
		if(A[mid]==mid)		// check right side
			low=mid;
		else			// check left side.
			high=mid;
	}
	
	cout << low+1 << endl;

	return 0;
}
