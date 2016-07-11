//====	Optimal Binary Search Tree

/*
Given a SORTED array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts,
where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such
that the total cost of all the searches is as small as possible.

Example 1
Input:  keys[] = {10, 12}, freq[] = {34, 50}
There can be following two possible BSTs 
        10                       12
          \                     / 
           12                 10
          I                     II
Frequency of searches of 10 and 12 are 34 and 50 respectively.
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118

The optimal cost for freq[i..j] can be recursively calculated using following formula.
optCost(i, j) = \sum\limits_{k=i}^j freq[k] + \min\limits_{r=i}^j [ optCost(i, r-1) + optCost(r+1, j) ]

We need to calculate optCost(0, n-1) to find the result.

The idea of above formula is simple, we one by one try all nodes as root (r varies from i to j in second term).
When we make rth node as root, we recursively calculate optimal cost from i to r-1 and r+1 to j.
We add sum of frequencies from i to j (see first term in the above formula),
this is added because every search will go through root and one comparison will be done for every search.

TC : O(n^3)
SC : O(n^2)

*/

#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
	int n,*A,*F,*leftSum;
	cin >> n;

	A = new int[n];
	F = new int[n];			
	leftSum = new int[n];	// leftSum is to store the sum of freq. of 0 to ith element of F including ith element...
	
	for(int i=0;i<n;i++)
	{
		cin >> A[i] >> F[i];
		leftSum[i] = ((i==0)?(F[i]):(leftSum[i-1]+F[i]));
	}

	int cost[n][n],j;
	/* cost[i][j] = Optimal cost of binary search tree that can be
       formed from A[i] to A[j].
       cost[0][n-1] will store the resultant cost */

	// For a single key, cost is equal to frequency of the key
	for(int i=0;i<n;i++)
		cost[i][i] = F[i];

	// Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L;i++)
		{
			j=i+L-1;
			cost[i][j]=INT_MAX;

			// Try making all keys in interval A[i..j] as root
			for(int r=i;r<=j;r++)
			{
				// c = cost when A[r] becomes root of this subtree
				// last term is to get the addition of freq. from i to j elements including both.
				int c = ((r>i)?cost[i][r-1]:0) + ((r<j)?cost[r+1][j]:0) + (leftSum[j]-leftSum[i]+F[i]);
				if(c<cost[i][j])
					cost[i][j] = c;
			}
		}
	}

	cout << cost[0][n-1] << endl;
	return 0;
}
