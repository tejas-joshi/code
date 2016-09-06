//==== Maximum Product Cutting
/*
Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts. You must make at least one cut. Assume that the length of rope is more than 2 meters.

Examples:

Input: n = 2
Output: 1 (Maximum obtainable product is 1*1)

Input: n = 3
Output: 2 (Maximum obtainable product is 1*2)

Input: n = 5
Output: 6 (Maximum obtainable product is 2*3)

Input: n = 10
Output: 36 (Maximum obtainable product is 3*3*4)

- Logic is similar to RodCutting problem
maxProd(n) = max(i*(n-i), maxProd(n-i)*i) for all i in {1, 2, 3 .. n}

TC : O(n^2)
SC : O(n)


A Tricky Solution:
If we see some examples of this problems, we can easily observe following pattern.
The maximum product can be obtained be repeatedly cutting parts of size 3 while size is greater than 4, keeping the last part as size of 2 or 3 or 4. For example, n = 10, the maximum product is obtained by 3, 3, 4. For n = 11, the maximum product is obtained by 3, 3, 3, 2. Following is C++ implementation of this approach.

TC : O(logn).. if the power computation is done through divide and conquer.
SC : O(logn)

*/

#include<iostream>
using namespace std;

int maxProd(int n)
{
   // n equals to 2 or 3 must be handled explicitly
   if (n == 2 || n == 3) return (n-1);
 
   // Keep removing parts of size 3 while n is greater than 4
   int res = 1;
   while (n > 4)
   {
       n -= 3;
       res *= 3; // Keep multiplying 3 to res
   }
   return (n * res); // The last part multiplied by previous parts
}


int findMaxCut(int n)
{
	int *dp = new int[n+1];
	
	dp[0]=0;
	dp[1]=0;
	
	for(int i=2;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<i;j++)
			dp[i] = max( dp[i], max(j*dp[i-j],j*(i-j)) );
	}
	
	return dp[n];
}


int main()
{
	int n;
	cin >> n;	
	cout << findMaxCut(n) << endl;
	
	return 0;
}
