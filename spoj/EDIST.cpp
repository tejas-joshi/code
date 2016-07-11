/***************
 * EDIT DISTANCE

Find the minimum cost required to convert string s1 to string s2.
l1 = length of s1, l2 = length of s2

If the characters are matching then
	it wont have any cost so it will be same as dp[i-1][j-1];
	dp[i][j] = dp[i-1][j-1];
else
	You have 3 operations. Check for minimum of all of them by taking values.
	dp[i][j] = min(dp[i-1][j-1]+cost_rep,dp[i-1][j] + cost_del,dp[i][j-1] + cost_ins)

This will require dp[l1][l2]	
You can minimize the space by taking just two rows because (no. of columns would be min. of both).
only need dp[i-1][j-1],dp[i-1][j],dp[i][j-1] elements for dp[i][j].

Here all the costs are taken 1. We cam change the values of them if it is mentioned in the problem.

TC : O(l1*l2)
SC : O(min(l1,l2))

********************/

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int min(int a,int b,int c)
{	return (a<b)?((a<c)?a:c):((b<c)?b:c);	}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		int cost_rep = 1,cost_ins = 1,cost_del = 1;
	
		int l1 = s1.length();
		int l2 = s2.length();
	
		int **dp;
		dp = (int **)malloc(2*sizeof(int *));
		for(int i=0;i<=1;i++)
			dp[i] = (int *)malloc((l2+1)*sizeof(int));
	
		dp[0][0] = 0;
	
		// Base case where l1=0, so you have to insert all the characters of s2.
		for(int i=1;i<=l2;i++)
			dp[0][i] = dp[0][i-1] + cost_ins;
	
	/*
	 *  PRINTING dp TABLE
		for(int i=0;i<=l1;i++)
		{
			for(int j=0;j<=l2;j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
	*/		
	
		int ans=0;
		for(int i=1;i<=l1;i++)
		{
			for(int j=0;j<=l2;j++)
			{
				// Base case where l2=0, so you have to delete the characters of s1.
				if(j==0)
					dp[i%2][0] = dp[(i-1)%2][0] + cost_del;
				else		
					// Character matched. so no cost
					if(s1[i-1]==s2[j-1])
						dp[i%2][j] = dp[(i-1)%2][j-1];
					// Character mismatched so check for operation that takes minimum cost overall.
					else
						dp[i%2][j] = min(cost_rep + dp[(i-1)%2][j-1],cost_ins + dp[i%2][j-1],cost_del + dp[(i-1)%2][j]);
				ans = dp[i%2][j];
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
