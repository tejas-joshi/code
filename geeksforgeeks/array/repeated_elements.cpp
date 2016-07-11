//==== PRINT THE DUPLICATES IN THE ARRAY... 

/**
Given an array of size n. Array contains values in the range 0 to n-1.
Multiple elements can be repeated.

Logic :
Use the logic of element as index.
Change the element at the index to -ve if it is +ve.
If it is already -ve then it is repeating. print it.

TC : O(n)
SC : O(1)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	for(int i=0;i<n;i++)
		if(A[abs(A[i])]<0)
			cout << abs(A[i]) << " ";
		else
			A[abs(A[i])] = -A[abs(A[i])];
	cout << endl;

	return 0;
}
