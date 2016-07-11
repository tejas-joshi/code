// BTREE TRAVERSALS

/******
INORDER , PREORDER , POSTORDER

TC : O(n) // no. of nodes 
SC : O(1) // (not considering recursion space)
SC : O(height of btree) // (considering stack space)

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

node *makeNode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data =data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node **nd,int data)
{
	if(*nd==NULL)
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

node *search(node **nd,int data)
{
	if((*nd)->data==data || *nd==NULL)
		return *nd;
	else if((*nd)->data<data)
		return search(&(*nd)->right,data);
	else
		return search(&(*nd)->left,data);
}

void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

void preorder(node *root)
{
	if(root)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}


int main()
{
	node *root=NULL;
	insert(&root,5);
	insert(&root,7);
	insert(&root,4);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	
	return 0;
}
