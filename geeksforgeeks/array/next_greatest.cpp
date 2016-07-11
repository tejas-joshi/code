//==== REPLACE THE ARRAY WITH THE NEXT GREATEST ELEMENT IN THE RIGHT SIDE

/*******

Given an array, replace each element with the greatest element on right side.

i/p: 16 17 4 3 5 2
o/p: 17 5 5 5 2 -1 

Logic :
Start from the right side.
-1 for the last element.
Keep track of max element you find till now and print it on current element.

TC : O(n)
SC : O(1)

********/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int max;
	if(n>0)
	{
		max = A[n-1];
		A[n-1] = -1;
	}
	
	for(int i=n-2;i>=0;i--)
	{
		int temp = max;
		if(A[i]>max)
			max = A[i];
		A[i]=temp;
	}

	for(int i=0;i<n;i++)
		cout << A[i] <<" ";
	cout << endl;
	return 0;
}	
