/************ LONGEST COMMON SUBSTRING.
str1 and str2 are two strings.
m - length of str1, n - length of str2

	if(str1[i]==str[j])
		dp[i][j] = 1 + dp[i-1][j-1];
	else
		dp[i][j] = 0;

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
* We can print the string also using the same array.
* We just need to remember i at which we have got maximum length L.
* Then we can just print the substring of length L ending at i.

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
				dp[i%2][j] = 0;
			if(dp[i%2][j]>lcslen)
				lcslen = dp[i%2][j]; // We can store the index in case we want to print the substring
		}
	}
	cout << lcslen << endl;
		
	return 0;
}

