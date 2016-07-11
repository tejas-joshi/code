//====== CONVERT BINARY TREE TO BINARY SEARCH TREE

/*

Given a Binary Tree, convert it to a Binary Search Tree.
The conversion must be done in such a way that keeps the original structure of Binary Tree.

Examples.

Example 1
Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7

Logic :

1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
2) Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm.
	In the following implementation, Quick Sort is used which takes (n^2) time.
	This can be done in O(nLogn) time using Heap Sort or Merge Sort.
3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step takes O(n) time.

TC : O(nlogn)  (n + nlogn + n)
SC : O(n) // extra array

*/

#include<iostream>
#include<stdlib.h>

using namespace std;
struct node_n
{
	int data;
	struct node_n *left,*right;
};
typedef struct node_n node;


int compare(const void *a,const void *b)
{
	return (*(int *)a) > (*(int *)b);
	// swaps when returns true
}

node *makeNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if( (*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

int countNodes(node *nd)
{
	if(!nd)
		return 0;
	else
		return 1 + countNodes(nd->left) + countNodes(nd->right);
}

void inorderFill(node *nd,int *arr,int *ind)
{
	if(nd)
	{
		inorderFill(nd->left,arr,ind);

		arr[*ind]=nd->data;
		(*ind)++;

		inorderFill(nd->right,arr,ind);
	}
}

void inorderSet(node *nd,int *arr,int *ind)
{
	if(nd)
	{
		inorderSet(nd->left,arr,ind);

		nd->data = arr[*ind];
		(*ind)++;

		inorderSet(nd->right,arr,ind);
	}
}

void convertBTtoBST(node **root)
{
	int n = countNodes(*root);	// count nodes for array size
	int ind=0,*arr;
	arr = new int[n];

	inorderFill(*root,arr,&ind);	// function for fill the elements of tree into array.. .passing the reference to the index also..

	qsort(arr,n,sizeof(int),compare);	// sort the array

	ind=0;		// resetting the index
	inorderSet(*root,arr,&ind);		// function to set the array elements into tree nodes which will be BST
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


int main()
{
	node *root=NULL;
	root = makeNode(10);
	root->left = makeNode(2);
	root->right = makeNode(7);
	root->left->left = makeNode(8);
	root->left->right = makeNode(4);

	convertBTtoBST(&root);
	inorder(root);
	cout << endl;				
	
	return 0;
}
