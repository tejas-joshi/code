#include<stdio.h>
int main()
{
	long long int d,n,k;
	scanf("%lld",&d);
	while(d--)
	{
		scanf("%lld %lld",&n,&k);
		printf("%d\n",(((n-k)&((k-1)/2))==0));
	}
	return 0;
}
