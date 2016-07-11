//==== FIND TWO NUMBERS WITH ODD OCCURENCES FROM ARRAY

/******
Given an array, there are two numbers with odd occurences and others with two/even occurences.
Find those two numbers.

Logic :
Find XOR of all the numbers.
	result will be xor of both numbers with odd occurences.
Now find the one bit position where both the numbers differ. (i.e. first bit from LSB side of result which is set.) let it is 'a'
Again xor of all the numbers but the one which is having that bit set is xor to x.
	else it is xored to y...
Look into code for more clarity.

TC : O(n)
SC : O(1)
*********/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	// xor2 contains xor of all the elements.. finally it will be xor of both the elements with odd occurences.
	int xor2=0;
	for(int i=0;i<n;i++)
		xor2 = xor2 ^ A[i];

	// finding the bit position which is set in xor2 i.e. the first position from LSB side which differs in both the numbers.
	// ~  ->  inverts all the bits .. like bitwise NOT...
	
	int lastMSB = xor2 & ~(xor2-1);

	int x=0,y=0; // x and y are the numbers with odd occurences which we are going to find.

	for(int i=0;i<n;i++)
	{
		if(A[i] & lastMSB)	// the number which has lastMSB set... finally this will contain one of both numbers
			x = x ^ A[i];
		else			// the number which has lastMSB not set...finally this will contain the other number.
			y = y ^ A[i];
	}
	cout << x << " " << y << endl;

	return 0;
}
