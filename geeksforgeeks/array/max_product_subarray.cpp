//=========== FIND MAXIMUM PRODUCT OF SUBARRAY
/*****
  Given an unsorted array, find the max. product of subarray.
 
Logic : in the comments
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

	// max_ending_here = maximum +ve product at current
	// min_ending_here = minimum -ve product at current
	// maxSum = our answer
	
	/* Traverse throught the array. Following values are maintained after the ith iteration:
          max_ending_here is always 1 or some positive product ending with arr[i]
          min_ending_here is always 1 or some negative product ending with arr[i] 
    */

	int max_ending_here=1,min_ending_here=1,maxSum=1;
	for(int i=0;i<n;i++)
	{	
		/* If this element is positive, update max_ending_here. Update
                   min_ending_here only if min_ending_here is negative */
		if(A[i]>0)
		{		
			max_ending_here = max_ending_here * A[i];
			min_ending_here = min(1,min_ending_here*A[i]);		
		}
		else if(A[i]==0)  // Here we are assuming that the output should be always >=0
			max_ending_here = min_ending_here = 1;
		/* If element is negative,
		   next min_ending_here will always be prev. max_ending_here * arr[i]
           next max_ending_here will be 1 if prev min_ending_here is 1, otherwise
           next max_ending_here will be prev min_ending_here * arr[i] */
		else	
		{
			int temp = max_ending_here;
			max_ending_here = max(min_ending_here*A[i],1);
			min_ending_here = temp*A[i];
		}
		if(maxSum < max_ending_here)
			maxSum = max_ending_here;
	}
	cout << maxSum << endl;
	return 0;
}
