#include<stdio.h>
#include<limits.h>
int minV(int a,int b)
{
	return (a<b)?a:b; 
}

int main()
{
	int T,m,i,j,d,min=INT_MAX;
	int dp[2][5];

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&m);

		for(i=0;i<=4;i++)
			dp[0][i] = INT_MAX;
		dp[1][4] = INT_MAX;			
		dp[1][0] = INT_MAX;	
		
		for(i=1;i<=m;i++)
			for(j=1;j<=3;j++)
			{
				scanf("%d",&d);				
				dp[i%2][j] = d + ((i==1)?0:minV(dp[(i+1)%2][j-1],dp[(i+1)%2][j+1]));
			}

		for(j=1;j<=3;j++)
			if(dp[m%2][j]<min)
				min = dp[m%2][j];
			
		printf("%d\n",min);
		min = INT_MAX;		
	}
	
	return 0;
}
