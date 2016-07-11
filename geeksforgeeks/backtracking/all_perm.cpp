// PRINT ALL THE PERMUTATIONS OF THE STRING

// TC : o(n*n!)

// Logic :

/*
1) ind is the current index to consider.
2) if it is same as length then we have reached the end of the string
3) else
		for each char c from ind to length-1 ( both included)
			swap c and (char at ind)
			call function again with ind+1 
			swal c and (char at ind) // to get back the original string so that the next iteration get the string as it is.
*/
		
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void swap(char *c1,char *c2)
{
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void printAllPerm(char *str,int ind,int len)
{
	if(ind==len)
	{
		for(int i=0;i<len;i++)
			cout << str[i] << " ";
		cout << endl;
	}
	else
	{
		for(int i=ind;i<len;i++)
		{
			swap(&str[ind],&str[i]);
			printAllPerm(str,ind+1,len);
			swap(&str[ind],&str[i]);
		}	
	}
}

int main()
{
	char str[100];
	gets(str);
	printAllPerm(str,0,strlen(str));	
	return 0;
}
