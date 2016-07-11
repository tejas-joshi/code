//===== PATTERN MATCHING (NAIVE APPROACH)

/*
Naive approach to search the pattern(susbstring) in string.
TC : O(mn)
SC : O(1)
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,pat;
	cin >> str >> pat;

	int lstr = str.length();
	int lpat = pat.length();

	for(int i=0;i<=lstr-lpat;i++)
	{
		int j=0;
		while(j<lpat && str[i]==pat[j])
		{
			j++;
			i++;
		}
		if(j==lpat)
		{ 
			cout << "Pattern found at " << i-lpat << endl;
			break;
		}
	}

	return 0;
}	
