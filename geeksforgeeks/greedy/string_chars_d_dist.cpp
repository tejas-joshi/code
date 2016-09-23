////=========== Rearrange a string so that all same characters become d distance away6
/*
Given a string and a positive integer d. Some characters may be repeated in the given string. 
Rearrange characters of the given string such that the same characters become d distance away from each other. 
Note that there can be many possible rearrangements, the output should be one of the possible rearrangements.

Input:  "abb", d = 2
Output: "bab"

Input:  "aacbbc", d = 3
Output: "abcabc"

Input: "geeksforgeeks", d = 3
Output: egkegkesfesor

Input:  "aaa",  d = 2
Output: Cannot be rearranged

The idea is to count frequencies of all characters and consider the most frequent character first and place all occurrences of it as close as possible. 
After the most frequent character is placed, repeat the same process for remaining characters.

1) Let the given string be str and size of string be n

2) Traverse str, store all characters and their frequencies in a Max Heap MH. 
	The value of frequency decides the order in MH, i.e., the most frequent character is at the root of MH.

3) Make all characters of str as ‘\0′.

4) Do following while MH is not empty.
…a) Extract the Most frequent character. Let the extracted character be x and its frequency be f.
…b) Find the first available position in str, i.e., find the first ‘\0′ in str.
…c) Let the first position be p. Fill x at p, p+d,.. p+(f-1)d

TC : O(n + mLogm). Here n is the length of str, m is count of distinct characters in str[] and MAX is maximum possible different characters. MAX is typically 256 (a constant) and m is smaller than MAX. So the time complexity can be considered as O(n).
SC : O(m) // queue size

*/


#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct Char_s
{
	char c;
	int freq;
	
	Char_s()
	{
		freq=0;	
	}
	
	Char_s(char C,int Freq)
	{
		c=C;
		freq=Freq;
	}
} Char;

bool operator> (const Char &l, const Char &r)
{
	return (l.freq)>(r.freq);
}

bool operator< (const Char &l, const Char &r)
{
	return (l.freq)<(r.freq);
}

ostream& operator<< (ostream &os, const Char &o)
{
	os << o.c << " : " << o.freq;
	return os;
}

struct compare  
{  
   bool operator()(const Char& l, const Char& r)  
   {  
       return l < r;  
   }  
};

bool checkValidDString(string str, int d, string &result)
{
	Char ch[256];
	
	// setting the frequence count
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		ch[str[i]].c = str[i];
		ch[str[i]].freq++;
	}
	
	// building the heap for sorting by freq
	priority_queue<Char, vector<Char>, compare> Q;
	for(int i=0;i<256;i++)
	{
		if(ch[i].freq>0)
			Q.push(ch[i]);
	}
	
	char *res;
	res = new char[len+1];
	memset(res,'\0',len+1);
	
	int nextFree=0;
	while(!Q.empty())
	{		
		// finding first free space
		while(nextFree<len && res[nextFree]!='\0')
			nextFree++;
		
		// not free space
		if(nextFree==len)
			return false;
	
		// popping most frequence char from the queue
		Char curr = Q.top();
		Q.pop();

		// setting all the occurances in the resultant string
		int j=nextFree;	
		while(j<len && curr.freq>0)	
		{
			res[j]=curr.c;
			curr.freq--;
			j=j+d;
		}
		
		// not possible to set all the occurances in the given length
		if(curr.freq>0)
			return false;
	}	
	result = string(res);
	return true;
}


int main()
{
	string str;
	cin >> str;
	
	int d;
	cin >> d;
	
	string result;
	if(checkValidDString(str,d,result))
		cout << result << endl;
	else
		cout << "Not possible" << endl;
    return 0;
}