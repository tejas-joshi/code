////=========== Shortest Superstring Problem
/*
Given a set of n strings arr[], find the smallest string that contains each string in the given set as substring. 
We may assume that no string in arr[] is substring of another string.

Input:  arr[] = {"geeks", "quiz", "for"}
Output: geeksquizfor

Input:  arr[] = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"}
Output: gctaagttcatgcatc

arr[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"}
Initialize:
temp[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"}

The most overlapping strings are "catgc" and "atgcatc"
(Suffix of length 4 of "catgc" is same as prefix of "atgcatc")
Replace two strings with "catgcatc", we get
temp[] = {"catgcatc", "ctaagt", "gcta", "ttca"}

The most overlapping strings are "ctaagt" and "gcta"
(Prefix of length 3 of "ctaagt" is same as suffix of "gcta")
Replace two strings with "gctaagt", we get
temp[] = {"catgcatc", "gctaagt", "ttca"}

The most overlapping strings are "catgcatc" and "ttca"
(Prefix of length 2 of "catgcatc" as suffix of "ttca")
Replace two strings with "ttcatgcatc", we get
temp[] = {"ttcatgcatc", "gctaagt"}

Now there are only two strings in temp[], after combing
the two in optimal way, we get tem[] = {"gctaagttcatgcatc"}

Since temp[] has only one string now, return it.

*/


#include<iostream>
#include<limits.h>
using namespace std;

int findMaxMatch(string s1, string s2, string &superString)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int maxMatch=0;
	
	// finding the overlapping of (s1,s2)
	for(int i=0;i<len1;i++)
	{
		if(s1.compare(i,len1-i,s2,0,len1-i)==0 && (len1-i)>maxMatch)
		{
			maxMatch = (len1-i);
			superString = s1 + s2.substr(len1-i);
		}
	}
	
	// finding the overlapping of (s2,s1)
	for(int i=0;i<len2;i++)
	{
		if(s2.compare(i,len2-i,s1,0,len2-i)==0 && (len2-i)>maxMatch)
		{
			maxMatch = (len2-i);
			superString = s2 + s1.substr(len2-i);
		}
	}
	return maxMatch;
}

string findSS(string arr[],int n)
{
	int remStrings=n;
	int i,j;
	while(remStrings>1)
	{
		int maxMatch = -1;
		int first,second;
		string currSuperString,superString;
		for(i=0;i<remStrings-1;i++)
		{
			for(j=i+1;j<remStrings;j++)
			{
				int currMaxMatch=findMaxMatch(arr[i],arr[j],currSuperString);
				if(currMaxMatch>maxMatch)
				{
					first=i;
					second=j;
					maxMatch = currMaxMatch;
					superString = currSuperString;
				}
			}
		}
		
		// Everytime we replace the result to first string of the pair and replace the second with the last string in the current loop.
		arr[first]=superString;
		arr[second]=arr[remStrings-1];
		remStrings--;
	}
	return arr[0];
}


int main()
{
    string arr[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << findSS(arr, len) << endl;
    return 0;
}