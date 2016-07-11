/*******************************

Given an array of positive integers.
All numbers occur even number of times except one number
which occurs odd number of times.
Find the number in O(n) time & constant space.

Example:
I/P = [1, 2, 3, 2, 3, 1, 3]
O/P = 3

Algorithm:
Do bitwise XOR of all the elements.
Finally we get the number which has odd occurrences. 

*********************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *A,n;
	cin >> n;

	// memory allocation and taking input
	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	// initialize ans to 0 and then XOR of all elements
	// only digit with odd occurences will cancel only 2 copies
	// but for other numbers they will cancel each other.
	// so ans will have the number which is occuring odd times.
	
	int ans=0;
	for(int i=0;i<n;i++)
		ans = ans ^ A[i];

	cout << ans << endl;
	
	return 0;
}
