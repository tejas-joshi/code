//============== BREADTH FIRST SEARCH

/*
 * POINTS TO BE TAKEN CARE:
 * 1) Just do visited[i]=true before pushing i into queue.
 *

TC : O(|V|+|E|)	// no. of edges
SC : O(|V|)	// no. of vertices

*/

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
int main()
{
	int n;	
	bool **E,*visited;
	queue<int> Q;

	cin >> n;
	visited = (bool *)calloc(sizeof(bool),n);
	E = (bool **)calloc(sizeof(bool*),n);
	for(int i=0;i<n;i++)
		E[i] = (bool*)calloc(sizeof(bool),n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> E[i][j];

	visited[0]= true;
	Q.push(0);

	while(!Q.empty())
	{
		cout << Q.front() << " ";
		int ele = Q.front();
		Q.pop();
		for(int j=0;j<n;j++)
			if(!visited[j] && E[ele][j])
			{
				visited[j] = true;
				Q.push(j);
			}
	}
					
	return 0;
}
