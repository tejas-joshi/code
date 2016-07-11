//====== DETECT CYCLE IN DIRECTED GRAPH

/**********

Here BFS is used to detect the cycle. DFS can also detect cycle in same way.
Don't forget to set visited array to false.
Don't add edges in both lists.
* (e.g. dont add (0,1) to both list[0] and list[1]. Only in one of them.)

TC : O(|V|+|E|)	( same as DFS/BFS )
SC : O(|V|)		( 		"		  )

**********/


#include<iostream>
#include<list>
#include<queue>
using namespace std;
int main()
{
	int n,e;
	list<int> *adj;
	bool *visited;
	queue<int> Q;
	
	cin >> n >> e;
	visited = new bool[n];
	adj = new list<int>[n];

	int src,dest;
	for(int i=0;i<e;i++)
	{
		cin >> src >> dest;
		adj[src].push_back(dest);
	}

	Q.push(0);
	visited[0] = true;
	bool cycle=false;

	// set visited array to 0(false).
	fill_n(visited,n,0);

	while(!Q.empty())
	{
		int ele = Q.front();
		Q.pop();
		for(list<int> :: iterator it=adj[ele].begin();it!=adj[ele].end();it++)
		{
			if(visited[*it])
			{
				cycle=true;
				break;
			}
			visited[*it]=true;
			Q.push(*it);
		}
					
		if(cycle)
			break;
	}

	if(cycle)
		cout << "detected..." << endl;
	else
		cout << "no cycle..." << endl;

	return 0;
}
