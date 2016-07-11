//====== BUILD BST FROM THE GIVEN PREORDER ARRAY

/*

e.g.
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

    10
   /  \
  5    40
 /  \   \
1    7   50  

Logic :
In the code...
Here we have used static variable for index of the array..
If it's not allowed then create a variable in main function and pass the address in the function...

NICE LOGIC... YOU WILL ENJOY THE ALGO... :)

TC : O(n)
SC : O(height)

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

node *buildBST(int *pre,int len,int min,int max)
{
	static int preIndex=0;		// starting from the first element in pre array

	if(preIndex>=len)			// if index crosses the length
		return NULL;

	node *t = NULL;				// t will be the root of current tree.. initialize to NULL in case of no element in the range
	int key = pre[preIndex];	// key to be checked in the range

	if(key>min && key<max)	// key is in the range... if key is not in the range then NULL will be return because t is currently NULL..
	{
		t = makeNode(key);	// create node 
		preIndex++;			// go to next element in the array
		
		t->left = buildBST(pre,len,min,key);	// setting left by updating the max range as key
		t->right = buildBST(pre,len,key,max);	// setting right by updating the min range as key
	}
	return t;	// returning the root
}

int main()
{
	int pre[] = {10, 5, 1, 7, 40, 50};

	node *root = buildBST(pre,6,INT_MIN,INT_MAX);	// RANGES ARE USED TO MAINTAIN THE PROPERTY OF BST...
	inorder(root);
	
	return 0;
}
