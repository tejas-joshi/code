/// ======== Print maximum sum square sub-matrix of given size

/* Given an N x N matrix, find a k x k submatrix where k <= N and k >= 1, such that sum of all the elements in submatrix is maximum. 
The input matrix can contain zero, positive and negative numbers.

Logic in the code

Here logic is for finding the sum
Submatrix can be printed just by storing i and j then print the matrix of size k which is ending at (i,j)

TC : O(mn)
SC : O(mn)
 */

#include<iostream>
#include<limits.h>
using namespace std;

int maxSubmatrixSum(int **mat, int nRows, int nCols,int k)
{
	if(k > nRows)
		return -1;
	
	int **sumSubMat;
	sumSubMat = new int*[nRows+1];
	for(int i=0;i<=nRows;i++)
		sumSubMat[i] = new int[nCols+1];
	
	sumSubMat[0][0] = 0;
	
	// Making first column zero
	for(int col=0;col<=nCols;col++)
		sumSubMat[0][col] = 0;	
	// Setting first row zero
	for(int row=0;row<=nRows;row++)
		sumSubMat[row][0] = 0;

	// Storing all the submatrix sum
	// sumSubMat[i-1][j] = sum of submatrix(i-1,j)
	// sumSubMat[i][j-1] = sum of submatrix(i,j-1)
	// deducting sumSubMat[i-1][j-1] because that is being added twice
	// adding mat[i-1][j-1] as current element
	for(int i=1;i<=nRows;i++)
		for(int j=1;j<=nCols;j++)
			sumSubMat[i][j] = sumSubMat[i-1][j] + sumSubMat[i][j-1] - sumSubMat[i-1][j-1] + mat[i-1][j-1];
		
	// Finding the maximum submatrix sum of kxk
	int maxSum = INT_MIN;
	for(int i=k;i<=nRows;i++)
		for(int j=k;j<=nCols;j++)
			if(maxSum < sumSubMat[i][j] - (sumSubMat[i-k][j] + sumSubMat[i][j-k]) + sumSubMat[i-k][j-k])
				maxSum = sumSubMat[i][j] - (sumSubMat[i-k][j] + sumSubMat[i][j-k]) + sumSubMat[i-k][j-k];
	
	return maxSum;
}

int main()
{
	int **mat;
	int col,row,k;
	cin >> row >> col;
	mat = new int*[row];
	for(int i=0;i<row;i++)
		mat[i] = new int[col];
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin >> mat[i][j];

	cin >> k;
		
	cout << maxSubmatrixSum(mat,row,col,k) << endl;
	
	return 0;
}