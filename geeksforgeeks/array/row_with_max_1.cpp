//=== FIND THE ROW WITH MAX 1s

/*******
Given a 2D array, find the row with max 1s.
Here each row is in sorted order... i.e. all 0s followed by all 1s.
e.g.
4 4
0 1 1 1
0 0 1 1
1 1 1 1
0 0 0 0
 o/p : 2

Logic:
Take two index i and j... i=0(row) and j=n-1(column)
Start with the first row and right most element
	Continue decrementing j till you find A[i][j]=1.. and record i into rowInd to maintain index of row.
	If A[i][j]==0 then increment i.. 
	continue this until you cover all the rows..

TC : O(m+n)
SC : O(1)
*******/	

#include<iostream>
using namespace std;
int main()
{
	int m,n,**A;
	cin >> m >> n;
	A = new int*[m];
	for(int i=0;i<m;i++)
		A[i] = new int[n];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];

	int col=n-1,rowInd=-1;	
	for(int i=0;i<m;i++)
	{
		while(col>=0 && A[i][col]==1)
		{
			col--;
			rowInd=i;
		}
	}
	if(rowInd==-1)
		cout << "no rows found" << endl;
	else	
		cout << rowInd << endl;

	return 0;
}
