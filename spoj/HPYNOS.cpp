#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	
	int sqr[10] = {0,1,4,9,16,25,36,49,64,81};
	map<int,bool> M;
	scanf("%d",&n);
	int sum=0;

	while(!M[n])
	{
		M[n]=true;
		while(n>0)
		{
			sum = sum + sqr[n%10];
			n=n/10;
		}
		n=sum;
		if(n==1)
		{
			cout << M.size() << endl;
			break;
		}
		sum=0;
	}
	if(n!=1)
		cout << -1 << endl;
}	
	


	return 0;
}
