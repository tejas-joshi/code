//====== FIND INORDER PREDECESSOR OF THE NUMBER FROM BST
//		( YOU WILL NEVER FORGET THIS QUESTION )

/*
 
Given a BST, find the inorder predecessor.

Logic:
1) Find the number and store the address of the node. let say nd.
2) If left of nd is not null then go to right most in left child. return it..
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
	else if( (*nd)->data>data)
		insert(&((*nd)->left),data);
	else
		insert(&((*nd)->right),data);
}

// searches d in BST
node *search(node *root,int d)
{
	if(!root)
		return NULL;
	else if(root->data == d)
		return root;
	else if(root->data < d)
		return search(root->right,d);
	else
		return search(root->left,d);
}

// go to right most of nd.. if not then nd will be returned..
node *maxValue(node *nd)
{
	// dont worry about the condition of nd==NULL because it was checked before this function was called.
	while(nd->right)
		nd = nd->right;
	return nd;
}

node *inOrderPredecessor(node *root,int d)
{
	node *n = search(root,d);	// n is the node with data d..
		
		
	// This is the case when the predecessor is below the node which was searched...
	if(n->left)		// Assuming d is surely available otherwise put a condition for checking n==null 
		return maxValue(n->left);	// go to right most in left child

	// this is the case when the predecessor is above the level of the node which was searched.
	// else find it in the tree
	node *pred = NULL;
	while(root)
	{
		// Here.. we are going close to d on each iteration... we are trying to find the highest element which is less than d..
		// So in if condition d is greater so we update pred and going to right for higher value..
		
		// for the else if condition.. we got the higher value than d so go to left for lesser value... 
			// we cant update the pred until we get the lower value than d
			// the value higher than d should not make any diff. on predecessor of d.
		
		if(d > root->data)	// updating pred .. go to right because we want to go to d as close as possible..
		{
			pred = root;
			root = root->right;
		}
		else if(d < root->data)	// we got higher value than d so go to left..
			root = root->left;
		else
			break;
	}
	return pred;
}


int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,7);
	insert(&root,9);
	insert(&root,1);

	int n;
	cin >> n;
	
	// Assuming n is there in the tree.. so make sure to add the condition for NULL check...
	cout << inOrderPredecessor(root,n)->data << endl;
	
	return 0;
}
