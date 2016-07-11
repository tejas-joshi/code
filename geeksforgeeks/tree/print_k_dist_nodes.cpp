//==== PRINT THE NODES AT THE DISTANCE OF K FROM ROOT..

/*
Root is at distance 0.. 

Logic :
BFS will do this but the recursive function written here is nice..
Just refer it..

TC : O(n)	// case where k is height of the tree
SC : O(k)	// 		""
*/

#include<iostream>
using namespace std;

struct node_n
{
	int data;
	struct node_n *left,*right;
};

typedef struct node_n node;

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

void printKDist(node *nd,int k)
{
	if(nd)	// if notnull then continue...
		if(k==0)	// the level we want to print
			cout << nd->data << " ";
		else
		{
			printKDist(nd->left,k-1);
			printKDist(nd->right,k-1);
		}
}	

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,1);
	insert(&root,4);
	insert(&root,7);
	insert(&root,9);

	int k;
	cin >> k;
	printKDist(root,k);
	cout << endl;

	return 0;
}	
