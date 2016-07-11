//=== FIND THE LONGEST PALINDROMIC SUBSTRING

/*
Given a string find the longest palindromic substring.

Logic :

DP logic is to make
s[i..j] is palindrome if s[i]==s[j] and s[i+1...j-1] is palindrome...
Maintain the variables of length of longest palindrome substring found (maxLen)
and the start index of that substring (sInd)..

Take boolean array of l*l where l is the length of the string.
and intially make all the diagonal elements true. (dp[i][j] is true if s[i..j] is palindrome)
becuase a single character is always palindrome..
update  maxLen=1 and sInd=l-1

Now take the length as 2 for 2 length string palindrome checking..
update maxLen and sInd accordingly...

Now check for 3 to the length of the string..
Refer code for more clarity...

TC : O(n^2)
SC : O(n^2)
*/

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
	bool dp[100][100] = {false};	// DONT FORGET THIS... INITIALLY ALL THE BOOLEAN VALUES MUST BE FALSE...

	// update maxLen and sInd for 1 length palindromes
	maxLen = 1;
	sInd = l-1;
	for(int i=0;i<l;i++)
		dp[i][i] = true;
	
	// update maxLen and sInd for 2 length palindromes
	for(int i=0;i<l-1;i++)
		if(s[i]==s[i+1])
		{
			sInd = i;
			maxLen = 2;
			dp[i][i+1] = true;
		}			

	// update maxLen and sInd for 3 or more length palindromes
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

	// printing starting index of the answer and the length of that substring
	cout << "start index : " << sInd << " length : " << maxLen << endl;
	
	return 0;
}
