// =========== Union-Find Algorithm | Set 1 (Detect Cycle in a an Undirected Graph)

/*
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

Union: Join two subsets into a single subset.

In this post, we will discuss an application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes that graph doesn’t contain any self-loops.
We can keeps track of the subsets in a 1D array, lets call it parent[].

Let us consider the following graph:

        0
        |  \
        |    \
        1-----2

For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.

Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

0   1   2
-1 -1  -1 

Now process all edges one by one.

Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa.

0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
1  -1  -1

Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
1   2  -1

Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.

How subset of 0 is same as 2?
0->1->2 // 1 is parent of 0 and 2 is parent of 1

This union() and find() is naive and takes O(n) time in worst case.

*/

#include<iostream>
#include<string.h>
using namespace std;

typedef struct Edge_s
{
	int src,dest;
} Edge;

typedef struct Graph_s
{
	int V,E;
	Edge *edge;
} Graph;

Graph *createGraph(int V,int E)
{
	Graph *tempG = new Graph;
	tempG->V = V;
	tempG->E = E;
	
	tempG->edge = new Edge[E];
	return tempG;
}

// find the subset of an element i
int Find(int *parent,int i)
{
	if(parent[i]==-1)
		return i;
	return Find(parent,parent[i]);
}

// do union of two subsets
void Union(int *parent,int src,int dest)
{
	parent[src] = dest;
}


bool isCycle(Graph *G)
{
	int *parent = new int[G->V];
	memset(parent,-1,sizeof(int)*(G->V));
	
	for(int i=0;i<G->E;i++)
	{
		int x = Find(parent,G->edge[i].src);
		int y = Find(parent,G->edge[i].dest);
		
		if(x==y)
			return true;
		Union(parent,x,y);
	}
	return false;
}

int main()
{
	int V,E;
	cin >> V >> E;
	
	Graph *G = createGraph(V,E);
	
	int src,dest;
	for(int i=0;i<E;i++)
	{
		cin >> src >> dest;
		G->edge[i].src = dest;
	}
	
	if(isCycle(G))
		cout << "Cycle exists" << endl;
	else
		cout << "Cycle doesnt exist" << endl;
		
	return 0;
}
