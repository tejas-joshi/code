// ======== COUNT NO. OF LEAVES IN TREE

/*******

LOGIC :

int count(nd)
{
	if(nd is null)  // this handle the cases when tree has no nodes, nodes with only one child
		return 0;
	else if( nd->left is null && nd->right is null) // leaf node
		return 1;
	else
		return (leaves in leftsubtree) + (leaves in right subtree)
}


TC : O(n)
SC : O(height)	(stack space)

*******/

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

int countLeaves(node *nd)
{
	if(!nd)		// handles cases when (if tree has no nodes),(nodes with only one child)
		return 0;
	else if(!(nd->left) && !(nd->right))	// leaf node
		return 1;
	else         // non leaf nodes
		return countLeaves(nd->left) + countLeaves(nd->right);
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	cout << countLeaves(root) << endl;
	
	return 0;
}
