// LONGEST SUBSTRING WITH UNIQUE CHARACTERS

/*

Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. 
For “BBBB” the longest substring is “B”, with length 1. 
For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7. 

Logic :

1) Take an int array for maintaining the index of each character last seen at.
	currLen is the length we are maintaining for current pass.

2) If the character last seen is out of the range then we update index for that character
   If the character is seen for the first time then we also do the same. 

3) If the index is in the range then we set currLen = (i-visited[str[i]]) because we cant consider both characters anyway in the length.
   and update the index for that character.

4) Compare each time with maxLen


TC : O(n)
SC : O(1)    // CONSTANT SPACE ARRAY OF SIZE 256


In case you want to print the string, maintain start and end index where you find the maxLen.
and print the substring between those indexes.

*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string str;
	int visited[256];
	int maxLen=-1,currLen=0;
	
	// setting all the values to -1
	for(int i=0;i<256;i++)
		visited[i] = -1;
	
	cin >> str;
	int len = str.length();
	
	for(int i=0;i<len;i++)
	{
		if(visited[str[i]]==-1 || visited[str[i]]<(i-currLen))	// if the character is first seen OR it is out of the range from the length we are considering
			currLen++;
		else                                        // if the character is in the range length we are considering
			currLen = (i-visited[str[i]]);
		visited[str[i]] = i;					// setting the index for the current character
		
		if(currLen>maxLen)			// comparing with max
			maxLen = currLen;
	}
	
	cout << maxLen << endl;
	
	return 0;
}
