#include<iostream>
using namespace std;

struct node_n
{
	int dest;
	struct node_n *next;
};

struct nodeList_l
{
	struct node_n *head;
};

struct graph_g
{
	int V;
	struct nodeList_l *ndList;
};

typedef struct node_n node;
typedef struct nodeList_l nodeList;
typedef struct graph_g graph;

graph *makeGraph(int V)
{
	graph *tempG = new graph;
	tempG->V = V;
	tempG->ndList = new nodeList[V];

	for(int i=0;i<V;i++)
		tempG->ndList[i].head = NULL;
	return tempG;
}

node *makeNode(int dest)
{
	node *tempN = new node;
	tempN->dest = dest;
	tempN->next = NULL;
	return tempN;
}

void addEdge(int src,int dest,graph *g)
{
	node *nd = makeNode(dest);
	nd->next = g->ndList[src].head;
	g[src]->ndList.head = nd;

	nd = makeNode(src);
	nd->next = g[dest].ndList.head;
	g->ndList[dest].head = nd;
}

void printGraph(graph *g)
{
	cout << " Printing Graph : " << endl;
	for(int i=0;i<g->V;i++)
	{
		cout << " source : " << i << endl;
		cout << " destinations : ";

		node *temp = g->ndList[i].head;
		while(temp)
		{
			cout << temp->dest << ",";
			temp = temp->next; 
		}
	}
}

int main()
{
	int V;
	cin >> V;
	graph *g = makeGraph(V);

	int src,dest;
	while(1)
	{
		cin >> src >> dest;
		if(src==-1 && dest==-1)
			break;
		addEdge(src,dest,g);	
	}
	return 0;
}
