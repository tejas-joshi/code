/****************

FIND NO. OF WAYS YOU CAN MAKE AMOUNT X BY TAKING GIVEN AMOUNT OF COINS.
QUANTITY FOR EACH COIN IS INFINITE.

Here function is defined to loop through the coins from start to n
* The reason behind taking 'start' is to avoid repeating counts.
* Otherwise same combinations will be repeated and counted.
 	e.g. X=4 {1,2,3}.. Here repeated counts are for {1,2,1},{1,1,2} and {2,1,1}.
		All these 3 counts should be considered as only 1.
	'start' maintains the order in which the coins are considered.
	Here once coin with value 2 is taken then it cannot take coin with value 1.

Both the iterative and recursive methods are implemented.

TC : O(n*X)
SC : O(X)

*****************/
 

#include<iostream>
#include<stdlib.h>
using namespace std;
int countRec(int *,int ,int, int );
int countItr(int *,int ,int);
int main()
{
	int *C,n,X;
	cin >> n;
	
	C = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		cin >> C[i];
	cin >> X;

	cout << countRec(C,n,0,X) << endl;
	cout << countItr(C,n,X) << endl;
		
	return 0;	
}

/*
LOGIC FOR ITERATIVE METHOD:

 * Here dp[i] indicates no. of ways to make amount i.
 * Every time we take one type of coin and increment the count by
 
   for each <coinValue>	c
		for all i=c to i<=X
			dp[i] = dp[i] + dp[i-c]

Ex.
	n=4 (2,5,3,6}
	X=10

dp table : 0 0 0 0 0 0 0 0 0 0 0

After completion of first coin iteration (i.e. c=2)
dp array : 1 0 1 0 1 0 1 0 1 0 1
Here each dp[i] indicates how many ways you can get amount by using only first coin ({2}).

After completion of second coin iteration (i.e. c=5)
dp array : 1 0 1 0 1 1 1 1 1 1 2
Here each dp[i] indicates how many ways you can get amount by using first coin and second coin.	({2,5})
e.g. dp[10]=2 -> 10 can be get 2 ways {2,2,2,2,2} and {5,5} using only coins 2 and 5.

Continue for all the coins.

Finally, dp[X] will have no. of ways by which we can get amount X by using all the coins.
 
*/

int countItr(int *C,int n,int X)
{
	int *dp;
	dp = (int *)malloc((X+1)*sizeof(int));

	dp[0]=1;
	for(int i=0;i<n;i++)
		for(int j=C[i];j<=X;j++)		// starting from C[i] because coin has value C[i].. We cant make less than C[i]...
			dp[j] = dp[j] + dp[j-C[i]];
	return dp[X];
}

int countRec(int *C,int n,int start,int X)
{
	int temp=0;
	for(int i=start;i<n;i++)
	{
		if(X-C[i]==0)
			temp++;
		else if(X-C[i]>0)
			temp = temp + countRec(C,n,i,X-C[i]);
	}
	return temp;
}
