#include<iostream>
#include<string>
using namespace std;
int main()
{
	char digit[26]={0,'1','2','3',0,'1','2',0,0,'2','2','4','5','5',0,'1','2','6','2','3',0,'1',0,'2',0,'2'};

	string s;
	cin >> s;
	int l = s.length();

	int j=1;
	for(int i=1;i<l;i++)
		if(digit[s[i]-97])
			s[j++] = digit[s[i]-97];
	l = s.length();
	for(int i=1;i<l;i++)
		if(s[i]<48 || s[i]>57)
		{
			s[i] = NULL;
			break;
		}
	cout << s << endl;
	return 0;
}
