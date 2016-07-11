
// FOR LAST TEST CASE IT SHOULD BE 360... YOU PROGRAM IS GIVING 349... AWESOME PROBLEM I HAVE SEEN.. SOLVE IT.. INTERESTING

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef long long int LL;
struct vec
{
	LL x,y;
};
typedef struct vec Vec;

LL sqr(LL x,LL y)
{	return x*x + y*y;	}

int main()
{	
	int N,i,j;
	Vec *V,*dp;
	scanf("%d",&N);
	V = (Vec *)malloc(N*sizeof(Vec));
	dp = (Vec *)malloc((N+1)*sizeof(Vec));

	for(i=0;i<N;i++)
		scanf("%lld %lld",&(V[i].x),&(V[i].y));

	dp[0].x = dp[0].y = 0;
	LL mxSum=INT_MIN;
	Vec maxV;
	LL temp;
	for(i=1;i<=N;i++)
	{
		for(j=0;j<i;j++)
		{
			temp = sqr(dp[j].x + V[i-1].x,dp[j].y + V[i-1].y);
			if( (sqr(dp[j].x,dp[j].y) < temp)
			     && (mxSum < temp))
			{	
				maxV.x = dp[j].x + V[i-1].x;
				maxV.y = dp[j].y + V[i-1].y;
				mxSum = temp;
			}
		}

		if(i!=1 && mxSum<=sqr(dp[i-1].x,dp[i-1].y))
		{
			dp[i].x = dp[i-1].x;
			dp[i].y = dp[i-1].y;
		}
		else
		{
			dp[i].x = maxV.x;
			dp[i].y = maxV.y;
		}
		mxSum = INT_MIN;
		printf("%lld %lld\n",dp[i].x,dp[i].y);	
	}		
//	printf("%lld\n",sqr(dp[N].x,dp[N].y));
	
	return 0;
}
