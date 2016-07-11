//========= FIND FIXED POINT IN SORTED ARRAY

/*****
Given a sorted array, find the fixed point. 	
Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative. 

Input: arr[] = {-10, -5, 0, 3, 7}
Output: 3  // arr[3] == 3 
Input: arr[] = {0, 2, 5, 8, 17}
Output: 0  // arr[0] == 0 

Logic :
Use binary search.
Check A[mid] and mid every time. and take decision accordingly..
If not found then output -1.

TC : O(logn)
SC : O(1)
******/

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
	bool found=false;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(A[mid]==mid)	// found
		{
			found=true;
			cout << mid << endl;
			break;
		}
		else if(A[mid]>mid)	// answer is in left side.
			high=mid-1;
		else			// answer is in right side.
			low = mid+1;
	}

	if(!found)
		cout << -1 << endl;

	return 0;
}
