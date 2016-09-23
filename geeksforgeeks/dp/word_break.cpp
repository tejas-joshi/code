/************ Word Break Problem
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words.
Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

The idea is simple, we consider each prefix and search it in dictionary. 
If the prefix is present in dictionary, we continue for rest of the string (or suffix).

TC : O(len^2)
SC : O(len)

*************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

bool wordBreak(string s)
{
	int len = s.length();
	if(len==0)
		return true;
	
	bool wb[len+1];
	memset(wb,0,sizeof(wb));
	
	// Create the DP table to store results of subroblems. The value wb[i]
    // will be true if str[0..i-1] can be segmented into dictionary words,
    // otherwise false.
	for(int i=1;i<=len;i++)
	{
		// if wb[i] is false, then check if current prefix can make it true.
        // Current prefix is "str.substr(0, i)"
		if(wb[i]==false && dictionaryContains(s.substr(0,i)))
			wb[i] = true;
	
		// wb[i] is true, then check for all substrings starting from
        // (i+1)th character and store their results.
		if(wb[i])
		{
			if(i==len)
				return true;
			// Update wb[j] if it is false and can be updated
			// Note the parameter passed to dictionaryContains() is
			// substring starting from index 'i' and length 'j-i'
			for(int j=i+1;j<=len;j++)
			{
				if(wb[j]==false && dictionaryContains(s.substr(i,j-i)))
					wb[j] = true;
				if(wb[j] && j==len)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	cout << wordBreak(s) << endl;
	return 0;
}

