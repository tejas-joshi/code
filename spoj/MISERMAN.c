#include<stdio.h>
#include<limits.h>

int minV(int a,int b,int c)
{
	return (a<b)?((a<c)?a:c):((b<c)?b:c); 
}

int main()
{
	int m,n,i,j,d,min=INT_MAX;
	int dp[2][105];

	scanf("%d%d",&m,&n);

	for(i=0;i<=(n+1);i++)
		dp[0][i] = INT_MAX;
	dp[1][n+1] = INT_MAX;			
	dp[1][0] = INT_MAX;			

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&d);
			dp[i%2][j] = d + ((i==1)?0:minV(dp[(i-1)%2][j],dp[(i-1)%2][j-1],dp[(i-1)%2][j+1]));
		}
	}

	for(j=1;j<=n;j++)
		if(dp[m%2][j]<min)
			min = dp[m%2][j];

	printf("%d\n",min);
	
	return 0;
}
