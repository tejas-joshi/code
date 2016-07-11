//======= PRINT THE LEADERS IN AN ARRAY

/******

Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.
For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2. 

Logic :
 * Scan all the elements from right to left in array and keep track of maximum till now. When maximum changes it’s value, print it.

TC : O(n)
SC : O(1)

*******/

#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int max=INT_MIN;
	for(int i=n-1;i>=0;i--)
	{
		if(max<A[i])
		{
			cout << A[i] << " ";
			max = A[i];
		}
	}
	cout << endl;

	return 0;
}
