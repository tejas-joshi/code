// LONGEST INCREASING SUBSEQUENCE
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main()
{
	int *A,n;
	cin >> n;
	vector<int> B,P(n);
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

/*
 * A - Holding the original array
 *
 * B - Vector for holding the indexes of each LIS found till now.
 * 		B will have size same as length of LIS.
 * 		B[i] stores the position k of the smallest value A[k] such that there is an increasing subsequence of length (i+1) ending at A[k]. 
 *
 * P is only required if the problem is to print the LIS elements.
 * P - Vector for backtracing.. P has size same as A and filled up P[i] for every iteration
 * 	  P[i] stores the position of the predecessor of A[i] in the longest increasing subsequence ending at A[i].
 */
 
 // http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 // Refer above link. It is easy to understand.

	B.push_back(0);
	
	for(int i=1;i<n;i++)
	{
		// If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if(A[B.back()]<A[i])
		{
			P[i] = B.back();
			B.push_back(i);
			continue;
		}
	
		// Binary search to find the smallest element referenced by b which is just bigger than A[i]
        // Note : Binary search is performed on B (and not A). Size of B is always <=k and hence contributes O(log k) to complexity.
        	
		int u=0,v=B.size()-1;

		while(u<v)	// u and v must not be the same in any case else we will have wrong u.
		{
			int c = u + (v-u)/2;
			if(A[i]>A[B[c]])
				u=c+1;
			else
				v=c;
		}

		// Update b if new value is smaller then previously referenced value 
		if(A[i]<A[B[u]])
		{
			if(u>0)			// condition because B[u-1] is going to be accessed in the below statement because of backtracing
				P[i] = B[u-1];
			B[u] = i;		// overwriting uth element in B because we have found another sequence of size u+1 with the element ending with A[B[u]]
		}
	}

	// This is to set the indexes of A into B for LIS elements (only needed to print LIS elements).
	// u is for index in B vector.. v for indexing P vector
	for(int u=B.size()-1,v=B.back();u>=0;u--)
	{
		B[u] = v;	// setting the index of resultant LIS into vector B
		v = P[v];	// go to previous index of LIS.. 
	}

	// Printing LIS elements
	for(int i=0;i<B.size();i++)
		cout << A[B[i]] << " ";
	cout << endl;
	
	return 0;
}
