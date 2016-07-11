// Lexicographic rank of a string

/*

FIRST CHECK OUT THE PROGRAM TO PRINT ALL THE PERMUTATIONS IN LEXICOGRAPHICALLY SORTED.
SO THAT YOU CAN UNDERSTAND THIS PROBLEM VERY EASILY...

Given a string, find its rank among all its permutations sorted lexicographically. 
For example, rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6. 

Let the given string be “STRING”. In the input string, ‘S’ is the first character. 
There are total 6 characters and 4 of them are smaller than ‘S’. 
So there can be 4 * 5! smaller strings where first character is smaller than ‘S’, like following

R X X X X X
I X X X X X
N X X X X X
G X X X X X

Now let us Fix S’ and find the smaller strings staring with ‘S’.

Repeat the same process for T, rank is 4*5! + 4*4! +…

Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…

Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…

Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…

Now fix N and repeat the same process for G, rank is 4*5! + 4*4 + 3*3! + 1*2! + 1*1! + 0*0!

Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597

Since the value of rank starts from 1, the final rank = 1 + 597 = 598

TO HANDLE THE DUPLICATES IN THE STRING
======================================
This program doesn’t work for duplicate characters. 
To make them work for duplicate characters, find all the characters that are smaller (include equal this time also), 
do the same as above but, this time divide the rank so formed by p! where p is the count of occurrences of the repeating character.

*/

#include<iostream>
#include<string.h>
#define MAX_CHARS 256
using namespace std;


// to find the n!
int fact(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
		ans = ans * i;
	return ans;
}

void updateCount(int *count,char *str)
{
	// to set the frequency of the characters in the string
	while(*str)
	{
		count[*str]++;
		str++;
	}
	
	// this is to update the count value such that count[i] will have number of characters in the string 
	// which is less than or equals to current character.
	for(int i=1;i<MAX_CHARS;i++)
		count[i] = count[i] + count[i-1];
}

// we have considered character ch so we have to decrement all the values after ch
// because ch was included in the values after ch in the count array
void decrementCount(int *count,int ch)
{
	for(int c=ch;c<MAX_CHARS;c++)
		count[c]--;
}

int lexicOrder(char *str)
{	
	int count[MAX_CHARS] = {0};
	updateCount(count,str);
	
	// to set the current values
	int rank = 1;
	
	// now we will find number of strings which is less than str in lexicographical ascending order
	
	int len = strlen(str);
	int mul = fact(len);

	// now mul is n!  (consider n as len)
	// on each term the fact value is decrementing by 1. so we find n! once and then divide by n on each iteration.
	
	for(int i=0;i<len;i++)
	{
		mul = mul/(len-i);
		
		// count[str[i]-1] will have number of chars which is less than str[i] from the remaining chars in the string 
		rank = rank + mul*count[str[i]-1];
		
		decrementCount(count,str[i]);
	}	
	return rank;
}

int main()
{
	char str[100];
	cin >> str;
	cout << lexicOrder(str) << endl;
	
	return 0;	
}
