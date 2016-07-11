/*************

0/1 KNAPSACK PROBLEM

n items:
* 	Each has weight and profit
Knapsack of W capacity
Make maximum profit.

dp[i][j] indicates maximum profit gained by taking i items into consideration and j weight.
* Here i items taken into consideration doesnt mean all are added. Some may not be added to make profit high.

	for each item i	from 1 to n
		for all weights j from 1 to W
			if(j<w[i-1])   // This item cannot be added because of more weight of item than capacity.
				dp[i][j] = dp[i-1][j] //	So profit will be same as previous.
			else     // This item can be added 
				dp[i][j] = max ( val[i-1] + dp[i-1][j-w[i-1]] , dp[i-1][j] )
				* first one for adding ith item. So adding profit and subtracting w[i-1] from j
				* second one for not adding ith item so profit will be same as dp[i-1][j]

TC : O(nW)
SC : O(nW)

************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *w,*val,**dp,n,W;
	cin >> n;
	w = (int *)malloc(n*sizeof(int));
	val = (int *)malloc(n*sizeof(int));

	for(int i=0;i<n;i++)
		cin >> w[i] >> val[i];

	cin >> W;

	dp=(int **)calloc((n+1),sizeof(int *));
	for(int i=0;i<=n;i++)
		dp[i] = (int *)calloc(W+1,sizeof(int));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=W;j++)
		{
			if(w[i-1]>j)	// Item cannot be added because of higher weight of item than j
				dp[i][j] = dp[i-1][j];
			else           
				dp[i][j] = max(val[i-1]+dp[i-1][j-w[i-1]] , dp[i-1][j]);
				// First one for adding item so profit is added.
				// second one for not adding item.
				// Take max of both will give me optimal answer.
		}

/*  PRINTING dp TABLE
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
*/

	cout << dp[n][W] << endl;
		
	return 0;
}
