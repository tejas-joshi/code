/******************

Write an efficient C program to find the sum of contiguous
subarray within a one-dimensional array of numbers which has the largest sum.

LOGIC : Kadane's Algorithm

*******************/

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{	
	int *A,n;
	cin >> n;

	A = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> A[i];

	// assigning min. value
	int max_sum=INT_MIN;

	// checking for all negative elements
	// if yes then output min. negative element
	bool allNeg=true;
	for(int i=0;i<n;i++)
	{
		if(A[i]<=0 && A[i]<max_sum)
			max_sum	= A[i];
		else
		{
			allNeg=false;
			max_sum=0;
			break;
		}
	}

	// Just keep adding the elements into sum until it will be -ve
	// Check with max_sum every time and update if sum gets greater
	// If sum becomes negative, make it to 0 because adding elements to it
	//		makes no sense until positive element is added after it.
	if(!allNeg)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum = sum + A[i];
			if(sum<0)
				sum=0;
			if(sum>max_sum)
				max_sum = sum;
		}
	}
	cout << "Maximum subarray sum is " << max_sum << endl;
	
	return 0;
}
