/**************

FIND MINIMUM COST TO REACH (0,0) TO (m,n).
YOU CAN GO DOWN,RIGHT AND DIAGONAL WAY ONLY.

Logic :

BASE CASES:
* For first row, you can go only right side.
	dp[0][i] = dp[0][i-1] + A[0][i];
* For first column, you can go only down side.
	dp[i][1] = dp[i][i-1] + A[1][i];

else  // take minimum of all the 3 sides by which the cost will be minimum.
	dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + A[i][j];

TC : O(mn)
SC : O(n)  // As we need only two rows for dp table.

**************/

#include<iostream>
#include<stdlib.h>
using namespace std;

int min(int a,int b,int c)
{	return (a<b)?((a<c)?a:c):((b<c)?b:c);	}

int main()
{
	int **A,m,n,**dp;

	cin >> m >> n;
	A = (int **)malloc(m*sizeof(int *));
	for(int i=0;i<m;i++)
		A[i] = (int *)malloc(n*sizeof(int));

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];

	dp = (int **)malloc(2*sizeof(int *));
	dp[0] = (int *)malloc(n*sizeof(int ));
	dp[1] = (int *)malloc(n*sizeof(int ));

	dp[0][0] = A[0][0];
	
	// First row - you can go only right side
	for(int i=1;i<n;i++)
		dp[0][i] = dp[0][i-1] + A[0][i];	

	int ans;
	for(int i=1;i<m;i++)
	{
		// For first column, we can go only down side
		dp[i%2][0] = dp[(i-1)%2][0] + A[i][0];
		// else
		for(int j=1;j<n;j++)
			ans = dp[i%2][j] = min(dp[(i-1)%2][j],dp[i%2][j-1],dp[(i-1)%2][j-1]) + A[i][j];
	}
	cout << ans << endl;

	return 0;
}
