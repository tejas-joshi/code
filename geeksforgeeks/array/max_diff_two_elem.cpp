//======= MAXIMUM DIFFERENCE BETWEEN TWO ELEMENTS.

/**

Given an array arr[] of integers, find out the difference between any two elements 
such that larger element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). 
If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)

Logic :

we take the difference with the minimum element found so far. So we need to keep track of 2 things:
1) Maximum difference found so far (max_diff).
2) Minimum number visited so far (min_element).

TC : O(n)
SC : O(1)

**/

#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int minVal=A[0],diff=0;
	for(int i=1;i<n;i++)
	{
		if(A[i]-minVal>diff)
			diff = A[i] - minVal;
		if(A[i]<minVal)
			minVal = A[i];
	}

	cout << diff << endl;

	return 0;
}
