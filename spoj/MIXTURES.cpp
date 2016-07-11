#include<iostream>
#include<limits.h>
#include<cstdio>
using namespace std;
int main()
{
	int color[101][101],smoke[101][101];
	int n,A[101];

	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			cin >> A[i+1];

		int j;
		for(int i=1;i<n;i++)
		{
			color[i][i] = A[i];
			smoke[i][i] = 0;
			
			smoke[i][i+1] = A[i]*A[i+1];
			color[i][i+1] = (A[i]+A[i+1])%100;
		}
		color[n][n] = A[n];
		smoke[n][n] = 0;
		
		for(int L=3;L<=n;L++)
		{
			for(int i=1;i<=n-L+1;i++)
			{
				j=i+L-1;
				smoke[i][j] = INT_MAX;
				for(int k=i;k<j;k++)
				{
					int c = color[i][k]*color[k+1][j] + smoke[i][k] + smoke[k+1][j];
					if(c<smoke[i][j])
					{
						smoke[i][j]=c;
						color[i][j]=(color[i][k]+color[k+1][j])%100;
					}
				}
			}
		}
		cout << smoke[1][n] << endl;	
	}	

	return 0;
}
