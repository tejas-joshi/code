//==== SEARCH ELEMENT IN ROW AND COLUMN SORTED MATRIX..

/**

Given a matric which is sorted column wise and row wise, search an element in it.

You have only 5 seconds to think....

Logic :
Start from the top-right element... i=0,j=n-1

while( i<n and j>=0 )
	if x==A[i][j] 
		print index
	else if x<A[i][j]
		go down.. i++
	else
		go left.. j--

TC : O(m+n)
SC : O(1)

**/

#include<iostream>
using namespace std;
int main()
{
	int n,m;
	int **A;
	cin >> n >> m;

	A = new int*[n];
	for(int i=0;i<n;i++)
		A[i] = new int[m];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> A[i][j];
	int x;
	cin >> x;
	bool found=false;

	int i=0,j=n-1;
	while(i<n && j>=0)
	{	
		if(x==A[i][j])	   // searched the element
		{
			found = true;
			cout << "(" << i << "," << j << ")" << endl;
			break;
		}
		else if(x<A[i][j]) // go left
			j--;
		else	           // go down
			i++;
	}
	
	if(!found)
		cout << "element not found" << endl;

	return 0;
}
