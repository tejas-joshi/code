//============== BREADTH FIRST SEARCH using list<int>

/***********
POINTS TO BE TAKEN CARE:
* Just do visited[i]=true before pushing i into queue.
* Don't forget to set visited array to 0(false).

TC : O(|V|+|E|)	// no. of edges
SC : O(|V|)	// no. of vertices

*************/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<list>
using namespace std;
int main()
{
	int n,e;	
	bool *visited;
	queue<int> Q;
	list<int> *adj;

	cin >> n;
	cin >> e;

	adj = new list<int>[n];
	visited = new bool[n];

	int src,dest;
	for(int i=0;i<e;i++)
	{
		cin >> src >> dest;
		adj[src].push_back(dest);
	}

	// set visited array to 0(false).
	fill_n(visited,n,0);
	
	visited[0]= true;
	Q.push(0);

	while(!Q.empty())
	{
		cout << Q.front() << " ";
		int ele = Q.front();
		Q.pop();
		for(list<int> :: iterator it=adj[ele].begin();it!=adj[ele].end();it++)
			if(!visited[*it])
			{
				visited[*it] = true;
				Q.push(*it);
			}
	}
					
	return 0;
}
