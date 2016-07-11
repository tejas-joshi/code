// PRINT ALL THE INTERLEAVINGS OF TWO STRINGS

/*
Input: str1 = "AB",  str2 = "CD"
Output:
    ABCD
    ACBD
    ACDB
    CABD
    CADB
    CDAB

TC : // FIND THE TIME COMPLEXITY

FIND NUMBER OF INTERLEAVINGS POSSIBLE FROM TWO STRINGS.
F(L1,L2) = F(L1-1,L2) + F(L1,L2-1)

*/

#include<iostream>
#include<string.h>
using namespace std;

void printAllInterleavings(char *str1,char *str2,int indStr1,int indStr2,int len1,int len2,char *strAns,char ind)
{
	if(indStr1>=len1 && indStr2>=len2)	//  if both the strings are exhausted
	{
		cout << strAns << endl;
		return;
	}
	
	// HERE WE HAVE TWO OPTIONS .. TAKING CHARACTER FROM FIRST STRING OR SECOND STRING
	
	if(indStr1<len1)	// taking the character from first string
	{
		strAns[ind] = str1[indStr1];
		printAllInterleavings(str1,str2,indStr1+1,indStr2,len1,len2,strAns,ind+1);
	}
	
	if(indStr2<len2)	// taking character from second string
	{
		strAns[ind] = str2[indStr2];
		printAllInterleavings(str1,str2,indStr1,indStr2+1,len1,len2,strAns,ind+1);
	}
}

int main()
{
	char *str1 = "AB";
	char *str2 = "CD";
	
	char *str = new char[strlen(str1)+strlen(str2)+1];
	
	printAllInterleavings(str1,str2,0,0,strlen(str1),strlen(str2),str,0);
	
	return 0;
}
