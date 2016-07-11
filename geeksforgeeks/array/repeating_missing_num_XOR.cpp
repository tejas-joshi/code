//======= FIND THE MISSING AND REPEATING ELEMENT FROM AN ARRAY OF SIZE n HAVING ELEMENTS 1 to n

/*******
Given an array of size n which contains elements from 1 to n where one number is missing 
	and one number is repeating twice..
Print both the numbers.

Logic :
XOR of all the elements with XOR of 1 to n which will give XOR of both the numbers.
Now use the strategy for partition the numbers by set bit.
let say one number is x and other is y.
output both the numbers.

TC : O(n)
SC : O(1)
********/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int [n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int x=0,y=0;
	int lastSet=0;
	int xorAll=0;
	
	for(int i=1;i<=n;i++)
		xorAll = xorAll ^ i;
	
	for(int i=0;i<n;i++)
		xorAll = xorAll ^ A[i];

	// Here xorAll will have the xor of both the numbers .. 
	// becase repeating number is xored thrice and missing number is xored once.. all others are xored twice... 
	
	// lastSet contains the last set bit of both the numbers i.e. the last bit position where both differ.
	lastSet = xorAll & ~(xorAll-1);

	// Check once again and partition the numbers by the set bit we have computed...
	for(int i=0;i<n;i++)
		if(lastSet & A[i])
			x = x ^ A[i];
		else
			y = y ^ A[i];
	
	for(int i=1;i<=n;i++)
		if(lastSet & i)
			x = x ^ i;
		else
			y = y ^ i;

	cout << x << " " << y << endl;
	return 0;
}
