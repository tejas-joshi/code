// ========= Print Matrix Diagonally

/* 
Given a 2D matrix, print all elements of the given matrix in diagonal order. For example, consider the following 5 X 4 input matrix.

    1     2     3     4
    5     6     7     8
    9    10    11    12
   13    14    15    16
   17    18    19    20
Diagonal printing of the above matrix is

    1
    5     2
    9     6     3
   13    10     7     4
   17    14    11     8
   18    15    12
   19    16
   20
  
 TC : O(mn)
 SC : O(1)
*/
   
#include<iostream>
using namespace std;

void printDiagonally(int **mat, int nRows, int nCols)
{
	//  print the portion starting from each row's first element
	for(int row=0;row<nRows;row++)
	{
		for(int j=0,i=row;(j<nCols && i>=0);j++,i--)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}		

	// print the portion starting from the bottom of second column to end
	// Here we are starting from 1 because the corner diagonal was covered in the above loop
	for(int col=1;col<nCols;col++)
	{
		for(int j=col,i=nRows-1;(j<nCols && i>=0);j++,i--)
		{
			cout << mat[i][j] << " ";
			// cout << i << ":" << j << " ";
		}
		cout << endl;
	}		
}
int main()
{
	int **mat;
	int row,col;
	cin >> row >> col;
	
	mat = new int*[row];
	for(int i=0;i<row;i++)
		mat[i] = new int[col];
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin >> mat[i][j];
	
	printDiagonally(mat,row,col);
	
	return 0;
}