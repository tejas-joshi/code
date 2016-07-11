#include<stdio.h>
typedef long long int LL;
int main()
{
	char seatN[6] = "WAAMW";
	
	LL Q,n,ind;
	scanf("%lld",&Q);

	while(Q--)
	{
		scanf("%lld",&n);

		if(n==1)
		{
			printf("poor conductor\n");
			continue;
		}

		ind = n-2;
		printf("%lld ",ind/5 + 1);

		if((ind/5)%2)		// odd case
		{
			printf("%c ",seatN[4-(ind%5)]);
			if((ind%5)>=3)
				printf("L\n");
			else	
				printf("R\n");
		}
		else    // even case
		{
			printf("%c ",seatN[ind%5]);	
			if((ind%5)>=2)
				printf("R\n");
			else	
				printf("L\n");
		}
	}
	
	return 0;
}
