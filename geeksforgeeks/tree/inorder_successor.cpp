//====== FIND INORDER SUCCESSOR OF THE NUMBER FROM BST

/*
 
Given a BST, find the inorder successor.

Logic:
1) Find the number and store the address of the node. let say nd.
2) If right of nd is not null then go to left most in right child. return it..
	else
		Find number from root and store the node in the path. in the end return it..

TC : O(n)	// in the case of skew tree
SC : O(n)	// search will take n in case of skew tree

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

void insert(node **nd,int data)
{
	if(!(*nd))
		*nd = makeNode(data);
	else if((*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

// searches d in the BST and returns the address of node
node *search(node *root,int d)
{
	if(!root)
		return NULL;
	else if(root->data==d)
		return root;
	else if(root->data<d)
		return search(root->right,d);
	else
		return search(root->left,d);
}

// go to left most of nd... otherwise nd
node * minValue(node* nd)
{	
	while (nd->left)
		nd=nd->left;
	return nd;
}

node *inOrderSuccessor(node *root,int d)
{
	node *n = search(root,d);	// n will node with data d..
	
	// this is the case when successor is below the node containing d
	if(n->right)	// Assuming n is not null ( d is always there in BST )
		return minValue(n->right);		// go to left most in right child

	// this is the case where successor is above the node containing d
	
	// else find d in the tree
	node *succ=NULL;
	while(root)
	{
		// Here we are trying to find the node which has the value just higher than d...
		// So if we get the value higher than d then we come to left hoping to get the lower value but higher value than d... so update the succ
		
		// else if condition is for the case when the current node is having value less than d
		// we can't update succ until we get higher value than d so here we are not changing succ.
		
		if(d < root->data)
		{
			succ=root;		// updating succ
			root=root->left;
		}
		else if(d > root->data)
			root=root->right;
		else
			break;
	}
	return succ;
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,1);
	insert(&root,9);
	insert(&root,4);

	int n;
	cin >> n;
	cout << inOrderSuccessor(root,n)->data << endl;
	
	return 0;
}
