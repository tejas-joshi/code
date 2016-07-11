//===== CHECK FOR SUM-TREE

/**

A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree
and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0.
A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3

Here one thing to note that if the child is nonleaf then consider its double to check for current data.
If the node is leaf then it's true.
More logic in comments...

Check the complexity for the recursive solution,,

----------------------------

Another solution is to use BFS and checking the sum all the times while pushing the children of the node.
So the sum property will be always be taken care...

TC : O(n)
SC : O(n)

**/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node* makeNode(int data)
{
	node *t = new node;
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

bool isLeaf(node *nd)
{
	if(!nd)
		return false;
	else if(!(nd->left) && !(nd->right))
		return true;
	else
		return false;		
}

bool checkSum(node *nd)
{
	if(!nd || isLeaf(nd))	// if node is null OR leaf then it's true.
		return true;

	if(checkSum(nd->left) && checkSum(nd->right))
	{
		int l,r;

		if(!(nd->left))		// if there's no left node then left-sum=0
			l=0;
		else if(isLeaf(nd->left))	// if left child is leaf then take its value to consider
			l = nd->left->data;
		else                    // if left child is nonleaf then consider double of left child's value to consider
		// the reason behind double for nonleaf is that node is also having the same sum below it.
			l = 2*(nd->left->data);

		// same for right child
		if(!(nd->right))		
			r=0;
		else if(isLeaf(nd->right))
			r = nd->right->data;
		else
			r = 2*(nd->right->data);

		return (nd->data==(l+r));	// checking the value of left+right == current
	}
	return false;
}	


int main()
{
//	node *root = NULL;

	node *root  = makeNode(26);
    root->left         = makeNode(10);
    root->right        = makeNode(3);
    root->left->left   = makeNode(4);
    root->left->right  = makeNode(6);
    root->right->right = makeNode(3);
/*
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);
*/
	cout << checkSum(root) << endl;
	
	return 0;
}
