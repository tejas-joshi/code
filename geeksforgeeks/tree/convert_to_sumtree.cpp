//====== CONVERT A GIVEN TREE TO SUMTREE

/*
Given a Binary Tree where each node has positive and negative values.
Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree.
The values of leaf nodes are changed to 0.

For example, the following tree

                  10
               /      \
			 -2        6
           /   \      /  \ 
		 8     -4    7    5

should be changed to

               20(4-2+12+6)
               /      \
			4(8-4)      12(7+5)
           /   \      /  \ 
		  0      0    0    0

Logic :
Do a traversal of the given tree. In the traversal, store the old value of the current node,
recursively call for left and right subtrees and change the value of current node as sum of the values returned by the recursive calls.
Finally return the sum of new value and value (which is sum of values in the subtree rooted with this node).

TC : O(n)
SC : O(height)
*/

#include<iostream>
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
}


void inorder(node *nd)
{
	if(nd)
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
	}
}

int BTtoSumTree(node *nd)
{
	if(!nd)
		return 0;
		
	int oldVal = nd->data;	// storing old value
	
	// setting the data of current node as the sum of left subtree and right subtree
	nd->data = BTtoSumTree(nd->left) + BTtoSumTree(nd->right);

	// returning the sum of old and new values... this will be used by the parent because it's returning the sum of whole tree..
	// i.e. nd->data is having sum of left and right subtree + oldVal is having the data of current node...
	return oldVal + nd->data;			
}

int main()
{
	node *root=NULL;
	root = makeNode(10);
	root->left = makeNode(-2);
	root->right = makeNode(6);
	root->left->right = makeNode(-4);
	root->left->left = makeNode(8);
	root->right->left = makeNode(7);
	root->right->right = makeNode(5);

	BTtoSumTree(root);
	inorder(root);
	cout << endl;
	
	return 0;
}
