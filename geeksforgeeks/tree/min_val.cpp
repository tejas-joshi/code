//======= FIND MINIMUM OF BST ( NO. OF NODES IN TREE )

/******
There are two logics for that . Read both of them...
Second one is optimized.

Logic :
* Go to left most node.
* Print it.

TC : O(n) (worst case)
SC : O(height)

OPTIMIZED CODE IS JUST 4 LINES OF CODE WHICH IS RECURSIVE...
which will have TC : O(n) (in the case of left skewed BST) 
				SC : O(1) 
node *nd = root;
while(nd->left)
	nd = nd->left;
cout << nd->data << endl;

******/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node_s
{
	int data;
	struct node_s *left,*right;
};

typedef struct node_s node;

node *makeNode (int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if((*nd)==NULL)
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

int min(node *nd)
{
	if(!nd)
		return -1;
	else if(nd->left)
		return min(nd->left);
	else
		return nd->data;
}

int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);
	
	cout << min(root) << endl;	
	
	return 0;
}
