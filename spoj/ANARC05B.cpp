#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n1,n2;
	int *a,*b,**dp;
	while(1)
	{
		int *sumA,*sumB,maxSum=0;
		int indexA=0,indexB=0;
		
		cin >> n1;
		if(n1==0)
			break;
		
		a = new int[n1];
		sumA = new int[n1];
		for(int i=0;i<n1;i++)
		{
			cin >> a[i];
			if(i==0)
				sumA[i] = a[i];
			else
				sumA[i] = sumA[i-1] + a[i];
		}
			
		cin >> n2;
		b = new int[n2];
		sumB = new int[n2];
		for(int i=0;i<n2;i++)
		{
			cin >> b[i];
			if(i==0)
				sumB[i] = b[i];
			else
				sumB[i] = sumB[i-1] + b[i];
		}

		dp = (int **)malloc(2*sizeof(int *));
		for(int i=0;i<2;i++)
			dp[i] = (int *)malloc(sizeof(int)*(n2+1));

		for(int i=0;i<=n2;i++)
			dp[0][i] = 0;
		dp[1][0] =0;

		for(int i=1;i<=n1;i++)
			for(int j=1;j<=n2;j++)
				if(a[i-1]==b[j-1])
				{
					if(indexA==0 && indexB==0)
						maxSum = max(sumA[i-1],sumB[j-1]);
					else	
						maxSum = maxSum + max(sumA[i-1]-sumA[indexA],sumB[j-1]-sumB[indexB]);
					indexA=i-1;
					indexB=j-1;
				}				
			
		if(indexA==0 && indexB==0)
			maxSum = max(sumA[n1-1],sumB[n2-1]);
		else	
			maxSum = maxSum + max(sumA[n1-1]-sumA[indexA],sumB[n2-1]-sumB[indexB]);

		cout << maxSum << endl;
	}
	return 0;
}
