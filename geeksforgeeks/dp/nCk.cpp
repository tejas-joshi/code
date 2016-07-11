/**********

Find nCk.

LOGIC :
* Pascal Triangle
	C(n,r) = C(n-1,r-1) + C(n-1,r)
	C(n,0) = C(n,n) = 1

TC : O(nk)
SC : O(k)	( only two rows are enough to count current answer. If you'll try, you can make more efficient. )

**********/

#include<iostream>
#include<stdlib.h>
using namespace std;
typedef long long int LL;
int main()
{
	LL n,k;
	cin >> n >> k;

	LL **dp;
	dp = (LL **)calloc(2,sizeof(LL *));
	dp[0] = (LL *)calloc(k+1,sizeof(LL));
	dp[1] = (LL *)calloc(k+1,sizeof(LL));

	dp[0][0] = 1;

	for(int i=1;i<=n;i++)
	{
		dp[i%2][0] = 1LL;
		for(int j=1;j<=k;j++)
			dp[i%2][j] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j];
	}			

	cout << dp[n%2][k] << endl;
	
	return 0;
}
