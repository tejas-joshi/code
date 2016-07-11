#include<stdio.h>
#include<math.h>
int main()
{
	int T,n,i,rt;
	int sum;
	scanf("%d",&T);
	while(T--)
	{	
		sum=1;
		scanf("%d",&n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		rt = sqrt(n);
		for(i=2;i<=rt;i++)
			if(n%i==0)
				sum = sum + i + (n/i);
		if(rt*rt==n && n!=1)
			sum = sum - rt;
		printf("%d\n",sum);
	}
	return 0;
}
