// FIND THE LONGEST PALINDROMIC SUBSTRING

/*
For example, if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”.

The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.

Step to generate odd length palindrome:
Fix a centre and expand in both directions for longer palindromes.

Step to generate even length palindrome
Fix two centre ( low and high ) and expand in both directions for longer palindromes.

TC : O(n^2)
SC : O(1)

*/

#include<iostream>
#include<string.h>
using namespace std;

void findLPS(char *str,int &startInd,int &maxLen)
{
	int len = strlen(str);
	if(len==0)
	{
		startInd = -1;
		maxLen = 0;
		return;
	}
	
	startInd = 0;
	maxLen = 1;
	
	int low,high;
	for(int i=1;i<len;i++)
	{
		low = i-1;
		high = i;
		
		// finding the palindromes of even length
		while(low>=0 && high<len && str[low]==str[high])
		{
			if(high-low+1 > maxLen)
			{
				startInd = low;
				maxLen = high - low +1;
			}
			low--;
			high++;
		}	
		
		low = i-1;
		high = i+1;
		
		// finding the palindromes of odd length
		while(low>=0 && high<len && str[low]==str[high])
		{
			if(high-low+1 > maxLen)
			{
				startInd = low;
				maxLen = high - low +1;
			}
			low--;
			high++;
		}	
	}
}

int main()
{
	char str[100];
	cin >> str;
	
	int start,len;
	findLPS(str,start,len);
	cout << start << " " << len << endl;
	return 0;
}
