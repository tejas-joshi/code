// REMOVE 'b' AND 'ac' FROM STRING IN SINGLE SCAN

/*
Maintain two indexes
One for maintaining the original index
Second for maintaining the index for resultant string.

Increment second index only if you are sure that 'b' or 'ac' is not there.

Set NULL at the last in the string.

TC : O(n)
SC : O(1)

*/

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[100];
	cin >> str;
	
	int len = strlen(str);
	int currInd=0;
	
	for(int i=0;i<len;i++)
	{
		if(str[i]=='b')			// checking for 'b'
			continue;
		else if(str[i]=='a' && (i+1<len) && str[i+1]=='c')		// checking for 'ac'
		{
			i++;		// because 'ac' has length 2. i must be incremented by 2.. one here and another in the for loop.
			continue;
		} 
		else
			str[currInd] = str[i];
		currInd++;
	}
	str[currInd] = '\0';		// end of the resultant string

	cout << str << endl;
	
	return 0;
}
