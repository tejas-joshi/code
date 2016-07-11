// === CHECK WHETHER TREE IS COMPLETE.

/***

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, 
* and all nodes are as far left as possible. See following examples.

The following trees are examples of Complete Binary Trees
    1
  /   \
 2     3
  
       1
    /    \
   2       3
  /
 4


the following tree is not complete tree.
	  1
    /    \
   2       3
    \     /  \   
     4   5    6


Logic:
=====
BFS is modified to solve this problem.
See code and comments for further logic.

***/

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode(int data)
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

bool checkComplete(node *nd)
{
	queue<node *> Q;

	if(nd)
		Q.push(nd);
	else
		return true;

	// making true this variable indicates node with (left is not null) and (right is null) is found.
	bool checkForNull=false;

		
	while(!Q.empty())
	{
		node *t = Q.front();

		Q.pop();
		if(t->left && t->right)		// both are not null push them and continue
		{
			Q.push(t->left);
			Q.push(t->right);
			continue;
		}
		else if(!(t->left) && t->right)		// if left is null and right is not then it's not complete tree
			return false;
		else if(t->left && !(t->right))		// if right is null and left is not then pushed all nodes must be leaves for complete tree case
		{
			Q.push(t->left);
			checkForNull = true;
		}

		
		if(checkForNull)	// if true then check all the pushed nodes are leaf nodes of not.. it not then it's not complete tree...
			while(!Q.empty())
			{
				node *temp = Q.front();
				if(temp->left || temp->right)
					return false;
				Q.pop();
			}
	}
	return true;
}



int main()
{
	node *root = NULL;
	insert(&root,7);
	insert(&root,4);
	insert(&root,9);
	insert(&root,1);
	insert(&root,8);
	insert(&root,5);
//	insert(&root,10);

	cout << checkComplete(root) << endl;		
	
	return 0;
}
