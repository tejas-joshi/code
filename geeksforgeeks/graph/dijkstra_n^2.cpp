//======= DIJKSTRA'S ALGORITHM FOR SINGLE SOURCE SHORTEST PATH...

/*
Find the shortest path to all the nodes(or any given) from the given source.

Logic :

There several arrays.

visited[V] (boolean) --->  visited[i] indicates whether i has been visited or not.
dist[V] (int) ---> dist[i] indicates the minimum distance found till now from the source.
edge[V][V] (int) ---> holds the adjacencey matrix in which cell indicated the weight of the edge.
let say source as src

Initially,
	dist[src]=0 ... for all other elements dist[i] = INT_MAX;
	visited[i] = false for all the nodes.

Loop through all the nodes
	find the node with the minimum dist which is not visited.
	make the selected node visited as true;
	Start exploring the selected node and update the distance if the current distance is higher and that node is not visited.

== The code is for undirected graph, same dijkstra function can be used for directed graphs also.

TC : O(V^2)		// on each iteration it is finding the minimum weight node 
SC : O(V^2)		// depends on the representation of the graph.. currently it's adjacency matrix so V^2

The code calculates shortest distance, but doesn’t calculate the path information.
* We can create a parent array, update the parent array when distance is updated (like prim’s implementation)
* and use it show the shortest path from source to different vertices.

The code finds shortest distances from source to all vertices.
* If we are interested only in shortest distance from source to a single target,
* we can break the for loop when the picked minimum distance vertex is equal to target.

Time Complexity of the implementation is O(V^2).
* If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap.
* We will soon be discussing O(E Log V) algorithm as a separate post.

Dijkstra’s algorithm doesn’t work for graphs with negative weight edges.
* For graphs with negative weight edges, Bellman–Ford algorithm can be used.

*/

#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

// Finding the node index which is not visited and having minimum distance from the source..
int minIndex(int *dist,bool *visited,int V)
{
	int min = INT_MAX,minInd=-1;
	for(int i=0;i<V;i++)
		if(!visited[i] && dist[i]<min)
		{
			min = dist[i];
			minInd = i;
		}
	return minInd;	
}

int main()
{
	int V;
	cin >> V;
	
	int edge[V][V],E,src,dest,w;
	bool visited[V];
	int dist[V];

	memset(edge,0,sizeof(edge[0][0])*V*V);			// set all the values in the matrix as 0
	memset(visited,false,sizeof(visited[0])*V);		// set all the values as false
	memset(dist,1000000,sizeof(dist));				// set all the distances as max...

	// taking the inputs of the edges
	cin >> E;
	for(int i=0;i<E;i++)
	{
		cin >> src >> dest >> w;
		edge[src][dest] = w;	// updating the matrix for the edge
		edge[dest][src] = w;	// updating the reverse way also for the edge
	}

	cin >> src;
	dist[src]= 0;	// setting the distance from the source is 0 which is obvious..

	for(int i=0;i<V-1;i++)
	{
		// taking the minimum weight index 
		int u = minIndex(dist,visited,V);

		// making it visited as it is selected for exploration
		visited[u] = true;
		
		for(int v=0;v<V;v++)
			// now check for the unvisited nodes which is having the lesser distance from the source than currently having
			if(!visited[v]	&& edge[u][v] && (dist[u] + edge[u][v] < dist[v]))
				dist[v] = dist[u] + edge[u][v];		// updating the distance
	}			

	// printing the distance for all the nodes from the source...
	for(int i=0;i<V;i++)
		cout << i << " : " << dist[i] << endl;

	return 0;
}
