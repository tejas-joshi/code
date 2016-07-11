#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char c1,c2;
	int count=0;
	
	while(1)
	{
		c1 = getchar();
		c2 = getchar();
		if(c1==' ' && c2==' ')
			break;
		count++;

		if(count==1)
			cout << "Ready" << endl;

		getchar();
		if( (c1=='p' && c2=='q') ||
			(c1=='q' && c2=='p') ||
			(c1=='b' && c2=='d') ||
			(c1=='d' && c2=='b'))
			cout << "Mirrored pair" << endl;
		else
			cout << "Ordinary pair" << endl;
	}
	return 0;
}
