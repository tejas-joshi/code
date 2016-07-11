//====== ROTATION OF AN ARRAY

/******

Rotate an array by d elements

e.g.
6	// n
1 2 3 4 5 6
2	// d
3 4 5 6 1 2

TC : O(n)
SC : O(1)

Logic :
* Reverse 0 to d-1 elements
* Reverse d to n-1 elements
* Reverse 0 to n-1 elements
same as (BA) = (ArBr)r	// I think you got the point...  De Morgan's Law...

********/	

#include<iostream>
using namespace std;

void reverse(int *A,int start,int end)
{
	for(int i=start,j=end;i<=j;i++,j--)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;		
	}
}

int main()
{
	int n;
	cin >> n;

	int *A;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int d;
	cin >> d;

	reverse(A,0,d-1);
	reverse(A,d,n-1);
	reverse(A,0,n-1);
	
	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
	

	return 0;
}


