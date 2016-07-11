//=== PRINT THE MATRIX IN DIAGONAL LINES 

/*
 * FOR THIS MATRIX :

    1     2     3     4
    5     6     7     8
    9    10    11    12
   13    14    15    16
   17    18    19    20


	1
    5     2
    9     6     3
   13    10     7     4
   17    14    11     8
   18    15    12
   19    16
   20

Logic : 
* 
* Logic is explained in the code... It is totally game of indexes... Just get the logic of series...
* 

TC : O(mn)	// obviously..
SC : O(1)

*/

#include<iostream>
using namespace std;

void printDiagonal(int **A,int row,int col)
{
	int r,c;
	
	// r -> row index of currently printing element
	// c -> col index of currently printing element 
	
	// line indicates the diagonal lines we are going to print
	// the value of line would be the sum of indexes of row and col.. It would be same for all the elements for the same line...
	
	for(int line=0;line<row+col;line++)
	{
		// Here we set the indexes of the element of the first element of each line
		r = min(row-1,line);
		c = max(line-row+1,0);
		
		while(r>=0 && c<col)
		{
			cout << A[r][c] << " ";
			r--;
			c++;
		}
		cout << endl;				
	}
}

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
	
	printDiagonal(A,n,m);
	
	return 0;
}
