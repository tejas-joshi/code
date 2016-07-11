// Print list items containing all characters of a given word

/*
There is a list of items. Given a specific word, 
e.g., “sun”, print out all the items in list which contain all the characters of “sun”

For example if the given word is “sun” and the items are “sunday”, “geeksforgeeks”, “utensils”, “”just” and “sss”, 
then the program should print “sunday” and “utensils”.

Logic :

We initially maintain the freq for the string we are checking to each item.

We check the frequency for each item in the list.
If it contains the print the item
*/

#include<iostream>
#include<string.h>
#define MAX_CHARS 256
using namespace std;

// returns true if all the chars of strCheck contains in strItems
bool containsWord(char *strItem,char *strCheck,int *countCheck)
{
	// hasFound will have the freq of char of item string if the char is there in strCheck
	int hasFound[MAX_CHARS] = {0};
	
	int lenItem = strlen(strItem);
	int lenCheck = strlen(strCheck);
	
	// count is to maintain how many chars of strCheck found in strItem.
	int count=0;
	
	for(int i=0;i<lenItem;i++)
	{
		// to ignore the char which is not there in strCheck
		if(countCheck[strItem[i]]==0)
			continue;
		
		hasFound[strItem[i]]++;
		
		// increment count only if the char in hasFound is met the consraints
		if(hasFound[strItem[i]]<=countCheck[strItem[i]])
			count++;
		
		// found all the chars in strItem so return true	
		if(count==lenCheck)
			return true;
	}
	return false;	
}

void fillCount(char *str,int *countCheck)
{
	while(*str)
	{
		countCheck[*str]++;
		str++;
	}
}

void printAllValidItems(char *items[],char *str,int lenList)
{
	int countCheck[MAX_CHARS] = {0};
	
	// fills thee char freq for the chars in the str
	fillCount(str,countCheck);
	
	while(lenList--)
		if(containsWord(items[lenList],str,countCheck))
			cout << items[lenList] << endl;
}

int main()
{
	char str[] = "sun";
	char *list[] = {"geeksforgeeks", "unsorted", "sunday", "just", "sss" };
	printAllValidItems(list,str,5);
	return 0;
}
