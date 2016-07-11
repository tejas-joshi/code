#include <stdio.h>
int main()
{
	int T;
	long double n;
	for(scanf("%d", &T);T;T--)
	{
		scanf("%Lf", &n);
		printf("%.0Lf\n", n/2.0 * (7.0*n*n + 4.5*n + 1.0));
	}
	return 0;
}
