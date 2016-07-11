// Convert an arbitrary Binary Tree to a tree that holds Children Sum Property

/*
You can only increment data values in any node (You cannot change structure of tree and cannot decrement value of any node).

For example, the below tree doesn’t hold the children sum property, convert it to a tree that holds the property.

             50
           /     \     
         /         \
       7             2
     / \             /\
   /     \          /   \
  3        5      1      30

Algorithm:
=========
Traverse given tree in post order to convert it, 
i.e., first change left and right children to hold the children sum property then change the parent node.

Let difference between node’s data and children sum be diff.

diff = node’s children sum - node’s data  

If diff is 0 then nothing needs to be done.

If diff > 0 ( node’s data is smaller than node’s children sum) increment the node’s data by diff.

If diff < 0 (node’s data is greater than the node's children sum) then increment one child’s data. 
We can choose to increment either left or right child if they both are not NULL. 
Let us always first increment the left child. 
Incrementing a child changes the subtree’s children sum property so we need to change left subtree also. 
So we recursively increment the left child. If left child is empty then we recursively call increment() for right child.

Let us run the algorithm for the given example.

First convert the left subtree (increment 7 to 8).

             50
           /     \     
         /         \
       8             2
     / \             /\
   /     \          /   \
  3        5      1      30

Then convert the right subtree (increment 2 to 31)

          50
        /    \     
      /        \
    8            31
   / \           / \
 /     \       /     \
3       5    1       30

Now convert the root, we have to increment left subtree for converting the root.

          50
        /    \     
      /        \
    19           31
   / \           /  \
 /     \       /      \
14      5     1       30

TC : O(n^2)

*/


#include<iostream>
using namespace std;

typedef struct node 
{
	int data;
	node *left,*right;
} node;

node *createNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// This function is used to increment subtree by diff
void increment(node *nd,int diff)
{
	// left child is not NULL then increment it
	if(nd->left)
	{
		nd->left->data = nd->left->data + diff;
		increment(nd->left,diff);
	}
	else if(nd->right)
	{
		nd->right->data = nd->right->data + diff;
		increment(nd->right,diff);
	}
}

void convertToChildrenSum(node *nd)
{
	// empty tree OR leaf node
	if(!nd || (!nd->left && !nd->right))
		return;
	
	int leftData=0,rightData=0;
	
	// convert left and right subtree
	convertToChildrenSum(nd->left);
	convertToChildrenSum(nd->right);	

	// we will come here for the first time when the we will be at 1 level above leaf level
		
	if(nd->left)
		leftData = nd->left->data;
	if(nd->right)
		rightData = nd->right->data;
	
	int diff = leftData + rightData - nd->data;

	// If node's children sum is greater than the node's data
	if(diff>0)
		nd->data = nd->data + diff;
	// If node's data is greater than children sum, then increment subtree by diff
	else if(diff<0)
		increment(nd,-diff);	// -diff is used to make diff positive
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

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = createNode(data);
	else if((*nd)->data < data)
		insert(&((*nd)->right),data);
	else
		insert(&((*nd)->left),data);		
}
	
int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,1);
	insert(&root,7);
	insert(&root,9);
	insert(&root,6);
	insert(&root,10);
	
	inorder(root);
	convertToChildrenSum(root);
	cout << endl;
	inorder(root);
	
	return 0;
}
