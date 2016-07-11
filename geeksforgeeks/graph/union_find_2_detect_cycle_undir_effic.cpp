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

typedef struct subset_s
{
	int parent,rank;
} subset;

// find the subset of an element i
int Find(subset *arrSub,int i)
{
	if(arrSub[i].parent!=i)
		return Find(arrSub,arrSub[i].parent);
	return arrSub[i].parent;
}

// do union of two subsets
void Union(subset *arrSub,int xRoot,int yRoot)
{
	if(arrSub[xRoot].rank > arrSub[yRoot].rank)
		arrSub[yRoot].rank = xRoot;
	else if(arrSub[xRoot].rank < arrSub[yRoot].rank)
		arrSub[xRoot].rank = yRoot;
	else
	{
		arrSub[yRoot].parent = xRoot;
		arrSub[xRoot].rank++;
	}	
}


bool isCycle(Graph *G)
{
	subset *arrSub = new subset[G->V];
	
	for(int i=0;i<G->V;i++)
	{
		arrSub[i].parent = i;
		arrSub[i].rank=0;	
	}
	
	for(int i=0;i<G->E;i++)
	{
		int xRoot = Find(arrSub,G->edge[i].src);
		int yRoot = Find(arrSub,G->edge[i].dest);
		
		if(xRoot==yRoot)
			return true;

		Union(arrSub,xRoot,yRoot);
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
