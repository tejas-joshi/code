// Convert a given Binary Tree to Doubly Linked List

/*
1) Fix Left Pointers: 
	In this step, we change left pointers to point to previous nodes in DLL. 
	The idea is simple, we do inorder traversal of tree. In inorder traversal, 
		we keep track of previous visited node and change left pointer to the previous node. 

2) Fix Right Pointers: 
	The idea is to use left pointers fixed in step 1. 
	We start from the rightmost node in Binary Tree (BT). 
	The rightmost node is the last node in DLL. 
	Since left pointers are changed to point to previous node in DLL, we can linearly traverse the complete DLL using these pointers. 
	The traversal would be from last to first node. 
	While traversing the DLL, we keep track of the previously visited node and change the right pointer to the previous node. 
	
TC : O(n)
SC : O(height of tree)	
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

void insert(node **root,int data)
{
	if(!(*root))
		*root = createNode(data);
	else if((*root)->data > data)
		insert(&((*root)->left),data);
	else
		insert(&((*root)->right),data);
}

// this function sets the left pointers of each node for DLL
void inorder(node *root)
{
	static node *prev = NULL;
	if(root)
	{
		inorder(root->left);
		
		root->left = prev;
		prev = root;
		
		inorder(root->right);
	}
}

// this function sets the right pointers of each node for DLL
void joinRightPtrs(node **root)
{
	if(!(*root))
		return;
		
	// go to right most node of BT which will be last node of DLL	
	node *nd = *root;
	while(nd && nd->right)
		nd = nd->right;
		
	// setting the right pointers 	
	node *prev=nd;
	while(prev && prev->left)
	{
		prev = nd->left;
		prev->right = nd;
		nd = nd->left;
	}
	*root = nd;
}

void BTToDLL(node **root)
{
	inorder(*root);			// for left pointer
	joinRightPtrs(root);	// for right pointer
} 

// prints DLL
void printDLL(node *head)
{
	while(head)
	{
		cout << head->data << " ";
		head = head->right;
	}
}

int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,3);
	insert(&root,4);
	insert(&root,1);
	insert(&root,7);
	insert(&root,6);
	insert(&root,9);
	BTToDLL(&root);
	printDLL(root);	
	return 0;
}
