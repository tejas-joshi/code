// COUNT THE WORDS IN THE STRING

/*
Given a string, count number of words in it. 
The words are separated by following characters: space (‘ ‘) or new line (‘\n’) or tab (‘\t’) or a combination of these.

isLastWord is to maintain the state of the last character seen.
If it is false means state is not word because of ' ' OR '\n' OR '\t'
If it is true means state is word.

Word count is incremented when we find some other character except (' ' OR '\n' OR '\t') and isLastWord is false
*/

#include<iostream>
using namespace std;

int countWords(char *str)
{
	bool isLastWord = false;
	int wordCount = 0;
	
	while(*str)
	{
		if(*str==' ' || *str=='\n' || *str=='\t')
			isLastWord = false;
		else if(!isLastWord)
		{
			isLastWord = true;
			wordCount++;
		}
		str++;
	}
	return wordCount;
}

int main()
{
	char str[] = "One two          three\n  four\nfive  ";
	cout << countWords(str) << endl;
	return 0;
}
