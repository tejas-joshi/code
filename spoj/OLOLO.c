#include<stdio.h>
int main()
{
	int N,a;
	long long int ans =0;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&a);
		ans = ans ^ a;
	}
	printf("%lld\n",ans);
	return 0;
}	
