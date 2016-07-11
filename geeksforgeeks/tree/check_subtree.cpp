// ======= CHECK WHETHER n2 is subtree of n1.

/***
======= LOGIC
* At every node we are checking whether this tree is identical to n2 or not.
* If it is true then
 	return true;
 else
	check for left subtree of n1 and right subtree of n1 ( If any one contains n2 or not )

TC : O(n^2)			// case when S and T has all the elements with same value x in whole tree except some leaf node...
SC : O(height) (stack space)

think for some other solution... checking subarray is one solution but the structure also matters so it wont work or need somethink to be added to it
* 	to make it work for this problem...

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

// CHECK WHETHER TWO TREES ARE IDENTICAL OR NOT
bool isIdentical(node *nd1,node *nd2)
{
	if(!nd1 && !nd2)
		return true;
	else if(nd1 && nd2)
		return ((nd1->data==nd2->data)) && isIdentical(nd1->left,nd2->left) && isIdentical(nd1->right,nd2->right);
	else
		return false;
}

// CHECKS WHETHER n2 IS SUBTREE OF n1 OR NOT.
bool isSubtree(node *n1,node *n2)
{
	if(!n2)		// If n2 is null then it's always true... 
		return true;
	if(!n1)		// If n2 is not null and n1 is null then we can't find so false
		return false;
		
	if(isIdentical(n1,n2))		// Every node we are checking for identical... 
		return true;
	else                      // if this tree is not identical then check for left and right subtree and ORing of them...
		return isSubtree(n1->left,n2) || isSubtree(n1->right,n2);
}

int main()
{
	node *root1 = NULL;
	insert(&root1,5);
	insert(&root1,4);
	insert(&root1,1);
	insert(&root1,7);
	insert(&root1,6);
	insert(&root1,9);

	node *root2 = NULL;
	insert(&root2,7);
	insert(&root2,6);
	insert(&root2,9);
		
	cout << isSubtree(root1,root2) << endl;
	
	return 0;
}	
