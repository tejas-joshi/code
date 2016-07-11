/***********

Find the length of longest bitonic subsequence.
Bitonic sequence is first increasing, then decreasing.

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)

LOGIC :
* Find LIS on the array and while doing it, store the length of LIS that ends on A[i].
* Same way find LDS on the array and parallely store the length of LDS that starts with A[i].
	LDS is nothing but reverse LIS i.e. LIS from n-1 to 0.

Find max. of (LIS[i] + LDS[i] - 1)
*  for i from 0 to n-1
		maxL = max(maxL,(LIS[i] + LDS[i] - 1))

o/p : maxL

TC : O(nlogn)
SC : O(n)

************/
	

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n,*LIS,*LDS;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	LIS = (int *)malloc(n*sizeof(int));
	LDS = (int *)malloc(n*sizeof(int));
	
	vector<int> B;

// LIS 
	B.push_back(0);
	LIS[0] = 1;

	for(int i=1;i<n;i++)
	{
		if(A[i]>A[B.back()])
		{
			B.push_back(i);
			LIS[i] = B.size();	// Storing the length
			continue;
		}

		int u=0,v=B.size()-1;
		while(u<v)
		{
			int c = u + (v-u)/2;
			if(A[i]>A[B[c]])
				u=c+1;
			else
				v=c;
		}

		if(A[B[u]]>A[i])
		{
			B[u] = i;
			LIS[i] = u+1;	// Storing the length
		}
		else if(A[B[u]]==A[i]) // for same element
			LIS[i] = u+1;	// Storing the length
	}

	// Clearing vector B
	B.clear();	

// LDS
	B.push_back(n-1);
	LDS[n-1] = 1;

	for(int i=n-2;i>=0;i--)
	{
		if(A[i]>A[B.back()])
		{
			B.push_back(i);
			LDS[i] = B.size();	// Storing the length
			continue;
		}

		int u=0,v=B.size()-1;
		while(u<v)
		{
			int c = u + (v-u)/2;
			if(A[i]>A[B[c]])
				u=c+1;
			else
				v=c;
		}

		if(A[B[u]]>A[i])
		{
			B[u] = i;
			LDS[i] = u+1;	// Storing the length
		}
		else if(A[B[u]]==A[i]) // for same element
			LDS[i] = u+1;	// Storing the length
	}

	// Counting the length of longest bitonic subsequence
	int maxLen = INT_MIN;
	for(int i=0;i<n;i++)
		maxLen = max(maxLen,LIS[i] + LDS[i] - 1);

	cout << maxLen << endl;	
		
	return 0;
}
