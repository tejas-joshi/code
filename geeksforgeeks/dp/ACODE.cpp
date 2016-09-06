#include<iostream>
#include<cstdio>
using namespace std;
int main()
{	
	int val[101]={0};
	for(int i=1;i<=26;i++)
		val[i] = 1;

	int curr,prev=0;

	while(1)
	{
		int dp[5001]={0};
		dp[1]=1;

		char c; 
		c = getchar();
		if( (c-'0')==0 )
			break;
		int count=1,dig;
		prev = c - '0';
		while( (c=getchar()) && (c!='\n') )
		{
			count++;
			curr = c - '0';
			dig = (prev!=0)?(prev*10 + curr):0;
	
			if(val[dig])	// check prev and current digit makes valid character
				dp[count] = dp[count] + ((count==2)?1:dp[count-2]);

			if(val[curr])	// check curr character makes valid character... 0 doesnt make any character
				dp[count] = dp[count] + dp[count-1]; 					

			prev = curr;
		}
		cout << dp[count] << endl;
	}
	

	return 0;
}
