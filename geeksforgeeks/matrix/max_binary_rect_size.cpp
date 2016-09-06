/// ======== Maximum size rectangle binary sub-matrix with all 1s

/* Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

Input : 0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  
1 1 1 1
1 1 1 1

We will use the logic of histogram here.

Step 1: Find maximum area for row[0]
Step 2:
    for each row in 1 to N - 1
        for each column in that row
            if A[row][column] == 1
              update A[row][column] with
                A[row][column] += A[row - 1][column]
    find area for that row
    and update maximum area so far 

Illustration :

step 1:    0 1 1 0  maximum area  = 2
step 2:
    row 1  1 2 2 1  area = 4, maximum area becomes 4
    row 2  2 3 3 2  area = 8, maximum area becomes 8
    row 3  3 4 0 0  area = 6, maximum area remains 8
	

TC : O(mn)
SC : O(n)
 */

#include<iostream>
#include<limits.h>
using namespace std;

int maxSubmatrixSum(int **mat, int nRows, int nCols)
{
	int **maxHeight;
	maxHeight = new int*[nRows];
	for(int i=0;i<nRows;i++)
		maxHeight[i] = new int[nCols];
		
	for(int col=0;col<nCols;col++)
		maxHeight[0][col] = mat[0][col];	

	int maxArea = histogram(maxHeight[0],n);  // finds the max area considering the elements as building size (in the histogram example)
	
	for(int i=1;i<nRows;i++)
	{	
		for(int j=0;j<nCols;j++)
			if(mat[i][j])
				maxHeight[i][j] = maxHeight[i-1][j] + 1;		
		maxArea = max(maxArea,histogram(maxHeight[i]));
	}	
	
	return maxArea;
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
		
	cout << maxSubmatrix(mat,row,col) << endl;
	
	return 0;
}