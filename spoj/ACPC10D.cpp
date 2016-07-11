#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
typedef long long int LL;

LL min2(LL a, LL b)
{	return (a<b)?a:b;	}

LL min4(LL a, LL b, LL c,LL d)
{ 	return min2(min2(a,b),min2(c,d));  }
	
int main()
{
	int N,T=0;
	while(1)
	{
		cin >> N;
		
		if(N==0)
			break;

		T++;	

		LL **dp,a;
		dp = (LL **)malloc(2*sizeof(LL *));
		dp[0] = (LL *)malloc(4*sizeof(LL));
		dp[1] = (LL *)malloc(4*sizeof(LL));

		dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;

		cin >> a;
		dp[1][1] = INT_MAX;

		cin >> a;
		dp[1][2] = a;

		cin >> a;
		dp[1][3] = a + dp[1][2];

//		cout << dp[1][1] << " " << dp[1][2] << " " << dp[1][3] << endl;
				
		for(int i=2;i<=N;i++)
		{
			dp[i%2][0] =0;

			cin >> a;
			dp[i%2][1] = min2(dp[(i-1)%2][1],dp[(i-1)%2][2]) + a;

			cin >> a;
			dp[i%2][2] = min4(dp[(i-1)%2][1],dp[(i-1)%2][2],dp[(i-1)%2][3],dp[i%2][1]) + a;
			
			cin >> a;
			dp[i%2][3] = min4(dp[(i-1)%2][2],dp[(i-1)%2][3],dp[i%2][2],INT_MAX) + a;

//			cout << dp[i%2][1] << " " << dp[i%2][2] << " " << dp[i%2][3] << endl;
		}
		cout << T << ". " << dp[N%2][2] << endl;
	
	}
	return 0;
}
