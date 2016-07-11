//==== FIND THE MAX. HEIGHT/DEPTH OF TREE

/********

Two methods are descibed here..

LOGIC :
(height of tree) = 1 + max(height of left sub-tree,height of right subtree)

TC : O(n)
SC : O(height)   (stack space)

Iterative method is using BFS and count the number of levels which is pushed... that will be the height of the tree...

TC : O(n)
SC : O(n)	// max nodes in the leaf level is n/2

********/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};
typedef struct node_s node;

node *makeNode(int data)
{
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

int height(node *nd)
{
	if(!nd)
		return 0;
	else
		return 1 + max(height(nd->left),height(nd->right));
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

	cout << height(root) << endl;
	
	
	return 0;
}
