/************ LONGEST COMMON SUBSEQUENCE.
str1 and str2 are two strings.
m - length of str1, n - length of str2

	if(str1[i]==str[j])
		dp[i][j] = 1 + dp[i-1][j-1];
	else
		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

FIND THE LENGTH:
===============
* Use only 2 1-D array for dp. (Size : 2x(n+1) ) because we need elements of the previous row.
* 	where n is length of string2.	You can also take the length of other string.
* 	If you want for minimum space then use [2][min(m,n)] array.
* Use rows alternatively by (i%2) by using (i-1)%2 as previous row. 
* Make first row and first column 0.

TC : O(mn)	
SC : O(min(m,n)) 

FIND THE STRING FOR LCS:
=======================
* HERE YOU MUST HAVE WHOLE dp TABLE FOR BUILDING LCS string.
* FILL THE dp TABLE BY THE GIVEN FORMULA.
*
* START FROM dp[m][n].
* Check [i-1][j],[i-1][j-1] and [i][j-1].
* 	If they are same then it is sure that character got matched.
	 	Print str1[i-1] or str2[j-1]
	Else
		It is sure that dp[i][j] is same as either dp[i-1][j] or dp[i][j-1] BUT NOT BOTH.
		Wherever it is repeating go that side.
		i.e. If dp[i][j]==dp[i-1][j] then go above (i--)
			 else go left (j--)
		Repeat this till (i>0) and (j>0) satisfies.
	
* This will print reverse string because we are backtracking from back.
* Store it in stack or somewhere else and print reverse.

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
		dp[0][i] = 0;
	dp[1][0] = 0;
	int lcslen=0;

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
				dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
			if(dp[i%2][j]>lcslen)
				lcslen = dp[i%2][j];
		}
	}
	cout << lcslen << endl;
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
	// PRINTING dp TABLE
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
			cout << dp[i][j] << " ";
		cout << endl;
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
//	PRINTING LENGTH OF LCS
//	cout << dp[len1-1][len2-1] << endl;
		
	return 0;
}

