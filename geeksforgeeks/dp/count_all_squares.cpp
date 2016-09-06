/*****************

Given a binary matrix, find out the all the square sub-matrix with all 1s.

For example, consider the below binary matrix.
 
   0  1  1  0  1 
   1  1  1  1  0 
   0  1  1  1  0
   1  1  1  1  0
   1  1  1  1  1
   0  0  0  0  0

   19  1x1
   8   2x2
   2   3x3
   --
   29
   
********************/

#include<iostream>
#include<stdlib.h>
using namespace std;

int min(int a,int b,int c)
{ return (a<b)?((a<c)?a:c):((b<c)?b:c); }

int main()
{
	int n,m,**A;
	cin >> n >> m;

	A = (int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
		A[i] = (int *)malloc(m*sizeof(int));

	int count=0;	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> A[i][j];
			if(A[i][j]==1)
				count++;
		}

	// only two array is enough.
	// because we need only (i-1,j-1),(i-1,j),(i,j-1) elements.
	int **dp;
	dp = (int **)malloc(2*sizeof(int *));
	dp[0] = (int *)malloc(m*sizeof(int));
	dp[1] = (int *)malloc(m*sizeof(int));

	// copies first row into dp array
	for(int i=0;i<m;i++)
		dp[0][i] = A[0][i];

	// >1 rows and >1 columns
	for(int i=1;i<n;i++)
	{
		dp[i%2][0] = A[i][0];	// first element of each row
		for(int j=1;j<m;j++)
		{
			if(A[i][j]==1)	// checks whether current element can form square submatrix.
			{
				dp[i%2][j] = min(dp[(i+1)%2][j],dp[(i+1)%2][j-1],dp[i%2][j-1]) + 1;
				count = count + (dp[i%2][j]-1);
			}
			else     // it's sure that it wont take part in any square submatrix
				dp[i%2][j] = 0;
		}
	}
	cout << count << endl;
		
	return 0;
}
