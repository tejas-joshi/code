#include<stdio.h>
int main()
{
	int t,d,sum=0;
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&d);
		sum+= ((d>0)?d:0);
	}
	printf("%d\n",sum);
	return 0;
}
