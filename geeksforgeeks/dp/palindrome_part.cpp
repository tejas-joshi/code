//===== MINIMUM PARTITION TO MAKE SO THAT EACH PARTITION WILL BE PALINDROME

/*
Given a string, count minimum no. of partition so that each partition will be palindrome.

ababbbabbababa	=> 3 ( a|babbbab|b|ababa )

Logic:

Use the same logic as matrix chain multiplication.
If you didnt refer that problem then first do it then do this problem.

Logic is explained in comments. It is the same as matrix chain multiplication.
But only thing different is limit of loop.. In that problem we started with 1.. because of matrix.
Here we will start from 0.
Read the code very carefully... 

TC : O(n^3)
SC : O(n^2)
*/

#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	
	/* Create two arrays to build the solution in bottom up manner
          cut[i][j] = Minimum number of cuts needed for palindrome partitioning
          of substring s[i..j]
          isPal[i][j] = true if substring s[i..j] is palindrome, else false
          Note that cut[i][j] is 0 if isPal[i][j] is true */

	int **cut;
	bool **isPal;
	cut = new int*[len];
	isPal = new bool*[len];
	for(int i=0;i<len;i++)
	{
		cut[i] = new int[len];
		isPal[i] = new bool[len];
	}

	// Every substring of length 1 is a palindrome
	for(int i=0;i<len;i++)
	{
		cut[i][i]=0;
		isPal[i][i] = true;
	}

	/* L is substring length. Build the solution in bottom up manner by
	          considering all substrings of length starting from 2 to n.
	*/
	for(int L=2;L<=len;L++)
	{
		for(int i=0;i<=len-L;i++)
		{
			int j=i+L-1;
			
			// If L is 2, then we just need to compare two characters. Else
                        // need to check two corner characters and value of P[i+1][j-1]
			if(L==2)
				isPal[i][j] = (s[i]==s[j]);
			else
				isPal[i][j] = (s[i]==s[j]) && isPal[i+1][j-1];

			if(isPal[i][j])	// Palindrome so no cut 
				cut[i][j]=0;
			else
			{
				cut[i][j] = INT_MAX;
				// Make a cut at every possible localtion starting from i to j,
				// and get the minimum cost cut.
				for(int k=i;k<j;k++)
					cut[i][j] = min(cut[i][j],cut[i][k] + cut[k+1][j] + 1);
			}
		}
	}
	cout << cut[0][len-1] << endl;

	return 0;
}
