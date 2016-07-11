/**********

Find the length of longest palindromic subsequence.
ex. BBABCBCAB => 7 (BABCBAB)

LOGIC :
* Use the same logic as LCS but consider the reverse of input string as second string.

TC : O(n^2)		n = length of string
SC : O(n)

***********/

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int l = s.length();

	// We use only two rows for dp table as it is enough to build current row.
	// calloc is used to make all the values 0. First row and first column is 0 intially.
	int *dp[2];
	dp[0] = (int *)calloc((l+1),sizeof(int));
	dp[1] = (int *)calloc((l+1),sizeof(int));

	dp[1][0]=0;	
	
	// dp table start from 1 to l.. considering the string from 0 to l-1..
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			if(s[i-1]==s[l-j])
				dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
			else
				dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);

	if(l%2==0)	// If l is odd then answer would be in first row.
		cout << dp[0][l] << endl;
	else        // If l is even then answer would be in second row. 
		cout << dp[1][l] << endl;
		
	return 0;
}
