// ==== FIND MAXIMUM ROOT TO LEAF PATH SUM

// LOGIC IN COMMENTS

// TC : O(n)
// SC : O(height) (stack space)

// Iterative solution will be using BFS and storing sum on each level in the queue.. 
// Comparing with the max when popping up the leaf node else continue..
// TC : O(n)
// SC : O(n) // max nodes in the leaf level is (n/2)

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
		*nd = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

int max_sum(node *nd)
{
	if(!nd)	// null nodes
		return 0;
	else if(nd->left && nd->right)	// both children ... current + max(left,right)
		return nd->data + max(max_sum(nd->left),max_sum(nd->right));
	else if(nd->left)		// left child... current + left
		return nd->data + max_sum(nd->left);	
	else if(nd->right)		// right child... current + right
		return nd->data + max_sum(nd->right);
	else                    // leaf node... current
		return nd->data;
}

int main()
{
	node *root = NULL;
	insert(&root,7);
	insert(&root,4);
	insert(&root,1);
	insert(&root,9);
	insert(&root,6);

	cout << max_sum(root) << endl;	

	return 0;
}
