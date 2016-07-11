#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,remain,c,i;
	double d;

	scanf("%lld",&c);
	while(c--)
	{
		scanf("%lld",&n);
		for(i=0;i*i<=n;i++)
		{
			remain = n - (i*i);
			d = sqrt(remain) + 0.5;
			if((d*d)==remain)
			{
				printf("Yes\n");
				break;
			}
		}
		if(i*i>n)
			printf("No\n");
	}
	return 0;
}
