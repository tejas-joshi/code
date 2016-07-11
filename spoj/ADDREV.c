#include<stdio.h>
int rev(int a)
{
	int d=0;
	while(a)
	{
		d = d*10 + (a%10);
		a = a/10;
	}
	return d;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",rev(rev(a)+rev(b)));	
	}
	
	return 0;
}
