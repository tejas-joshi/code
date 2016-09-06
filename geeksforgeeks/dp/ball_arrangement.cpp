//==== Ways to arrange Balls such that adjacent balls are of different types

/*
There are ‘p’ balls of type P, ‘q’ balls of type Q and ‘r’ balls of type R. 
Using the balls we want to create a straight line such that no two balls of same type are adjacent.

Input  : p = 1, q = 1, r = 0
Output : 2
There are only two arrangements PQ and QP

Input  : p = 1, q = 1, r = 1
Output : 6
There are only six arrangements PQR, QPR,
QRP, RQP, PRQ and RPQ

We recursively call for three cases
1) Last ball to be placed is of type P (0) then countWays(p-1,q,r,1) + countWays(p-1,q,r,2)
2) Last ball to be placed is of type Q (1) then countWays(p,q-1,r,0) + countWays(p,q-1,r,2)
3) Last ball to be placed is of type R (2) then countWays(p,q,r-1,0) + countWays(p,q,r-1,1)
and call the functions accordingly. 

TC : O(pqr)
SC : (pqr)

*/

#include<iostream>
using namespace std;

int dp[10][10][10][3]; // set all the values to -1

// Returns count of arrangements where last placed ball is
// 'last'.  'last' is 0 for 'p', 1 for 'q' and 2 for 'r'
int countWaysUtil(int p, int q, int r, int last)
{
	if(p<0 || q<0 || r<0)
		return 0;
	
	// If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
	if(p==1 && q==0 && r==0 && last==0)
		return 1;
	if(p==0 && q==1 && r==0 && last==1)	// same for q
		return 1;
	if(p==0 && q==0 && r==1 && last==2) // same for r
		return 1;
	
	if(dp[p][q][r][last]!=-1)
		return dp[p][q][r][last];
	
	// if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
	if(last==0)
		dp[p][q][r][last] = countWaysUtil(p-1,q,r,1) + countWaysUtil(p-1,q,r,2);
	else if(last==1)  // same for q
		dp[p][q][r][last] = countWaysUtil(p,q-1,r,0) + countWaysUtil(p,q-1,r,2);
	else if(last==2) // same for r
		dp[p][q][r][last] = countWaysUtil(p,q,r-1,0) + countWaysUtil(p,q,r-1,1);
	return dp[p][q][r][last];
}

int main()
{
	int p,q,r;
	cin >> p >> q >> r;	
	cout << countWaysUtil(p,q,r,0) + countWaysUtil(p,q,r,1) + countWaysUtil(p,q,r,2) << endl;		
	return 0;
}
