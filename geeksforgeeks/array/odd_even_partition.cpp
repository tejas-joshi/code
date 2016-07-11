//============== SEGREGATE ODD-EVEN ELEMENTS IN ARRAY
/****************

Given an array, partition the array into even and odd elements
i.e. even elements on left side and odd elements on right side..
order can be changed.

Logic:
=====
* Take two index i and j. i=0 and j=n-1
* Loop until A[i] is even and A[j] is odd by doing i++ and j--
* If found then swap both and i++ and j--
* Continue doing this until i<j.

TC : O(n)
SC : O(1)

****************/

#include<iostream>
using namespace std;
int main()
{
	int *A,n;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	for(int i=0,j=n-1;i<j;)
	{
		if(A[i]%2==0 && A[j]%2==1)	// left one is even and right one is odd.. 
		{	i++; j--;	}
		else if(A[i]%2==1 && A[j]%2==0)	// time to swap.. contradicting condition ( left is odd and right is even )
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
		else if(A[i]%2==0)	// even condition satisfied.. so check for next one
			i++;
		else           // odd condition satisfied .. so check for next one
			j--;
	}

	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
