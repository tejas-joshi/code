#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	int t;
	string s,sRev;
	cin >> t;
	while(t--)
	{
		int **dp;
		cin >> s;
		int l = s.length();

		dp = (int **)malloc(2*sizeof(int *));
		for(int i=0;i<=1;i++)
			dp[i] = (int *)calloc((l+1),sizeof(int));			
			
		for(int i=1;i<=l;i++)
		{	
			for(int j=1;j<=l;j++)
			{
				if(s[i-1]==s[l-j])
					dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
				else
					dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
			}
		}
		cout << l-dp[l%2][l] << endl;
	}
	return 0;
}
