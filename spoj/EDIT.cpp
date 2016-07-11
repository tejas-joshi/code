#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	int x=1,y=0;
	while(1)
	{
		char s[1001];
		if(scanf("%s",s)==-1)
			break;		
		
		int costX=0,costY=0;
		for(unsigned int i=0;i<strlen(s);i++)
		{
			if(s[i]>=65 && s[i]<=90)
				x?(costY++):(costX++);
			else
				x?(costX++):(costY++);

			x=1-x;
			y=1-y;
		}		
		cout << min(costX,costY) << endl;
	}	
	return 0;
}
