#include<cstdio>
using namespace std;
int max(int a, int b)
{
	return (a >= b)?a:b;
}

int rs, fun, dp[101][505];
int main()
{
	int v, n, w, i, maxFun;
	while(scanf("%d%d", &v, &n)==2)
	{
		if(!v && !n)
			break;
		for(i = 1; i <= n; i++)
		{
			scanf("%d%d", &rs, &fun);
			for(w = 1; w <= v; w++)
			{
				if(rs > w) dp[i][w] = dp[i-1][w];
				else dp[i][w] = max(dp[i-1][w], dp[i-1][w-rs] + fun);
			}
		}
		for(w = v, maxFun = dp[n][v]; w; w--)
			if(dp[n][w] < maxFun)
				break;
		printf("%d %d\n", w + 1, dp[n][v]);
	}
	return 0;
}
