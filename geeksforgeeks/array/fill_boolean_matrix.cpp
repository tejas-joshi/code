//========= BOOLEAN MATRIX QUESTION

/**
Given a boolean matrix mat[M][N] of size M X N, modify it such that 
if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1. 

Example 1
The matrix
1 0
0 0
should be changed to following
1 1
1 0

Example 2
The matrix
0 0 0
0 0 1
should be changed to following
0 0 1
1 1 1

Example 3
The matrix
1 0 0 1
0 0 1 0
0 0 0 0
should be changed to following
1 1 1 1
1 1 1 1
1 0 1 1

Logic :
Take two boolean variables rowFlag and colFlag to indicate whether first row has any 1.. and first column has any 1 respectively.

Take first row and first column as auxiliary array to indicate row index and column index to be set.
i.e. If A[2][3] is 1 then A[2][0] and A[0][3] will be set to 1.

Now start from submatrix starting from 2nd row and 2nd column to all elements and set elements of auxiliary array accordingly.
At the end travarse auxiliary array to set the elements
After all do, Check rowFlag and colFlag to check to set first row and first column respectively.

TC : O(mn)
SC : O(1)

***/

#include<iostream>
using namespace std;
int main()
{
	int n,m,**A;
	cin >> n >> m;

	A = new int*[n];
	for(int i=0;i<n;i++)
		A[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> A[i][j];
	
	bool rowFlag=false,colFlag=false;
	
	// checking to set first column
	for(int i=0;i<n;i++)
		if(A[i][0])
		{
			colFlag=true;
			break;
		}

	// checking to set first row
	for(int i=0;i<m;i++)
		if(A[0][i])
		{
			rowFlag=true;
			break;
		}
	
	// setting the elements in auxiliary array if A[i][j]=1...
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(A[i][j])
			{
				A[0][j]=1;
				A[i][0]=1;
			}
	
	// setting the elements in matrix from row auxiliary array elements 
	for(int i=1;i<n;i++)
		if(A[i][0])
			for(int j=1;j<m;j++)
				A[i][j]=1;
	
	// setting the elements in matrix from column auxiliary array elements
	for(int i=1;i<m;i++)
		if(A[0][i])
			for(int j=1;j<n;j++)
				A[j][i]=1;

	// if rowFlag is true then set first row to 1
	if(rowFlag)
		for(int i=0;i<m;i++)
			A[0][i]=1;

	// if colFlag is treu then set first column to 1
	if(colFlag)
		for(int i=0;i<n;i++)
			A[i][0]=1;

	// printing the resultant matrix.
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}
