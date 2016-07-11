#include<iostream>
#include<string>

#define debug(x) cout << x << " ";
#define fr(x,s,e) for(int x=s;x<e;x++)
#define fr_rev(x,s,e) for(int x=s;x>=e;x--)

using namespace std;
int main()
{
	string s;
	cin >> s;

	int maxLen,sInd;
	int l = s.length();	
	bool dp[100][100] = {false};

	maxLen = 1;
	sInd = l-1;
	for(int i=0;i<l;i++)
		dp[i][i] = true;
	

	for(int i=0;i<l-1;i++)
		if(s[i]==s[i+1])
		{
			sInd = i;
			maxLen = 2;
			dp[i][i+1] = true;
		}			

	int j;
	for(int len=3;len<=l;len++)
	{
		for(int i=0;i<l-len+1;i++)
		{
			j = i+len-1;
			if(s[i]==s[j] && dp[i+1][j-1])
			{
				maxLen = len;
				sInd = i;
				dp[i][j] = true;
			}
		}
	}

	cout << "start index : " << sInd << " length : " << maxLen << endl;
	
	return 0;
}
