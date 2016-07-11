//===== FIND THE EQUILIBRIUM INDEX OF THE ARRAY

/**
Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. 

For example, in an arrya A:
-7,1,5,2,-4,3,0

3 is an equilibrium index, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

6 is also an equilibrium index, because sum of zero elements is zero, i.e., A[0] + A[1] + A[2] + A[3] + A[4] + A[5]=0

You have 5 seconds to think...

Logic :
The idea is to get total sum of array first. 
Then Iterate through the array and keep updating the left sum which is initialized as zero. 
In the loop, we can get right sum by subtracting the elements one by one.

Refer code for more understanding...

TC : O(n)
SC : O(1)
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

	int lsum=0,sum=0;

	// lsum contains sum of all the elements left to A[i]
	// sum contains total sum
	for(int i=0;i<n;i++)
		sum = sum + A[i];

	for(int i=0;i<n;i++)
	{
		sum = sum - A[i];

		if(lsum==sum)
		{
			cout << i << endl;
			break;
		}

		lsum = lsum + A[i];
	}

	return 0;
}
