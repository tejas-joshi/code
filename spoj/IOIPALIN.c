#include<stdio.h>
#include<string.h>

int main()
{
	char s[5010];
	int len,i,lcslen=0,j;

	scanf("%d %s",&len,s);

	int dp[2][len+1];
	memset(dp,0,sizeof(dp[0][0])*(len+1)*2);
	
	for(i=1;i<=len;i++)
		for(j=len;j>0;j--)
		{
			if(s[i-1]==s[j-1])
				dp[i%2][len-j+1] = 1 + dp[(i+1)%2][len-j];
			else
				dp[i%2][len-j+1] = ((dp[(i+1)%2][len-j+1]>dp[i%2][len-j])?dp[(i+1)%2][len-j+1]:dp[i%2][len-j]);
			if(dp[i%2][len-j+1]>lcslen)
				lcslen = dp[i%2][len-j+1];
		}

	printf("%d\n",len-lcslen);
		
	return 0;
}

