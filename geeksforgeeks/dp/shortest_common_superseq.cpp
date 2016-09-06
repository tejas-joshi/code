/************ Shortest Common Supersequence

Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"

This problem is closely related to longest common subsequence problem. Below are steps.

1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”.

2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. 
So “ek” becomes “geeke” which is shortest common supersequence.

Let us consider another example, str1 = “AGGTAB” and str2 = “GXTXAYB”. LCS of str1 and str2 is “GTAB”. 
Once we find LCS, we insert characters of both strings in order and we get “AGXGTXAYB”



FIND THE LENGTH:
===============
* Use only 2 1-D array for dp. (Size : 2x(n+1) ) because we need elements of the previous row.
* When dp[i][j] = i when j=0
					  = j when i=0
					  = 1 + dp[i-1][j-1]   (we need to add only one char because it is same in both the strings)
					  = 1 + min(dp[i-1][j],dp[i][j-1])  (we need to add one char from any of the strings and find the rest of the combination with min length)

TC : O(mn)	
SC : O(min(m,n)) 

FIND THE STRING FOR LCS:
=======================
* HERE YOU MUST HAVE WHOLE dp TABLE FOR BUILDING LCS string.
* FILL THE dp TABLE BY THE GIVEN FORMULA.
*
* START FROM dp[m][n].
* Check [i-1][j],[i-1][j-1] and [i][j-1].
* TODO :::: Implement the logic and write the logic here
	
* This will print reverse string because we are backtracking from back.

TC : O(mn)	
SC : O(mn) 

*************/
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int max(int a,int b)
{	return (a>b)?a:b;	}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();

	int **dp;
	dp = (int **)malloc(2*sizeof(int *));
	dp[0] = (int *)malloc((len2+1)*sizeof(int));
	dp[1] = (int *)malloc((len2+1)*sizeof(int));

	// DONT FORGET TO SET THE INITIAL VALUES...
	for(int i=0;i<=len2;i++)
		dp[0][i] = i;
	dp[1][0] = 1;

	// THIS NEEDS ONLY 2 1-D ARRAY BECAUSE WE ONLY NEED 3 ELEMENTS FOR dp[i][j]
	// dp[i-1][j-1],dp[i][j-1] and dp[i-1][j]... ALL ELEMENTS ARE AVAILABLE IN PREVIOUS ROW.
	// SO WE USE ALTERNATE ROWS EVERYTIME AND MAKE USE OF OTHER ROW TO BUILD CURRENT ONE.
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
			else
				dp[i%2][j] = 1 + min(dp[(i-1)%2][j],dp[i%2][j-1]);
		}
	}
	
	cout << dp[len1%2][len2] << endl;

	// This table is for finding the LCS. Here please modify this code to print the supersequence.
/*
  	// THIS STORES THE WHOLE dp TABLE SO SPACE WILL BE O(mn).
	// m = length of string1, n = length of string2
  
	int **dp;
	dp = (int **)malloc((len1+1)*sizeof(int *));
	for(int i=0;i<=len1;i++)
		dp[i] = (int *)malloc((len2+1)*sizeof(int));

	for(int i=0;i<=len1;i++)
		dp[i][0] = 0;
	for(int i=0;i<=len2;i++)
		dp[0][i] = 0;
	
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
*/

/*
	// PRINTING LCS STRING
	// NOTE : TO PRINT THE STRING, WE MUST HAVE WHOLE dp TABLE.
 
	int i=len1,j=len2;
	while(i>0 && j>0)
	{
		if(dp[i][j]!=dp[i-1][j-1] && dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1])
			{	cout << s1[i-1] << " "; i--; j--;  }
		else if(dp[i][j]==dp[i-1][j])
			i--;
		else
			j--;	
	}
*/
		
	return 0;
}

