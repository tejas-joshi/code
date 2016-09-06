//==== Boolean Parenthesization Problem

/*
Symbols
    'T' ---> true 
    'F' ---> false
	
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
	
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, T, F, T}
       operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) 
and (T|((T&F)^T)). 

Logic :
- It is the same logic as matrix chain multiplication (taking L as window length, loop through all the windows, in each window - check for each partition)

TC : O(n^3)
SC : O(n^2)

*/

#include<iostream>
using namespace std;

int countParenthesization(char *val,char *opr,int n)
{
	int **T = new int*[n];
	int **F = new int*[n];
	for(int i=0;i<n;i++)
	{
		T[i] = new int[n];
		F[i] = new int[n];
	}

	// Fill diaginal entries first
    // All diagonal entries in T[i][i] are 1 if symbol[i]
    // is T (true).  Similarly, all F[i][i] entries are 1 if
    // symbol[i] is F (False)	
	for(int i=0;i<n;i++)
	{
		T[i][i] = (val[i]=='T')?1:0;
		F[i][i] = (val[i]=='F')?1:0;
	}
	
	for(int L=2;L<=n;L++) // deciding the window length
	{
		for(int i=0,j=L-1;j<n;i++,j++) // deciding the window
		{
			T[i][j] = F[i][j] = 0;
			for(int part=i;part<(i+L-1);part++)	// loop through all the partitions in the current window
			{
				// Store Total[i][k] and Total[k+1][j]
				int total_i_part = T[i][part] + F[i][part];
				int total_part_j = T[part+1][j] + F[part+1][j];

				// Checking current operator
				if(opr[part]=='&')
				{
					T[i][j] += T[i][part]*T[part+1][j];
					F[i][j] += ((total_i_part*total_part_j) - T[i][part]*T[part+1][j]);
				}
				else if(opr[part]=='|')
				{
					F[i][j] += F[i][part]*F[part+1][j];
					T[i][j] += ((total_i_part*total_part_j) - F[i][part]*F[part+1][j]);
				}
				else if(opr[part]=='^')
				{
					T[i][j] += (T[i][part]*F[part+1][j] + F[i][part]*T[part+1][j]);
					F[i][j] += (F[i][part]*F[part+1][j] + T[i][part]*T[part+1][j]);					
				}
			}
		}
	}
	return T[0][n-1];
}

int main()
{
	int n;
	char *val,*opr;
	cin >> n;
	val = new char[n];
	opr = new char[n-1];

	for(int i=0;i<n;i++)
		cin >> val[i];
	for(int i=0;i<n-1;i++)
		cin >> opr[i];
	
	cout << countParenthesization(val,opr,n) << endl;
  	
	return 0;
}
