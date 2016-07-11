//==== DEPTH FIRST SEARCH using list

/*********

POINTS TO BE TAKEN CARE
* Make visited[i]=true before pushing it into stack.
* Don't forget to set visited array to 0(false).

TC : O(|V|+|E|)
SC : O(|V|)

*********/


#include<iostream>
#include<stdlib.h>
#include<stack>
#include<list>
using namespace std;
int main()
{
	int n,e;	
	bool *visited;
	stack<int> S;
	list<int> *adj;

	cin >> n;
	cin >> e;
	
	visited = new bool[n];
	adj = new list<int>[n];

	int src,dest;
	for(int i=0;i<e;i++)
	{
		cin >> src >> dest;
		adj[src].push_back(dest);
	}

	// set visited array to 0(false).
	fill_n(visited,n,0);
	
	visited[0] = true;
	S.push(0);

	while(!S.empty())
	{
		cout << S.top() << " ";
		int elem = S.top();
		S.pop();

		for(list<int>::iterator it=adj[elem].begin();it!=adj[elem].end();it++)
			if(!visited[*it])
			{
				visited[*it] = true;
				S.push(*it);
			}
	}	
	
	return 0;		
}	
