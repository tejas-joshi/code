#include<iostream>
#include<stdlib.h>
using namespace std;



typedef struct edge_s
{
	int src,dest,w;
} Edge;

typedef struct Graph_s
{
	int E,V;
	Edge *edge;
} Graph;

Graph *createGraph(int E,int V)
{
	Graph *temp = new Graph;
	temp->E = E;
	temp->V = V;
	temp->edge = new Edge[E];
	return temp;
}

int compare(const void *a,const void *b)
{
	return (* (Edge *) a).w > (* (Edge *)b).w;
}

typedef struct subset_s
{
	int parent,rank;
} subset;

int Find(subset *arrSub,int i)
{
	if(arrSub[i].parent!=i)
		return Find(arrSub,arrSub[i].parent);
	return arrSub[i].parent;
}

void Union(subset *arrSub, int xRoot, int yRoot)
{
	if(arrSub[xRoot].rank > arrSub[yRoot].rank)
		arrSub[yRoot].parent = xRoot;
	else if(arrSub[xRoot].rank < arrSub[yRoot].rank)
		arrSub[xRoot].parent = yRoot;
	else
	{
		arrSub[xRoot].parent = yRoot;
		arrSub[yRoot].rank++;
	}	
}

void KruskalMST(Graph *G)
{
	int E,V;
	E = G->E;
	V = G->V;
	
	subset *arrSub = new subset[V];	
	for(int v=0;v<V;v++)
	{
		arrSub[v].parent = v;
		arrSub[v].rank = 0;
	}
	
	qsort(G->edge,E,sizeof(Edge),compare);

	int v=0,e=0,i=0;
	Edge *resultE = new Edge[E];
	
	while(e<V-1)
	{
		int xRoot = Find(arrSub,G->edge[i].src);
		int yRoot = Find(arrSub,G->edge[i].dest);
		if(xRoot!=yRoot)
		{
			resultE[e] = G->edge[i];
			e++;
			Union(arrSub,xRoot,yRoot);
		}	
		
		i++;
	}
	
	for(int e=0;e<V-1;e++)
		cout << resultE[e].src << " " << resultE[e].dest << endl;
}

int main()
{
	int E,V,src,dest,w;
	cin >> E >> V;

	Graph *G = createGraph(E,V);
	
	for(int e=0;e<E;e++)
	{
		cin >> src >> dest >> w;
		G->edge[e].src = src;
		G->edge[e].dest = dest;
		G->edge[e].w = w;
	}
	
	
	KruskalMST(G);
	
	
	
	return 0;
}
