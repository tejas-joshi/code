// PRINT ALL THE PERMUTAIONS WHICH ARE LEXICOGRAPHICALLY SORTED

/*

Given a string, print all permutations of it in sorted order. 
For example, if the input string is “ABC”, then output should be “ABC, ACB, BAC, BCA, CAB, CBA”.

Following are the steps to print the permutations lexicographically

1. Sort the given string in non-decreasing order and print it. 
	The first permutation is always the string sorted in non-decreasing order.

2. Start generating next higher permutation. 
	Do it until next higher permutation is not possible. 
	If we reach a permutation where all characters are sorted in non-increasing order, then that permutation is the last permutation.

Steps to generate the next higher permutation:

1. Take the previously printed permutation and find the rightmost character in it, which is smaller than its next character. 
	Let us call this character as ‘first character’.

2. Now find the ceiling of the ‘first character’. 
	Ceiling is the smallest character on right of ‘first character’, which is greater than ‘first character’. 
	Let us call the ceil character as ‘second character’.

3. Swap the two characters found in above 2 steps.

4. Sort the substring (in non-decreasing order) after the original index of ‘first character’.
	Here you just have to reverse the substring because the substring is always sorted in descending order.

Let us consider the string “ABCDEF”. Let previously printed permutation be “DCFEBA”. 
The next permutation in sorted order should be “DEABCF”. 
Let us understand above steps to find next permutation. 
The ‘first character’ will be ‘C’. The ‘second character’ will be ‘E’. 
After swapping these two, we get “DEFCBA”. 
The final step is to sort the substring after the character original index of ‘first character’. 
Finally, we get “DEABCF”.

Logic is explained in the code also.

TC : O(n*n!)

TO HANDLE THE DUPLICATE PERMUTATIONS
====================================
This program prints duplicate permutation when characters are repeated. 
We can avoid it by keeping track of the previous permutation. 
While printing, if the current permutation is same as previous permutation, we won’t print it.

*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

// COMPARE FUNCTION USED IN SORTING
int compare(const void *a,const void *b)
{
	return (* (char *)a)-(* (char *)b);
}

// LOGIC FOR SWAPPING
void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sortByReverseStr(char *str,int len)
{
	for(int i=0,j=len-1;i<(len/2);i++,j--)
		swap(&str[i],&str[j]);
}

// returns the next higher permutation of the string.. if it is not possible then returns NULL
char *nextHigherPermutation(char *str)
{
	int len = strlen(str);
	
	// finding the place where current char is smaller than next char from the right side
	int i = len-2;
	while(i>=0 && str[i]>=str[i+1])
		i--;

	// we didnt find any character because the string is sorted in decreasing order... so return NULL		
	if(i==-1)
		return NULL;
	
	// finding the ceiling of str[i]
	int j;
	for(j=i+1;j<len;j++)
		if(str[j]<str[i])
		{
			j--;
			break;
		}

	// all the characters are greater than str[i] so str[len-1] will be ceiling of str[i]	
	if(j==len)
		j--;
	
	// swaps str[i] and str[j]
	swap(&str[i],&str[j]);
	
	// sort the string starts from str[i+1] to str[len-1]
	// Here the substring is always sorted in descending order so just reverse the string to sort it in ascending order.
	sortByReverseStr(str+(i+1),len-(i+1));
		
	return str;	
}

void printAllPermLex(char *str)
{
	// prints the lexicographically sorted permutation till we find the next one.
	while(str)
	{
		cout << str << endl;
		str = nextHigherPermutation(str);
	}
}

int main()
{
	char str[100];
	cin >> str;
	
	// first sort the string
	qsort(str,strlen(str),sizeof(char),compare);

	printAllPermLex(str);
	
	return 0;
}
