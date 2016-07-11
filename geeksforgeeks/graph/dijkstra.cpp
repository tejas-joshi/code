#include<iostream>
#include<queue>
#include<limits.h>
#include<string.h>
using namespace std;

class compare
{
	public:
		bool operator ()(pair<int,int> p1,pair<int,int> p2)
		{
			return p1.second > p2.second;
		}
};

int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,compare> pQ;

	int V;
	cin >> V;
	
	int edge[V][V],E,src,dest,w;
	bool visited[V];
	int dist[V];

	memset(edge,0,sizeof(edge[0][0])*V*V);
	memset(visited,false,sizeof(visited[0])*V);
	memset(dist,1000000,sizeof(dist));

	cin >> E;
	for(int i=0;i<E;i++)
	{
		cin >> src >> dest >> w;
		edge[src][dest] = w;
		edge[dest][src] = w;
	}

	cin >> src;
	
	pQ.push(make_pair(src,0));
	for(int i=0;i<V;i++)
		if(src!=i)
			pQ.push(make_pair(i,INT_MAX));
	dist[src]= 0;

/*
	while(!pQ.empty())
	{
		cout << pQ.top().first << " " << pQ.top().second << endl;
		pQ.pop();
	}
*/	

	while(!pQ.empty())
	{
		int u = pQ.top().first;
		visited[u] = true;

		
		for(int v=0;v<V;v++)
		{
			cout << u << " " << v <<  " " << visited[v] <<  " " << edge[u][v] <<  " " << dist[v] << endl;
			if(!visited[v]	&& edge[u][v] && (dist[u] + edge[u][v] < dist[v]))
				dist[v] = dist[u] + edge[u][v];
		}
		pQ.pop();
	}			

	for(int i=0;i<V;i++)
		cout << i << " : " << dist[i] << endl;

	return 0;
}
