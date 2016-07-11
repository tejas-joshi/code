#include <cstdio>
#define N 1000002
bool dp[N]; 
int main() 
{
	int k, l, n, i, c;
	scanf("%d %d %d",&k,&l,&n);
	for(i = 1; i <= N; ++i) 
		dp[i] = ((dp[i-1]==0) || (i-k>=0 && dp[i-k]==0) || (i-l>=0 && dp[i-l] == 0));
			
	while(scanf("%d",&c)!=EOF) 
		printf("%c",'A'+(!dp[c]));
		
	printf("\n");
}
