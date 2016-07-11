/**************

FLOYD-WARSHALL'S ALL PAIR SHORTEST PATH.

Floyd-Warshall Algorithm:
========================
* We initialize the solution matrix same as the input graph matrix as a first step.
* Then we update the solution matrix by considering all vertices as an intermediate vertex.
* The idea is to one by one pick all vertices and update all shortest paths
	which include the picked vertex as an intermediate vertex in the shortest path.
* When we pick vertex number k as an intermediate vertex,
  we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices.
* For every pair (i, j) of source and destination vertices respectively, there are two possible cases.

1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j].

Here -1 is used as input for INFINITE and then updated to INT_MAX
But while checking, take care about conditions : (Especially first two otherwise you'll end up getting weird values)
	if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];

TC : O(V^3)
SC : O(V^2)

*************/

#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int **A,V,**dp;
	cin >> V;

	A = (int **)malloc(V*sizeof(int *));
	for(int i=0;i<V;i++)
		A[i] = (int *)malloc(V*sizeof(int));

	dp = (int **)malloc(V*sizeof(int *));
	for(int i=0;i<V;i++)
		dp[i] = (int *)malloc(V*sizeof(int));

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
		{
			cin >> A[i][j];
			if(A[i][j]==-1)		// If the input is INFINITE 
				A[i][j] = INT_MAX;
			dp[i][j] = A[i][j];
		}

	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				// first condition to check path between i and k
				// second condition to check path between k and j
				// third condition to check min cost from path i and j
				if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dp[i][j]==INT_MAX)
				dp[i][j] = -1;
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}
	
	return 0;
}
