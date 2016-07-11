/************

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
For example, if length of the rod is 8 and the values of different pieces are given as following,
	then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

LOGIC :
* dp[i] indicates max. price of cutting rod of length i.
* for i from 1 to n in array
		maxV = INT_MIN
		for j from 0 to i-1
			maxV = max(maxV,A[j]+dp[i-j-1])		// NICE FORMULA... MAKES SENSE..
		dp[i] = maxV

	let say i=5
	then j will loop through 0 to 4

							// HERE WE ARE DOING ...A[] + dp[] not... A[] + A[] (because that will indicate we can only divide in two parts. Here we can divide in more than two parts also..)
							// We are not considering dp[] + dp[] in formula because it is not considering A[]..
							
							 /	A[0] + dp[4]		
							/   A[1] + dp[3]
		dp[5] will be max  |	A[2] + dp[2]
							\   A[3] + dp[1]
							 \  A[4] + dp[0]

TC : O(n^2)
SC : O(n)

************/
							  
#include<iostream>      
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n,*dp;
	cin >> n;
	
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	dp = new int[n+1];
	dp[0] = 0;

	for(int i=1;i<=n;i++)
	{
		int maxVal = INT_MIN;
		for(int j=0;j<i;j++)
			maxVal = max(maxVal,A[j] + dp[i-j-1]);
		dp[i] = maxVal;
	}
	cout << dp[n] << endl;
	
	return 0;
}
