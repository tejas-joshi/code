//=== CHECK WHETHER GRAPH IS 2-COLORABLE ( BI-PARTITE ) ( ODD-LENGTH CYCLE )

// If graph is NOT 2-colorable then odd length cycle exists.

/**********

* CHECK 2-COLORABLE = CHECK BIPARTITE = CHECK ODD-LENGTH CYCLE EXISTANCE.

Logic:
* Color current node and push it into queue ( for BFS ).
* Check the color of all the connected nodes to this node.
	If it is same then "not 2 colorable"
	else continue for all nodes..

	If graph can be colored then "2 colorable.."

TC : O(|E|+|V|)
SC : O(|V|)

**********/

#include<iostream>
#include<list>
#include<queue>
using namespace std;
int main()
{
	list<int> *adj;
	int *color;
	int n,e;
	queue<int> Q;

	cin >> n >> e;

	color = new int[n];
	adj = new list<int>[n];

	int src,dest;
	for(int i=0;i<e;i++)
	{
		cin >> src >> dest;
		adj[src].push_back(dest);
	}

	fill_n(color,n,-1);

	color[0] = 0;
	Q.push(0);

	bool cycle = false;

	while(!Q.empty())
	{
		int el = Q.front();
		int curr_color = color[el];
		Q.pop();
		for(list<int> :: iterator it=adj[el].begin();it!=adj[el].end();it++)
		{
			if(color[*it]==curr_color)
			{
				cycle = true;
				break;
			}
			color[*it] = 1 - curr_color;
			Q.push(*it);
		}
		if(cycle)
			break;
	}

	if(cycle)
		cout << "not 2 colorable... " << endl;
	else
		cout << "2 colorable..." << endl;

	return 0;
}
