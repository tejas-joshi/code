//=== FIND THE MAXIMUM AMOUNT MADE FROM THE SEQUENCE OF COINS... 

There are n coins in a line. (Assume n is even). 
Two players take turns to take a coin from one of the ends of the line until there are no more coins left. 
The player with the larger amount of money wins.

Would you rather go first or second? Does it matter?
Assume that you go first, describe an algorithm to compute the maximum amount of money you can win.



#include<iostream>
using namespace std;
int main()
{
	int *P,N;
	cin >> N;
	P = new int[N];

	// Takine the coins prices	
	for(int i=0;i<N;i++)
		cin >> P[i];

	int **dp;
	dp = new int*[N];
	for(int i=0;i<N;i++)
		dp[i] = new int[N];

	int m,n;

	// dp[m][n] indicates the maximum amount that can be gained between array having index m and n.
	// so our answer will be dp[0][n-1]...
	
	for(int i=0;i<N;i++)
	{
		// every inner loop completion fills the diagonals in the dp 2D array
		// first it fills the main diagonal -- (0,0) (1,1) (2,2) (3,3).....
		// then next diagonal in upper triangle. (0,1) (1,2) (2,3) (3,4)...
		// continue till the whole upper diagonal will be filled out...
		for(m=0,n=i;n<N;m++,n++)
		{
			int a,b,c;

			// checking the boundary .. if it is right then assign the dp value else 0
			a = ( m+2<N ? dp[m+2][n] : 0);			
			b = ( ( m+1<N && n-1>=0) ? dp[m+1][n-1] : 0);
			c = (  n-2>=0 ? dp[m][n-2] : 0);

			dp[m][n] = max( P[m] + min(a,b), P[n] + min(b,c) );
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << dp[0][N-1] << endl;
	return 0;
}
