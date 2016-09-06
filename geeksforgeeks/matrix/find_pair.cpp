/// ======== Find a specific pair in Matrix

/* Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] - mat[1][0] = 18 has maximum difference. 

We pre-process the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1) 
and in the process keeps on updating maximum value found so far. We finally return the maximum value.

TC : O(mn)
SC : O(mn)

 */

#include<iostream>
#include<limits.h>
using namespace std;

int findPairDiff(int **mat, int nRows, int nCols)
{
	int **maxDiffMat;
	maxDiffMat = new int*[nRows];
	for(int i=0;i<nRows;i++)
		maxDiffMat[i] = new int[nCols];
	
	maxDiffMat[nRows-1][nCols-1] = mat[nRows-1][nCols-1];
	int maxV = mat[nRows-1][nCols-1];
	
	// process last row
	for(int col=nCols-2;col>=0;col--)
	{
		if(maxV > maxDiffMat[nRows-1][col])
			maxV = maxDiffMat[nRows-1][col];
		maxDiffMat[nRows-1][col] = maxV;
	}		
	
	// process last column
	maxV = mat[nRows-1][nCols-1];
	for(int row=nRows-2;row>=0;row--)
	{
		if(maxV > maxDiffMat[row][nCols-1])
			maxV = maxDiffMat[row][nCols-1];
		maxDiffMat[row][nCols-1] = maxV;
	}		

	
	int maxDiff = INT_MIN;
	for(int i=nRows-2;i>=0;i--)
	{
		for(int j=nCols-2;j>=0;j--)
		{
			if(maxDiffMat[i+1][j+1]-mat[i][j] > maxDiff)
				maxDiff = maxDiffMat[i+1][j+1]-mat[i][j];
			maxDiffMat[i][j] = max(max(mat[i+1][j+1], maxDiffMat[i+1][j]),maxDiffMat[i][j+1]);
		}
	}
	return maxDiff;
}

int main()
{
	int **mat;
	int col,row;
	cin >> row >> col;
	mat = new int*[row];
	for(int i=0;i<row;i++)
		mat[i] = new int[col];
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin >> mat[i][j];
		
	cout << findPairDiff(mat,row,col) << endl;
	
	return 0;
}