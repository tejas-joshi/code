#include<stdio.h>

int maxV(int a,int b,int c)
{
	return (a>b)?((a>c)?a:c):((b>c)?b:c); 
}

int main()
{
	int T,m,n,i,j,d,max=-1;
	scanf("%d",&T);

	while(T--)
	{
		int dp[2][101]={{0},{0}};
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&d);				
				dp[i%2][j] = d + maxV(dp[(i-1)%2][j],dp[(i-1)%2][j-1],dp[(i-1)%2][j+1]);
				if(dp[i%2][j]>max)
					max = dp[i%2][j];
			}
		}

		printf("%d\n",max);
		max = -1;		
	}
	
	return 0;
}
