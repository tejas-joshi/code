#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int T;
	string S;
	int small[26],big[26];
	cin >> T;
	int count=0;
	while(T--)
	{
		memset(small,0,26*sizeof(int));	
		memset(big,0,26*sizeof(int));	

		cin >> S;
		int len = S.length();
		for(int i=0;i<len;i++)
		{
			if(S[i]>=97 && S[i]<=122)
				small[S[i]-97]++;
			else
				big[S[i]-65]++;
		}
	
		for(int i=0;i<26;i++)
			count = count + (small[i]/2) + ((small[i]%2)?1:0) + (big[i]/2) + ((big[i]%2)?1:0);
		cout << count << endl;
		count = 0;
	}
	
	return 0;
}
