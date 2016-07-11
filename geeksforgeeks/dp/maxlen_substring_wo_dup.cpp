/****************

FIND THE MAX. LENGTH OF SUBSTRING WHICH HAS NO DUPLICATES

Ex. geeksforgeeks
* o/p : 7 (eksforg)

Logic :
* Take array of 26 and initialize it to -1.
* This array is used to store the index at which that character last seen.
* If value is -1 OR the charcter seen before is out of the string we are considering then
	len++;
	Update the index of that character.
  else
    Check for the last index value if it is in the string we are considering, it means we can't take current character.
    Now we have to move to the index that was previously seen in order to consider the current character.
    So we have to subtract that much length from len. Update the index of current character.
	len = len - (i-count[ind]);
	count[ind] = i;

TC : O(n)
SC : O(1) constant space. count[26]

******************/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int count[26],len=0,max=0;
	fill_n(count,26,-1);		// to set the count array to -1
	int slen = s.length();

	for(int i=0;i<slen;i++)
	{
		int ind = s[i]-97; 			// considering the string has only lowercase characters
		if(count[ind]==-1 || (i-count[ind])>len)
			len++;
		else
		{
			if(len>max)
				max = len;
			len = i-count[ind];
		}				
		count[ind] = i;
	}

	// last check... the case where our answer ends at the end of original string.. max was not updated in the above code...
	if(len>max)
		max = len;

	cout << max << endl;

/*
 *  // PRINTING THE COUNT ARRAY
	for(int i=0;i<26;i++)
		cout << count[i] << " ";
*/
			
	return 0;
}
