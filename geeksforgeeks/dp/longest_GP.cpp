//====== Longest Geometric Progression 
/*****************
Given a set of numbers, find the Length of the Longest Geometric Progression (LLGP) in it.

set[] = {5, 7, 10, 15, 20, 29}
output = 3
The longest geometric progression is {5, 10, 20}

set[] = {3, 9, 27, 81}
output = 4

* Check the problem of finding longest geometric progression. Then you can easily solve this problem.
* Awesome logic !! <3 <3

*****************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

// An entry L[i][j] in this table stores LLGP with set[i] and set[j] as first two elements of GP and j > i.
// Rest of the table is filled from bottom right to top left. To fill rest of the table, j (second element in GP) is first fixed. 
// i and k are searched for a fixed j. If i and k are found such that i, j, k form an GP, then the value of L[i][j] is set as L[j][k] + 1.
int findLLGP(int *A,int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return (A[1]%A[0]==0)?2:1;
	
	int dp[n][n];
	memset(dp,0,sizeof(dp));

	int llgp=1;	

    // Two elements in GP with last number of set as second element in GP
	for(int i=0;i<n;i++)
	{
		if(A[n-1]%A[i]==0)
		{	
			dp[i][n-1]=2;
			llgp=2;
		}
		else
			dp[i][n-1]=1;
	}	
	
	int i,j,k;
	
	for(int j=n-2;j>=1;j--)
	{
		i=j-1,k=j+1;
		
		while(i>=0 && k<=n-1)
		{
			if(A[i]*A[k]>A[j]*A[j])
			{
				if(A[j]%A[i]==0)
				{
					dp[i][j]=2;
					llgp = max(llgp,dp[i][j]);
				}
				else
					dp[i][j]=1;
				// We are setting 2 as we were not able to find k such that A[i] and A[j] can be first two elements. Here k has least value. 
				// Further increasing k will increase the value as array is sorted.
				i--;
			}
			else if(A[i]*A[k]<A[j]*A[j])
				k++;
			else
			{
				// Found i and k for j, LLGP with i and j as first two
               // elements is equal to LLGP with j and k as first two
               // elements plus 1. 
			   dp[i][j] = dp[j][k]+1;

				if(dp[i][j]>llgp)
					llgp = dp[i][j];
				i--;
				k++;
			}
		}

		// If the loop was stopped due to k becoming more than
        // n-1, set the remaining entties in column j as 2 or 1 (depending on the condition)
		while(i>=0)
		{
			if(A[j]%A[i]==0)
			{
				dp[i][j]=2; 
				llgp=max(llgp,2);
			}
			else
				dp[i][j]=1;
			i--;
		}
	}
	return llgp;		
}

int main()
{
	int *A,n;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	cout << findLLGP(A,n) << endl;	
	
	return 0;
}
