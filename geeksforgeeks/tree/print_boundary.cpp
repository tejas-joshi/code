//======= PRINT ELEMENTS OF TREE IN BOUNDARY (ANTICLOCKWISE)

/*
		7
	  /   \
	4  		9
   / \	   / \
  1   5   8	  10
       \
     	6

	OUTPUT : 7 4 1 6 8 10 9
*/

/***

LOGIC :
=====
1) print left boundary in top to bottom manner.	(using preorder)
2) print all leaves in left to right manner.	(using logic of printing leaves)
3) print right boundary in bottom to up manner.	(using postorder)

TAKE CARE:
1) Nodes which are in more than one section should not be printed twice. ( 1 in last example which is in (1) and (2) both)
2) While calling from printBoundaries function root should be printed (look into it).

TC : O(n)
SC : O(height)	(stack space)

***/

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

// LEFT BOUNDARY
void printLeftBoundary(node *nd)
{
	if(nd)
	{
		if(nd->left)	// go to extreme left
		{
			// Here print then call is for top to bottom printing
			cout << nd->data << " ";
			printLeftBoundary(nd->left);	
		}
		else if(nd->right)	// if left is null then go to right
		{
			// Here print then call is for top to bottom printing
			cout << nd->data << " ";
			printLeftBoundary(nd->right);
		}
		
		// else part will be for leaves which we are not printing so avoiding printing twice...
	}

}

// PRINT LEAVES
void printLeaves(node *nd)
{
	if(nd)
	{
		// first print left subtree leaves
		printLeaves(nd->left);

		// if current node is leaf then print
		if(!nd->left && !nd->right)
			cout << nd->data << " ";

		// print right subtree leaves
		printLeaves(nd->right);
	}
}

// RIGHT BOUNDARY
void printRightBoundary(node *nd)
{
	if(nd)
	{
		if(nd->right)	// go to right sub tree
		{
			// Here call then print is for bottom to up printing
			printRightBoundary(nd->right);	
			cout << nd->data << " ";			
		}
		else if(nd->left)	// if right is null then go to left
		{
			// Here call then print is for bottom to up printing
			printRightBoundary(nd->left);
			cout << nd->data << " ";
		}
	}
}

void printBoundary(node *nd)
{
	if(nd)
	{
		printLeftBoundary(nd);	// nd to consider root for printing
		printLeaves(nd);		// print leaves
		printRightBoundary(nd->right);	// nd->right instead of nd is to avoid root to print twice.
	}
}

int main()
{
	node *root = NULL;
	
	insert(&root,4);
	insert(&root,1);
	
	//~ insert(&root,7);
	//~ insert(&root,4);
	//~ insert(&root,9);
	//~ insert(&root,1);
	//~ insert(&root,5);
	//~ insert(&root,8);
	//~ insert(&root,10);

	printBoundary(root);

	return 0;
}
