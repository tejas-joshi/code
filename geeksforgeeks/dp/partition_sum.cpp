/***********

Find whether array can be divided into two paritition that has same sum.
{3,5,6,7,1} => true  ( {5,6} and {3,7,1} )

LOGIC :
* If the sum is odd then it's surely not possible to partition.
* Use same logic as 0-1 KNAPSACK PROBLEM but to find whether some items can fill up the knapsack exactly.

Take boolean array for dp table	
	dp[i][j] = dp[i-1][j];	// If we don't add current element then bool value would be same.
	if(j>=A[i-1])
		dp[i][j] = dp[i][j] || dp[i-1][j-A[i-1]];

	
TC : O(n*(sum/2))
SC : O(n*(sum/2))

*********************

 SC CAN BE REDUCED TO O(sum/2) IF WE USE THE SAME TECHNIQUE AS TO FIND THE SUBSET WITH SUM S
 * HERE THE PROBLEM IS SAME BUT WE HAVE TO FIND THE SUM WITH VALUE (TOTAL-SUM)/2

TC : O(n*(sum/2))
SC : O(sum/2)
*********************

***********/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *A,n,sum=0;
	bool **dp;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		cin >> A[i];
		sum = sum + A[i];
	}

	if(sum%2)
	{
		cout << "false" << endl;
		return 0;
	}	
	sum = sum/2;

	dp = (bool **)calloc((n+1),sizeof(bool *));
	for(int i=0;i<=n;i++)
		dp[i] = (bool *)calloc((sum+1),sizeof(bool));

	// If there are 0 items then it's not possible to make sum so make first row as false(0).
	// Sum 0 is always possible to make first column to true(1) excluding dp[0][0].
	for(int i=1;i<=n;i++)
		dp[i][0] = 1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j>=A[i-1])
				dp[i][j] = dp[i][j] || dp[i-1][j-A[i-1]];
		}

	if(dp[n][sum])
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
