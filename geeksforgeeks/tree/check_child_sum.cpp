// === CHECK IF CHILD SUM PROPERTY HOLDS IN BTREE

/*********

Child Sum property is satisfied if the element at node is the sum of all of its left child and right child (just next level ).
Sum tree property is satisfied if the element at node is the sum of all of its children (all the levels below current).

LOGIC :
=====
* if
* 	(node is null) or (it is leaf) then it is true
* else
* 	if left child is null
* 		leftNum=0
* 	else
* 		leftNum = element at left child
* 
*   if right child is null
* 		rightNum=0
* 	else
* 		rightNum = element at right child
*
* 	return
	   check (leftNum+rightNum==current data)
	   && check left subtree for child sum property
	   && check right subtree for child sum property

TC : O(n)
SC : O(height) (stack space)

This problem can also be solved using BFS.. if you want it to be iterative.

**********/ 


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
	
bool check_childSum(node *nd)
{
	if(!nd || (!nd->left && !nd->right))
		return true;
	else
	{
		int lNum=0,rNum=0;

		if(nd->left)
			lNum = nd->left->data;
		if(nd->right)
			rNum = nd->right->data;
	
		return ((nd->data)==(lNum+rNum) && check_childSum(nd->left) && check_childSum(nd->right));
	}	
}

void inorder(node *nd)
{
	if(!nd)
		return;
	else
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
	}
}

int main()
{	
	node *root = NULL;
	root  = makeNode(10);
	root->left         = makeNode(7);
	root->right        = makeNode(2);
	root->left->left   = makeNode(3);
	root->left->right  = makeNode(5);
	root->right->right = makeNode(2);

//	inorder(root);

	cout << check_childSum(root) << endl;
	
	return 0;
}
