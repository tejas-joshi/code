//===== WORD WRAP PROBLEM

/*
Given an array containing the length of the words and length of the line.
Print the sequence where the words should be kept so that the cost will be minimum.
Cost of the line is the cube of remaining space in the line... If it''s the last line then the cost will be 0.

e.g.
aaa bb cc ddddd  ( input will be 3,2,2,5 - length of each word )
the line width = 6

aaa		- 27	(3 spaces) =>3*3*3=27
bb cc	-  1	(1 space)  =>1*1*1
ddddd	-  0	(last line)=>0
	 ===
	  28

Greedy wont work here because
line1 - aaa bb	=>  0
line2 - cc		=> 64
line3 - ddddd	=>  0
		  ===
		   64

so DP... B)

Logic :
Take a 2D array 'extras',
extras[i][j] contains the no. of extra spaces in the line if words from i to j are included in single line.
	extras[i][j] can be negative. ( words i to j cannot be accomdated in single line )
Refer the code to fill the whole table.

Take another 2D array 'lc'
lc[i][j] contains the cost of including the words i to j in the single line.
	lc[i][j] = 0 		, for last line and extras[i][j]>0
		 = infinite	, if extras[i][j] is -ve
		 = cube of (extras[i][j]) ,otherwise

Take another array 'c'
c[i] contains the optimal cost from 1 to i words... So our answer is c[n].

	/  0   if j=0
c[j] = |
   \   |    min	   (c[i-1] + lc[i][j])  if j>0
	\ 1<=i<=j

TC : O(n^2)
SC : O(n^2)

*/

#include<iostream>
#include<limits.h>
using namespace std;

// UNDERSTAND THIS LOGIC OF PRINTING... 
int printSeq(int *p,int n)
{
	int k;
	if(p[n]==1)
		k=1;
	else
		k = printSeq(p,p[n]-1)+1;
	cout << "Line number : " << k << " ... Words : " << p[n] << " to " << n << endl;
	return k;
}

int main()
{
	int *l,n;
	cin >> n;
	l = new int[n];

	for(int i=0;i<n;i++)
		cin >> l[i];
	
	int M;
	cin >> M;


	int **extras,**lc;
	extras = new int*[n+1];
	lc = new int*[n+1];

	for(int i=0;i<=n;i++)
	{
		extras[i] = new int[n+1];
		lc[i] = new int[n+1];
	}

	for(int i=1;i<=n;i++)
	{
		extras[i][i] = M - l[i-1];
		for(int j=i+1;j<=n;j++)
			extras[i][j] = extras[i][j-1] - l[j-1] - 1;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(extras[i][j]<0)
				lc[i][j] = INT_MAX;
			else if(j==n && extras[i][j]>=0)	// last line
				lc[i][j] = 0;
			else
				lc[i][j] = extras[i][j]*extras[i][j]*extras[i][j];
		}
	}

	int *c;
	c = new int[n+1];
	c[0]=0;
	int *p;
	p = new int[n+1];

	// Calculate minimum cost and find minimum cost arrangement.
	// The value c[j] indicates optimized cost to arrange words
	// from word number 1 to j.
	for(int j=1;j<=n;j++)
	{
		c[j]=INT_MAX;
		for(int i=1;i<=j;i++)
		{
			//cout << extras[i][j] << " ";
			if(c[i-1]!=INT_MAX && lc[i][j]!=INT_MAX && (c[j]>c[i-1]+lc[i][j]))
			{
				c[j] = c[i-1] + lc[i][j];
				p[j]=i;
			}
		}
		cout << j << " " << p[j];
		cout << endl;
	}
	cout << c[n] << endl;
	printSeq(p,n);
	return 0;
}

