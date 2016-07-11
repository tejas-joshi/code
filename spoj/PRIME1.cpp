#include<iostream>
#include<stdlib.h>
using namespace std;
typedef unsigned long long int LL;
int main()
{
	int T;
	LL **num;

	cin >> T;
	num = (LL **)malloc(T*sizeof(LL *));
	for(int i=0;i<T;i++)
	{
		num[i] = (LL *)malloc(2*sizeof(LL));
		cin >> num[i][0] >> num[i][1];
	}

	bool f=true;
	for(int x=0;x<T;x++)
	{	
		for(int i=num[x][0];i<=num[x][1];i++)
		{
			f = true;
			for(int j=2;j*j<=i;j++)
				if(i%j==0)
				{
					f= false;
					break;
				}
			if(f)
				cout << i << endl;		
		}
		cout << endl;
	}
	return 0; 
}

