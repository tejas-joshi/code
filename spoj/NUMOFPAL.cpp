#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	
	bool isPal[1001][1001];

	int count=0;
	for(int i=0;i<len;i++)
	{
		isPal[i][i] = true;
		count++;
	}

	for(int L=2;L<=len;L++)
	{
		for(int i=0;i<=len-L;i++)
		{
			int j=i+L-1;
			
			if(L==2)
				isPal[i][j] = (s[i]==s[j]);
			else
				isPal[i][j] = (s[i]==s[j]) && isPal[i+1][j-1];

			if(isPal[i][j])
				count++;
		}
	}

	cout << count << endl;

	return 0;
}
