// A Naive Pattern Searching Question

/*
Consider a situation where all characters of pattern are different. 
Modify the original Naive String Matching algorithm so that it works better for these types of patterns. 
If we can, then what are the changes to original algorithm?

Solution: 
========
In the original Naive String matching algorithm , we always slide the pattern by 1 in case of mismatch. 
* When all characters of pattern are different, we can slide the pattern by more than 1. 
* When a mismatch occurs after j matches, 
* 	we know that the first character of pattern will not match the j matched characters because all characters of pattern are different. 
* So we can always slide the pattern by j without missing any valid shifts. 

TC : O(n)
SC : O(1)

*/

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[100],pat[100];
	
	cin >> str >> pat;
	
	int lenStr = strlen(str);
	int lenPat = strlen(pat);

	int i=0,j=0;
	while(i<=(lenStr-lenPat))	
	{
		for(j=0;j<lenPat;j++)	
			if(str[i+j]!=pat[j])
				break;
		
		if(j==lenPat)	// matched
		{
			cout << "Found the match at " << i << endl;
			i=i+lenPat;
		}
		else if(j==0)     // first char is not matching so going to next char
			i++;
		else     // shift the window by j because we know that the previous chars wont match
			i=i+j;
	}

	return 0;
}
