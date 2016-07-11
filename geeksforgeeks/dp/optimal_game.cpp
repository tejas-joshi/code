//====== Optimal Strategy for a Game

/*
Consider a row of n coins of values v1 . . . vn, where n is even. 
We play a game against an opponent by alternating turns. 
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, 
and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

Note: The opponent is as clever as the user.

There are two choices:
1. The user chooses the ith coin with value Vi: The opponent either chooses (i+1)th coin or jth coin. 
The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) )

2. The user chooses the jth coin with value Vj: The opponent either chooses ith coin or (j-1)th coin. 
The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vj + min(F(i+1, j-1), F(i, j-2) )

Following is recursive solution that is based on above two choices. We take the maximum of two choices.

F(i, j)  represents the maximum value the user can collect from 
         i'th coin to j'th coin.

    F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
                   Vj + min(F(i+1, j-1), F(i, j-2) )) 
Base Cases
    F(i, j)  = Vi           If j == i
    F(i, j)  = max(Vi, Vj)  If j == i+1


TC : O(n^2)
SC : O(n^2)
    
*/

#include<iostream>
using namespace std;

int optimalGame(int *A,int n)
{
	int **res;
	res = new int*[n];
	for(int i=0;i<n;i++)
		res[i] = new int[n];
	
	// from diagonal elements to table[0][n-1] which is the result.
	for(int diff=0;diff<n;diff++)
		for(int i=0,j=diff;j<n;j++,i++)
		{
			int i2j = ((i+2)<=j)?res[i+2][j]:0;
			int i1j1 = ((i+1)<=(j-1))?res[i+1][j-1]:0;
			int ij2 = (i<=(j-2))?res[i][j-2]:0;
			
			res[i][j] = max( A[i] + min(i2j,i1j1) , A[j] + min(i1j1,ij2) );
		}
	return res[0][n-1];
}

int main()
{
	int n,*A;
	cin >> n;
	
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	cout << optimalGame(A,n) << endl;
	
	return 0;	
}	
