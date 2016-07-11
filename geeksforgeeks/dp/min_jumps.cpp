/*****************

FIND MINIMUM NO. OF STEPS TO REACH END
Each element indicates how many steps you can take atmost.
e.g. A[i] = 3. You can reach to (i+1),(i+2),(i+3) in 1 step after A[i].

Logic :
* Just like LIS of O(n^2), check for all the previous j's such that j<i
	and reach to i or beyond i.
	dp[i] = min(no. of steps to reach i) + 1

TC : O(n^2)
SC : O(n)

*****************/

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n,*dp;
	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	dp = (int *)malloc((n+1)*sizeof(int));

	for(int i=0;i<n;i++)
		cin >> A[i];

	dp[0]=0;				// initial values

	for(int i=1;i<n;i++)
	{
		int min=INT_MAX;
		for(int j=0;j<i;j++)
			if(i<=j+A[j] && min>(dp[j]+1))	// first condition for reaching there and second for checking min jumps
				min = dp[j]+1;
		dp[i] = min;
	}

	cout << dp[n-1] << endl;	
	
	return 0;
}
