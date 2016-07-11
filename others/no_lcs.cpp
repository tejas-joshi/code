//======== FIND NUMBER OF STRINGS WITH LCS LENGTH
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
	for(int i=0;i<(len1+1);i++)
		dp[i] = new int[len2+1];

	// BUILDING LCS LENGTH TABLE .. NORMAL
	for(int i=0;i<(len1+1);i++)
		for(int j=0;j<(len2+1);j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else
			{
				if(s1[i-1]==s2[j-1])
					dp[i][j] = 1 + dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);	
			}
		}
	
	// LENGTH OF LCS	
	cout << "length of LCS : " << dp[len1][len2] << endl;
	int **dpL;
	dpL = new int*[len1+1];
	for(int i=0;i<(len1+1);i++)
		dpL[i] = new int[len2+1];
	
	// BUILDING THE TABLE FOR NO. STRINGS WITH LCS...
	for(int i=0;i<(len1+1);i++)
		for(int j=0;j<(len2+1);j++)
			if(i==0 || j==0)
				dpL[i][j] = 1;
			else
			{	
				dpL[i][j]=0;
				if(s1[i-1]==s2[j-1])
					dpL[i][j] = dpL[i-1][j-1];
				else
				{
					if(dp[i][j]==dp[i-1][j])
						dpL[i][j] = dpL[i][j] + dpL[i-1][j];
					if(dp[i][j]==dp[i][j-1])
						dpL[i][j] = dpL[i][j] + dpL[i][j-1];
					if(dp[i][j]==dp[i-1][j-1])
						dpL[i][j] = dpL[i][j] - dpL[i-1][j-1];
				}
			}

	cout << dpL[len1][len2] << endl;

	return 0;
}
