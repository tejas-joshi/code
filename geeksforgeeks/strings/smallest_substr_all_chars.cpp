// Finding the Minimum Window in S which Contains All Elements from T

/*
To help illustrate this approach, I use a different example: S = “acbbaca” and T = “aba“. 
The idea is mainly based on the help of two pointers (begin and end position of the window) and two tables (needToFind and hasFound) while traversing S. 
needToFind stores the total count of a character in T and hasFound stores the total count of a character met so far. 
We also use a count variable to store the total characters in T that’s met so far (not counting characters where hasFound[x] exceeds needToFind[x]). 
When count equals T‘s length, we know a valid window is found.

Each time we advance the end pointer (pointing to an element x), we increment hasFound[x] by one. 
We also increment count by one if hasFound[x] is less than or equal to needToFind[x]. Why? 
When the constraint is met (that is, count equals to T‘s size), 
we immediately advance begin pointer as far right as possible while maintaining the constraint.

How do we check if it is maintaining the constraint? 
Assume that begin points to an element x, we check if hasFound[x] is greater than needToFind[x]. 
If it is, we can decrement hasFound[x] by one and advancing begin pointer without breaking the constraint. 
On the other hand, if it is not, we stop immediately as advancing begin pointer breaks the window constraint.

Finally, we check if the minimum window length is less than the current minimum. Update the current minimum if a new minimum is found.

TC : O(n)
SC : O(1)  // array of size 256

*/
#include<iostream>
#include<string.h>
#define MAX_CHARS 256

using namespace std;

// to fill the count of strSub character freq.
void fillCount(int *count,char *str)
{
	while(*str)
	{
		count[*str]++;
		str++;
	}
}

// Returns false if no valid window is found. Else returns
// true and updates beginW and endW with the
// starting and ending position of the minimum window.
bool getWindow(char *strMain,char *strSub,int &beginW,int &endW)
{
	int needToFind[MAX_CHARS] = {0};
	int hasFound[MAX_CHARS] = {0};
	int lenMain = strlen(strMain);
	int lenSub = strlen(strSub);

	int begin,end,len;
	int minLen = lenMain+1;
	int count=0;
	
	fillCount(needToFind,strSub);
	
	for(begin=0,end=0;end<lenMain;end++)
	{
		// skip characters not in strSub
		if(needToFind[strMain[end]]==0)
			continue;
		
		hasFound[strMain[end]]++;
		
		if(hasFound[strMain[end]]<=needToFind[strMain[end]])
			count++;
		
		// if window constraint is satisfied
		if(count==lenSub)
		{
			// advance begin index as far right as possible,
			// stop when advancing breaks window constraint.
			while(needToFind[strMain[begin]]==0 || hasFound[strMain[begin]] > needToFind[strMain[begin]])
			{
				if(hasFound[strMain[begin]] > needToFind[strMain[begin]])
					hasFound[strMain[begin]]--;
				begin++;
			}			
			
			// update window if a minimum length is met
			len = end - begin + 1;
			if(len < minLen)
			{
				beginW = begin;
				endW = end;
				minLen = len;
			}
		}
	}	
	return (count==lenSub);
}


int main()
{
	char strMain[100],strSub[100];
	int ansBegin,ansEnd;

	cin >> strMain;
	cin >> strSub;	

	if(getWindow(strMain,strSub,ansBegin,ansEnd))
		cout << ansBegin << " " << ansEnd << endl;
	else
		cout << "window doesnt exist" << endl;
	
	return 0;
}
