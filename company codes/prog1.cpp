#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

using namespace std;
int toBinary(char *S, int startInd, int endInd)
{
    int number=0;
    for(int i=0; i<=(endInd-startInd); i++)
    {
		number = number*2;
		if(S[startInd+i]=='1')
			number++;
    }
    return number;
}

bool isPower5(char *S, int startInd, int endInd)
{	
    int n = toBinary(S,startInd,endInd);
    int rem = 5;    
    while(n>rem)
        rem = rem * 5;        
    return (n==1) || (rem==n);
}

int getMin(char *S)
{
	int l = strlen(S);
	int *dp;
	bool *poss;
	dp = (int *)malloc(l * sizeof(int));
	poss = (bool *)malloc(l * sizeof(bool));

	for(int i=0;i<l;i++)
	{
		dp[i] = INT_MAX;
		poss[i] = false;	
	}

	if(S[0]=='1')
	{
		dp[0] = 1;
		poss[0] = true;
	}	
	
	for(int L=2;L<=l;L++)
	{
		for(int j=1;j<L;j++)
		{
			bool ans = poss[j-1] && isPower5(S,j,L-1);			
			if(ans)
			{
				dp[L-1] = min(dp[L-1],dp[j-1]+1);
				poss[L-1] = true;
			}
		}
		if(isPower5(S,0,L-1))
		{
			dp[L-1] = 1;
			poss[L-1] = true;
		}
	}
	
	
	if(poss[l-1]==false)
		return -1;
	return dp[l-1];	
}

int main()
{
	char *S = "101111";
	cout << getMin(S) << endl;
    return 0;
}
