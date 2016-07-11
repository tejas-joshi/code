//======= FIND SIZE OF TREE ( NO. OF NODES IN TREE )

/******

Logic :
no. of nodes = 1 + (nodes in left subtree) + (nodes in right subtree)

TC : O(n)
SC : O(height)

BETTER SOLUTIONS:
================
If iterative solutions is asked then BFS,DFS can also give no. of nodes. They will take space...
* If space is also not allowed then use Inroder traversal for counting..( Increment the count where you are printing the element. )...BINGO...  

******/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode (int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if((*nd)==NULL)
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

int size(node *nd)
{
	if(!nd)
		return 0;
	else
		return 1 + size(nd->left) + size(nd->right);
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);
	
	cout << size(root) << endl;	
	
	return 0;
}
