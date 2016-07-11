#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	cin >> s1;
	cin >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	int **dp;
	dp = new int*[len1+1];
	for(int i=0;i<=len1;i++)
		dp[i] = new int[len2+1];

	for(int i=0;i<=len1;i++)
		dp[i][0] = i;
	for(int i=0;i<=len2;i++)
		dp[0][i] = i;
	
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
	cout << dp[len1][len2] << endl;
	return 0;
}
