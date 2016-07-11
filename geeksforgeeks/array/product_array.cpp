//============== PRODUCT ARRAY

/***********
Given an array, output an array which contains in which each element is product of all elements in left and all in right.

Example:
arr[] = {10, 3, 5, 6, 2}
prod[] = {180, 600, 360, 300, 900}

Logic:

* Take an extra array that contains product of all the elements in its left. First element will be 1.
* Now start from last element and take a variable that contains product of elements in right on every iteration.
* prod[i] = prod[i] * temp; // Here prod[i] already contains product of all elements left to i and temp contains product of right of i.
* output prod array.

TC : O(n)
SC : O(n)
************/

#include<iostream>
using namespace std;
int main()
{
	int *A,*prod,n;
	cin >> n;
	A = new int[n];
	prod = new int[n];

	int temp=1;
	for(int i=0;i<n;i++)
	{
		cin >> A[i];
		prod[i] = temp;		// prod contains product of all elements in its left.. for first it will be 1.
		temp = temp * A[i];	
	}

	temp=1;

	for(int i=n-1;i>=0;i--)
	{
		prod[i] = prod[i] * temp;	// update prod array for the product of left product and right product.
		temp = temp * A[i];		// temp will contain product of elements in right of i. A[i] is multiplied in every iteration and it is for n-1 to 0.	
	}

	for(int i=0;i<n;i++)
		cout << prod[i] << " ";
	cout << endl;
	
	return 0;
}
