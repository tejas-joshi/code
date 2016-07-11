//===== DELETE THE TREE

/**********

Logic :
* Delete left sub-tree
* Delete right sub-tree
* Delete current node

TC : O(n)
SC : O(height)

**********/


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
	node *t = (node *)malloc(sizeof(node));
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void insert(node **nd,int data)
{
	if(!(*nd))
		(*nd) = makeNode(data);
	else if((*nd)->data<data)
		insert(&(*nd)->right,data);
	else
		insert(&(*nd)->left,data);
}

void delete_tree(node **nd)
{
	if(!(*nd))
		return;

	delete_tree(&(*nd)->left);	
	delete_tree(&(*nd)->right);
	free(*nd);	
}

void inorder(node *nd)
{
	if(!nd)
		return;
	else
	{
		inorder(nd->left);
		cout << nd->data << " ";
		inorder(nd->right);
	}

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

	inorder(root);
	
	delete_tree(&root);
	root=NULL;

	cout << endl;
	inorder(root);

	return 0;
}
