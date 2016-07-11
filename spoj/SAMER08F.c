#include<stdio.h>
int main()
{
	int d;
	while(1)
	{
		scanf("%d",&d);
		if(!d)
			break;
		printf("%d\n",(d*(d+1)*(2*d+1))/6);
	}
	return 0;
}
