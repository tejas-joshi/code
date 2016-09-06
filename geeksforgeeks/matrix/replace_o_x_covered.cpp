/// ======== Given a matrix of ‘O’ and ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’

/* Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. 
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, 
just above, just left and just right of it.

Input: mat[M][N] =  
					{{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
Input: mat[M][N] =  
					{{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };

This is mainly an application of Flood-Fill algorithm. 
The main difference here is that a ‘O’ is not replaced by ‘X’ if it lies in region that ends on a boundary. 
Following are simple steps to do this special flood fill.

1) Traverse the given matrix and replace all ‘O’ with a special character ‘-‘.

2) Traverse four edges of given matrix and call floodFill(‘-‘, ‘O’) for every ‘-‘ on edges. 
	The remaining ‘-‘ are the characters that indicate ‘O’s (in the original matrix) to be replaced by ‘X’.

3) Traverse the matrix and replace all ‘-‘s with ‘X’s.
	

TC : O(mn)
SC : O(n)
 */

#include<iostream>
#include<limits.h>
using namespace std;

void floodFill(char **mat, int row,int col, int nRows, int nCols, char prevC, char newC)
{
	if(row < 0 || row >= nRows || col < 0 || col >= nCols || mat[row][col] != prevC)
		return;
	
	mat[row][col] = newC;
	
	floodFill(mat,row+1,col,nRows,nCols,prevC,newC);
	floodFill(mat,row-1,col,nRows,nCols,prevC,newC);
	floodFill(mat,row,col+1,nRows,nCols,prevC,newC);
	floodFill(mat,row,col-1,nRows,nCols,prevC,newC);
}

int replaceOX(char **mat, int nRows, int nCols)
{
	// Replacing all O by -
	for(int i=0;i<nRows;i++)
		for(int j=0;j<nCols;j++)
			if(mat[i][j]=='O')
				mat[i][j] = '-';

	// Replacing all - in the first row by O and calling flood fill
	for(int col=0;col<nCols;col++)
		if(mat[0][col]=='-')
			floodFill(mat,0,col,nRows,nCols,'-','O');
	// same for last row
	for(int col=nCols-1;col>=0;col--)
		if(mat[nRows-1][col]=='-')
			floodFill(mat,nRows-1,col,nRows,nCols,'-','O');
	// same for first column
	for(int row=0;row<nRows;row++)
		if(mat[row][0]=='-')
			floodFill(mat,row,0,nRows,nCols,'-','O');
	// same for last column
	for(int row=nRows-1;row>=0;row--)
		if(mat[row][nCols-1]=='-')
			floodFill(mat,row,nCols-1,nRows,nCols,'-','O');

	// Replacing all the remaining - by X
	for(int i=1;i<nRows-1;i++)
		for(int j=1;j<nCols-1;j++)
			if(mat[i][j]=='-')
				mat[i][j] = 'X';
	
}

int main()
{
	char **mat;
	int col,row;
	cin >> row >> col;
	mat = new char*[row];
	for(int i=0;i<row;i++)
		mat[i] = new char[col];
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin >> mat[i][j];
		
	replaceOX(mat,row,col);
	
	for (int i=0; i<row; i++)
    {
		for (int j=0; j<col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
    }
	return 0;
}