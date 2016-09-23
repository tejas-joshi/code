//==== Dice Throw
/*
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. 
X is the summation of values on each face when all the dice are thrown.

The function can be represented as:
Sum(m, n, X) = Finding Sum (X - 1) from (n - 1) dice plus 1 from nth dice
               + Finding Sum (X - 2) from (n - 1) dice plus 2 from nth dice
               + Finding Sum (X - 3) from (n - 1) dice plus 3 from nth dice
                  ...................................................
                  ...................................................
                  ...................................................
              + Finding Sum (X - m) from (n - 1) dice plus m from nth dice

TC : O(mnX)
SC : O(nX)

*/

#include<iostream>
#include<string.h>
using namespace std;

int findWays(int nDices,int nSides, int X)
{
	int dp[nDices+1][X+1];	
	memset(dp,0,sizeof(dp));

	// Table entries for only one dice
	for(int j=1;j<=X && j<=nSides;j++)
		dp[1][j] = 1;
	
	// Fill rest of the entries in table using recursive relation
    // i: number of dice, j: sum
	for(int i=1;i<=nDices;i++)
		for(int j=1;j<=X;j++)
			for(int k=1;k<=j && k<=nSides;k++)
				dp[i][j] = dp[i][j] + dp[i-1][j-k];	
	return dp[nDices][X];
}

int main()
{
	int nDices,nSides,X;
	cin >> nDices >> nSides >> X;
	cout << findWays(nDices,nSides,X) << endl;	
	return 0;
}
