//======== FIND TWO REPEATING ELEMENTS FROM THE ARRAY

/**
Given an array of size n. The range of elements is 1 to n-2.
{4, 2, 4, 5, 2, 3, 1} and n = 7
o/p : 2 4

Logic :
It is same as finding one repeating and the missing number from the range.
do XOR of (all the elements of array) and (1 to n-2)... this will be xor of two elements which are repeating let say xorAll.
Now find the bit position where both numbers are differing. ( xorAll & ~(xorAll-1) ) let say lastMSB

let the two numbers which are missing is x and y..

now parition the numbers where lastMSB is matching and not matching... 

Refer code for more clarity...

TC : O(n)
SC : O(1)

>>> Another easy logic ::
If changing the sign is allowed, just change the sign of A[(value-1)].
There are two points, last two number will not be referenced so it will as it is.
The numbers which are repeating twice, so their signs will be changes twice so that number will be same as initially.
We have to find the indexes in first n-2 numbers that has positive value. These will be repeating numbers.

**/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int xorAll=0;
	for(int i=0;i<n;i++)
		xorAll = xorAll ^ A[i];
	for(int i=1;i<=n-2;i++)
		xorAll = xorAll ^ i;
	// Here xorAll holds the xor of both the numbers which are repeating..

	// lastMSB holds the bit position where both are differing...
	int lastMSB = xorAll & ~(xorAll-1);

	int x=0,y=0;

	// follow the same procedure as above... first xor with all elements of array + 1 to n-2 but with two partitions... 
	for(int i=0;i<n;i++)
	{
		if(A[i] & lastMSB)	// partition  where A[i] matches with lastMSB
			x = x ^ A[i];
		else			// not matching
			y = y ^ A[i];
	}

	for(int i=1;i<=n-2;i++)
	{
		if(i & lastMSB)		// partition where A[i] matches with lastMSB
			x = x ^ i;
		else			// not matching.
			y = y ^ i;
	}

	cout << x << " " << y << endl;

	return 0;
}
