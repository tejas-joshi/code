/*****
 *
 * You have 4 keys to press. Each is counted as 1.
 * Ctrl+A , Ctrl+C, Ctrl+V, A
 *
 *
 * Find maximum As you can print using n steps.
 *
 *
 * dp[i] =  max (
 * 				dp[i-1] + 1  // If we press A
 * 				dp[i-3]*2    // If we press Ctrl+A,Ctrl+C,Ctrl+V... this takes 3 steps.. so it is (i-3).. duoble for paste.
					copyA = dp[i-3]	  // Here is we choose above branch we have to change copyA because clipboard value is changed.
				dp[i-1] + copyA  // copyA is maintaining the no. of A's copied in the clibboard..
									Sometimes Ctrl+A, Ctrl+C, Ctrl+V, Ctrl+V .. can give answer
				)

TC : O(n)
SC : O(1) // If we take only array of 4 elements because we only require 4 elements to get current value...


NOTE : IF YOU OBSERVE THE OUTPUT... IT IS IN THE FORMAT <i> <BRANCH TAKEN> <NO. OF As> <VALUE OF copyA> FOR EACH i...
AND YOU CAN SEE THE SERIES... EVERY 4TH STEP IT IS CHANGING THE BRANCH ELSE IT IS JUST COPIES copyA.


Here dp approach is changing its branch only on 4k+2 value (e.g. 2,6,10,14...) else it is adding the value of clipboard.
We can make the formula for this series...

ans = dp[2]*(3^((n-2)/4))
ans = ans + ((n-2)%4)*(ans/2)

TC : O(log n)... If we count power value by D&C and store method..
SC : O(1)

Both logics are implemented...

*/

int ansBySeries(int n,int dp2)
{
	int pw = (n-2)/4;
	int ansPW3=1;
		
	for(int i=0;i<pw;i++)
		ansPW3 = ansPW3*3;

	int ans  = dp2*ansPW3;		
	ans = ans + ((n-2)%4)*(ans/2);
	return ans;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,*dp;
	cin >> n;

	int copyA=0;

	dp = new int[n+1];

	dp[0]=0;
	dp[1]=1;
	dp[2]=2;

	int ans;
	for(int i=3;i<=n;i++)
	{
		int a = dp[i-1]+ copyA;
		int b = dp[i-1]+1;
		int c = dp[i-3]*2;

		cout << i << " ";
		if(a>b)
		{
			if(a>c)
			{
				ans = a;
				cout << 1 << " ";
			}
			else
			{
				cout << 3 << " ";
				ans = c;
				copyA = dp[i-3];
			}
		}
		else
		{
			if(b>c)
			{
				cout << 2 << " ";
				ans = b;
			}
			else
			{
				cout << 3 << " ";
				ans = c;
				copyA = dp[i-3];
			}
		}		
		dp[i] = ans;
		cout << ans << " " << copyA << endl; 
	}

	cout << "Answer by dp : " << dp[n] << endl;
	cout << "Answer by series : " << ansBySeries(n,dp[2]) << endl;

	return 0;
}
