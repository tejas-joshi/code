/************

Find the maximum from increasing subsequence.

{1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
It may not be longest.

Here we need not bother about length of increasing subsequence.

LOGIC :
* Initialize all dp array value same as original array A.

	for each i
		dp(i) = A(i)

* Use same logic as LIS of O(n^2) but use sum for comparison.  (atleast now. I haven't found the logic for this in O(nlogn))

	for each i from 1 to n
	{
		for j from 0 to i
			if A[j]<A[i] && dp(j)+A(i) > dp(i)
				dp(i) = dp(j) + A(i)
		Check with max value with dp(i) and update if required.
	}
	
TC : O(n^2)
SC : O(n)

*************/

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n,*dp;
	cin >> n;

	A = new int[n];
	dp = new int[n];

	for(int i=0;i<n;i++)
	{
		cin >> A[i];
		dp[i] = A[i];	// Assign same value as A.
	}

	int max = INT_MIN;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			if(A[j]<A[i] && dp[i]<dp[j]+A[i])
				dp[i] = dp[j] + A[i];
		if(max<dp[i])
			max = dp[i];
	}

	cout << max << endl;
	
	return 0;
}
