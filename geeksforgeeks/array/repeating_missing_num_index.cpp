//=== FIND THE MISSING NUMBER AND REPEATING NUMBER FROM THE ARRAY OF SIZE n AND CONTAINS THE ELEMENTS IN THE RANGE 1 TO n.

/*******
Given an array of size n which contains the elements in 1 to n.
One number is missing and one number is occuring twice.
output those two numbers.
arr[] = {4, 3, 6, 2, 1, 1}
Output: 1, 5  // 5 is missing and 1 occurs twice 

Logic:
Use  element as index and change the sign of the element if it is +ve.
If it is -ve then declare it as repeating number..
After all done scan the array once again.
Only one number is +ve because that was not being referenced.. output the its index+1... that is missing number...

TC : O(n)
SC : O(1)
********/

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
		if(A[abs(A[i])-1]<0)	// already marked so it is repeating...
			cout << "Repeating number is " << abs(A[i]) << endl;
		else		/// change the sign of the element at index.
			A[abs(A[i])-1] = -A[abs(A[i])-1];

	for(int i=0;i<n;i++)
		if(A[i]>0)	// checking for missing number because it is +ve.
		{
			cout << "Missing number is " << i+1 << endl;
			break;
		}

	return 0;
}
