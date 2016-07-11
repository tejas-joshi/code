//===== CHECK IF THE GIVEN TREE IS BST OR NOT

/*
Given a binary tree, check whether it is BST or not..

Logic : 
We have to maintain min and max for node then check the data of current node is between them and recursively for left and right.
While going to right update min because in right subtree, all elements must be greater than current element.
While going to left update max because in left subtree, all elements must be lesser than current element.

if node is null then 
	true
else
	nd->data>min  && nd->data<max && isBST(nd->left,min,nd->data) && isBST(nd->right,nd->data,max)

TC : O(n)
SC : O(height)	// stack space
*/

#include<iostream>
#include<limits.h>
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
	return temp;
}

bool checkBST(node *nd,int min,int max)
{
	if(!nd)
		return true;
	return ( (nd->data)>min && (nd->data)<max && checkBST(nd->left,min,nd->data) && checkBST(nd->right,nd->data,max) );
	// checking the data in the range and check for left and check for right...
}

int main()
{
	node *root=NULL;
	root = makeNode(1);
	root->left = makeNode(3);
	root->right = makeNode(7);
	root->left->right = makeNode(4);
	root->right->right = makeNode(10);

	cout << checkBST(root,INT_MIN,INT_MAX) << endl;

	return 0;
}

