//==== FIND SUBARRAY WITH GIVEN SUM

/*****
Given an array with NON-NEGATIVE elements, find the subarray with given sum.
Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4

Logic :
Initialize a variable curr_sum as first element. 
curr_sum indicates the sum of current subarray. 
Start from the second element and add all elements one by one to the curr_sum. 
If curr_sum becomes equal to sum, then print the solution. 
If curr_sum exceeds the sum, then remove trailing elements while curr_sum is greater than sum.

TC : O(n)
SC : O(1)
******/

#include<iostream>
using namespace std;
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	int x;
	cin >> x;
	int sum=A[0],start=0;
	for(int i=1;i<=n;i++)	// it includes n just to check the subarray ending with last element...
	{
		while(sum>x && start<(i-1))
		{
			sum = sum - A[start];
			start++;
		}

		if(sum==x)
		{
			cout << "Sum is between " << start << " and " << i-1 << endl;
			break;
		}

		if(i<n)	// loop includes n so ...
			sum = sum + A[i];
	}
	return 0;
}
