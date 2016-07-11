/*****

You are given a list of n-1 integers and
these integers are in the range of 1 to n.
There are no duplicates in list.
One of the integers is missing in the list.
Write an efficient code to find the missing integer.

Example:
I/P    [1, 2, 4, 6, 3, 7, 8]
O/P    5

LOGIC :

1. XOR all the elements from 1 to n.. let say it is ans.
2. XOR ans with all the array elements.
	only the missing number won't be cancelled.
So ans is the missing number.

*****/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int *A,n;
	cin >> n;

	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	// assign ans to 0
	// XOR with 1 to n+1 elements...
	// here n is array size so n+1
	int ans=0;
	for(int i=1;i<=n+1;i++)
		ans = ans ^ i;

	// XOR with array elements
	// only missing number wont be cancelled.
	for(int i=0;i<n;i++)
		ans = ans ^ A[i];

	cout << ans << endl;
	
	return 0;
}
