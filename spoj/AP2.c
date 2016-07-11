#include<stdio.h>
int main()
{
	int T;
	long long int a,d,n,S,t3,tn3,i;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%lld %lld %lld",&t3,&tn3,&S);
		n = (S*2)/(t3+tn3);
		d = (tn3-t3)/(n-5);
		a = t3 - d*2;

		printf("%lld\n",n);
		for(i=0;i<n;i++)
			printf("%lld ",a+i*d);
		printf("\n");
	}
	
	return 0;
}
