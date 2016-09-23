//====== Longest Arithmetic Progression 
/*****************
Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.

set[] = {1, 7, 10, 15, 27, 29}
output = 3
The longest arithmetic progression is {1, 15, 29}

set[] = {5, 10, 15, 20, 25, 30}
output = 6

* Check the function to check whether array has 3 elements which are in AP. (Check the program and the comments)
* Soln of this problem extends the soln of the above problem. (After understanding above soln., Check the code and comments)
* Awesome logic !! <3 <3

*****************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


// The function returns true if there exist three elements in AP
// Assumption: set[0..n-1] is sorted. 
// The code strictly implements the algorithm provided in the reference.

/* 
We first fix an element as middle element and search for other two (one smaller and one greater). 
We start from the second element and fix every element as middle element. 
For an element set[j] to be middle of AP, 
there must exist elements ‘set[i]’ and ‘set[k]’ such that set[i] + set[k] = 2*set[j] where 0 <= i < j and j < k <=n-1.
*/
/*
bool arithmeticThree(int set[], int n)
{
    // One by fix every element as middle element
    for (int j=1; j<n-1; j++)
    {
        // Initialize i and k for the current j
        int i = j-1, k = j+1;
 
        // Find if there exist i and k that form AP
        // with j as middle element
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] == 2*set[j])
                return true;
            (set[i] + set[k] < 2*set[j])? k++ : i–-;
        }
    }
    return false;
}
*/

// An entry L[i][j] in this table stores LLAP with set[i] and set[j] as first two elements of AP and j > i. The last column of the table is always 2.
// Rest of the table is filled from bottom right to top left. To fill rest of the table, j (second element in AP) is first fixed. 
// i and k are searched for a fixed j. If i and k are found such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1.
int findLLAP(int *A,int n)
{
	if(n<=2)
		return n;
	
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	
	// Fill entries in last column as 2. There will always be
    // two elements in AP with last number of set as second
    // element in AP
	for(int i=0;i<n;i++)
		dp[i][n-1] = 2;
	
	int i,j,k;
	int llap=2;
	
	for(int j=n-2;j>=1;j--)
	{
		i=j-1,k=j+1;
		
		while(i>=0 && k<=n-1)
		{
			if(A[i]+A[k]>2*A[j])
			{
				dp[i][j]=2; // We are setting 2 as we were not able to find k such that A[i] and A[j] can be first two elements. Here k has least value. 
				// Further increasing k will increase the value as array is sorted.
				i--;
			}
			else if(A[i]+A[k]<2*A[j])
				k++;
			else
			{
				// Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
				dp[i][j] = dp[j][k]+1;

				if(dp[i][j]>llap)
					llap = dp[i][j];
				i--;
				k++;
			}
		}

		// If the loop was stopped due to k becoming more than
        // n-1, set the remaining entties in column j as 2
		while(i>=0)
		{
			dp[i][j]=2;
			i--;
		}
	}
	return llap;		
}

int main()
{
	int *A,n;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	cout << findLLAP(A,n) << endl;	
	
	return 0;
}
