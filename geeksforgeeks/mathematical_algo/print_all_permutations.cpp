// PRINT ALL THE PERMUTAION OF THE STRING/ARRAY...

// Logic is in the comments...

// THIS PERMUTATION ARE NOT LEXICOGRAPHICALLY SORTED...
// FOR THAT YOU HAVE TO APPLY DIFFERENT LOGIC.
// THE SOLUTION FOR THIS PROBLEM IS IN THE strings SECTION.

// TC : O(n*n!)
#include<iostream>
#include<string.h>
using namespace std;

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

// start and end indicates the range of the permutation that is going to be done...
void printPerm(char *s,int start,int end) 	
{
	if(start==end)
		cout << s << endl;
	else
	{
		for(int j=start;j<=end;j++)// first iteration keeps the string as it is but afterwards it is replacing with other elements and 
						// continue the permutation for the rest of the elements..
		{
			swap(s+start,s+j);	// swaps start and jth element
			printPerm(s,start+1,end);
			swap(s+start,s+j);	// swaps start and jth element which will keep the original string as it is.. 
						// and for the next iteration the next j will be used for replacement...
		}
	}
}	

int main()
{
	char s[100];
	cin >> s;
	printPerm(s,0,strlen(s)-1);
	return 0;
}
