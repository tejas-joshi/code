//====== MATRIX CHAIN MULTIPLCATION

/*
Given a set of matrices, find the minimum no. of scalar operations they have to perform for product.

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30

Logic :

Array will be given for matrices information.

e.g. 10 20 30 40 50
so there will be 4 matrices  10*20, 20*30, 30*40 and 40*50.	say A1,A2,A3 and A4 respectively.
cost table contains the minimum no. of scalar mult. required for product.

cost[i][j] is min. no. of scalar mult. from matrix i to j including both. 
e.g. i=1 and j=3 then cost[1][3] will contain min. no. of scalar mult. to compute the muliplication A1*A2*A3. ( among A1(A2A3) and (A1A2)A3 in this case)

Taking chain of each size(2 to n-1) and compute them.. store them in the matrix to use it for computing bigger chain
Now partition the chain to check which two smaller chain partitions give better answer... 

cost(i,j) = 	min	( cost[i][k] + cost[k+1][j] + A[i-1]*A[k]*A[j] )       
	       i<=k<j
	
	       A[i-1] because of no. of rows of first matrix 	


e.g. A1 A2 A3 A4 A5.. chain length is 5 ( 5 matrices ) ... 

To computer A1 to A5, we have several partitions.

A1 (A2 TO A5)      +  ( rows(A1)*cols(A2)*cols(A5) )
(A1 A2)(A3 to A5)  +  ( rows(A1)*cols(A3)*cols(A5) )
(A1 TO A3)(A4 A5)  +  ( rows(A1)*cols(A4)*cols(A5) )
ETC.

Minimum scalar multiplications required from all these will be answer for chain 5...i.e. cost[1][5]

so our goal is to find cost[1][n-1].

Logic for printing is explained in the comments.. 
For the simpleicity order matrix is printed ... you can remove that...

TC : O(n^3)
SC : O(n^2)

*/

#include<iostream>
#include<limits.h>
using namespace std;

void printSeq(int **order,int start,int end)
{
	if((end-start)==1)	// two matrices... no partition can happen now so print it..
		cout << start << "*" << end;
	else	// further parition must be there
	{
		// order[start][end] is the point where partition occured...
		// e.g. order[1][6] = 3 ==> (1..3)(4..6)    
		// So now we recursively compute for both the subpartitions and put parenthesis around them.
		// two subpartitions will be  (start,order[start][end])  and (order[start][end]+1,end)

		// in this if condition, only one matrix is there so no need of parenthesis and also this is base case for printing...
		// e.g. order[1][3] = 1  ==> (1) (2..3) ... Here only 1 will be printed ..no need of parenthesis...
		if(start==(order[start][end]))
			cout << start;
		else
		{
			cout << "(";
			printSeq(order,start,order[start][end]);
			cout << ")";
		}

		// same as above if block but for second partition.
		// example for this is.. order[4][6]=5  ==> (4..5)(6) .. 
		if( (order[start][end]+1)==end)
			cout << end;
		else
		{	
			cout << "(";
			printSeq(order,order[start][end]+1,end);
			cout << ")";
		}
	}
}

int main()
{
	int *A,n;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];
	/* cost[i,j] = Minimum number of scalar multiplications needed to compute
          the matrix M[i]M[i+1]...M[j] = M[i..j] where dimention of M[i] is
	  A[i-1] x A[i] */
	int **cost;
	cost = new int*[n];
	for(int i=0;i<n;i++)
		cost[i] = new int[n];

	int **order;
	order = new int*[n];
	for(int i=0;i<n;i++)
		order[i] = new int[n];



	// L is chain length.
	for(int L=2;L<n;L++)
		for(int i=1;i<=n-L;i++)	// i is the index of second dimension(columns) of first matrix being computed.. e.g. for (10*20)*30.. i will be 1 (20)..
								// same way for j.. j holds the index of second dimension of last matrix being considered considering i and L...
								// in general j will also be incremented to 1 but keeping distance of L-1.. 
								// if L=3 then 1 to 3 (i=1 => j=i+L-1 => 3).. 2 to 4... 3 to 5... etc.
		{ 
			cost[i][i]=0;	// cost is zero in case of one matrix.
			int j=i+L-1;
			cost[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++)		// j-1 because of single matrix in the last. 
			{
				// q = cost/scalar multiplications
				int q = cost[i][k] + cost[k+1][j] + A[i-1]*A[k]*A[j];	// checking for all the partitions that can be made in between i to j
											// taking k as paritition index
				if(q<cost[i][j])
				{
					cost[i][j] = q;
					order[i][j] = k; // STORES WHERE THE PARTITION OCCURS.
				}
			}
		}

	cout << cost[1][n-1] << endl;

	// order table is printed to see where the partitions happens for simplicity..
	// More logic is there in the printSeq function... 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << order[i][j] << " ";
		cout << endl;
	}
	printSeq(order,1,n-1);

	return 0;
}
