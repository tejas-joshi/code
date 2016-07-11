//====== EGG DROPPING PUZZLE

/*
Given n eggs and k floors, What is the least number of egg-droppings needed to answer the floor from which egg will break after drop in worst case?

1) If the egg breaks after dropping from xth floor, 
   then we only need to check for floors lower than x with remaining eggs; 
   so the problem reduces to x-1 floors and n-1 eggs
2) If the egg doesn’t break after dropping from the xth floor, 
   then we only need to check for floors higher than x; 
   so the problem reduces to k-x floors and n eggs.

n=1   If there is only one egg then we have to check for all the floors starting from 1.	=> k
k=0   If there is no floor then no trial is needed.											=> 0
k=1   If there is only 1 floor then only 1 trial is needed.									=> 1

  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                      floor in worst 
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
		x in {1, 2, ..., k}}

For better understanding, refer the code.

TC : O(n * k^2)
SC : O(nk)

*/
#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;

	/* A 2D table where entery eggFloor[i][j] will represent minimum
          number of trials needed for i eggs and j floors. */
	int **dp;
	dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[k+1];

	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;	// no floors so 0 trials
		dp[i][1]=1;	// 1 floor so only 1 trial
	}

	for(int i=0;i<=k;i++)
		dp[1][i] = i;	// only 1 egg so only 1 way we can check... all the floors.. so i trials..

	for(int i=2;i<=n;i++)
		for(int j=2;j<=k;j++)
		{
			dp[i][j] = INT_MAX;
			for(int x=1;x<=j;x++)
				dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1],dp[i][j-x]));
		}
	cout << dp[n][k] << endl;

	return 0;
}
