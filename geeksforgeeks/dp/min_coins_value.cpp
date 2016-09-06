//====  Find minimum number of coins that make a given value
/*
Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents


Same logic as K sum possible/number of ways sum possible/...

TC : O(nV)
SC : O(V)

*/

#include<iostream>
#include<limits.h>
using namespace std;

int findMinCoins(int *coins,int n,int V)
{
	int *dp = new int[V+1];
	
	for(int i=0;i<=V;i++)
		dp[i]=INT_MAX;
	dp[0]=0;	
	
	for(int i=0;i<n;i++)
	{
		for(int j=coins[i];j<=V;j++)
			if(dp[j-coins[i]]!=INT_MAX && dp[j] > dp[j-coins[i]]+1)
				dp[j]=dp[j-coins[i]]+1;
	}
		
	return dp[V];	
}

int main()
{
	int n,*coins,V;
	cin >> n;
	coins = new int[n];

	for(int i=0;i<n;i++)
		cin >> coins[i];
	cin >> V;
	
	cout << findMinCoins(coins,n,V) << endl;
	
	return 0;
}
