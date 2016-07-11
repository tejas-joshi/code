#include<cstdio>
#include<map>
using namespace std;
int main()
{
	long long int n,T,sum=0;	
	long long int sqr[10] = {0,1,4,9,16,25,36,49,64,81};
	map<long long int,bool> M;

	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);

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
				printf("%d\n",M.size());
				break;
			}
			sum=0;
		}
		if(n!=1)
			printf("-1\n");
	}

	return 0;
}
