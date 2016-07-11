#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int T;
	int *oxyReq,*nitReq;

	cin >> T;

	oxyReq = new int[T];
	nitReq = new int[T];

	for(int i=0;i<T;i++)
		cin >> oxyReq[i] >> nitReq[i];

	int nB;
	cin >> nB;

	int **bottles;

	bottles = new int*[nB];
	for(int i=0;i<nB;i++)
		bottles[i] = new int[3];

	int totalOxy=0,totalNit=0;
	for(int i=0;i<nB;i++)
	{
		cin >> bottles[i][0] >> bottles[i][1] >> bottles[i][2];
		totalOxy = totalOxy + bottles[i][0];
		totalNit = totalNit + bottles[i][1];
	}

	int **dp;
	dp = new int*[totalOxy+1];
	for(int i=0;i<=totalOxy;i++)
		dp[i] = new int[totalNit+1];

	for(int i=0;i<=totalOxy;i++)
		for(int j=0;j<=totalNit;j++)
			dp[i][j] = INT_MAX;
	dp[0][0] = 0;

	for(int k=0;k<nB;k++)
		for(int i=totalOxy;i>=bottles[k][0];i--)
			for(int j=totalNit;j>=bottles[k][1];j--)
				dp[i][j] = min(dp[i][j],dp[i-bottles[k][0]][j-bottles[k][1]] + bottles[k][2]);

	for(int i=0;i<=totalOxy;i++)
	{
		for(int j=0;j<=totalNit;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}	

	

//	for(int i=0;i<T;i++)
//		cout << dp[oxyReq[i]][nitReq[i]] << endl;

	return 0;
}
