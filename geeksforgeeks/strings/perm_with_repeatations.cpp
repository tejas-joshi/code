// PRINT ALL THE PERMUTATIONS OF THE STRING WITH REPEATATIONS

/*
Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order
Examples:

Input: AB
Ouput: All permutations of AB with repeatition are:
      AA
      AB
      BA
      BB

Input: ABC
Output: All permutations of ABC with repeatition are:
       AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC


1) For an input string of size n, there will be n^n permutations with repetition allowed. 
2) The idea is to fix the first character at first index and recursively call for other subsequent indexes. 
3) Once all permutations starting with the first character are printed, fix the second character at first index. 
4) Continue these steps till last character.

							data="" 
                          /         \
                         /           \ 
                   index=0           index=0
                    i=0               i=1 
                  data="A"           data="B"
                   /   \              /    \
                 /      \            /      \
              index=1  index=1    index=1    index=1 
               i=0      i=1        i=0        i=1 
            data="AA"  data="AB"  data="BA"  data="BB"


*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int compare(const void *a,const void *b)
{
	return (*(char *)a)-(*(char *)b);	
}

// ind is maintaining the index for the resultant string of permutation
// str is the original string
// strAns is the string for answer of permutation
// len is length of string
void printAllPermutationWithRepeatations(char *str,char *strAns,int len,int ind)
{
	if(ind==len) // we have reached the length so print the permutation
		cout << strAns << endl;
	else
		for(int i=0;i<len;i++)		// here we have to consider whole string for each character in the permutation
		{
			strAns[ind] = str[i];
			printAllPermutationWithRepeatations(str,strAns,len,ind+1);
		}
}

int main()
{
	char str[100];
	cin >> str;

	int l = strlen(str);	
	char *strAns = new char[l+1];		
	
	// sorts the string to make it lexicographically sorted
	qsort(str,l,sizeof(char),compare);

	printAllPermutationWithRepeatations(str,strAns,strlen(str),0);
	return 0;
}
