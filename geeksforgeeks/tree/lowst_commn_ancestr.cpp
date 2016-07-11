//== LOWEST COMMON ANCESTOR OF TWO NODES

/*****

LOGIC :
=====
* Tree has no nodes then return -1
* Check with current data of node.
	if (both elements > current data)
		ans will be in right sub tree
	else if(both elements < current data)
		ans will be in left subtree
	else
		(this is the node where one is in left subtree and another in right subtree)
		make sure both exists in the tree
		if so return current data
		else return -1

TC : O(n)
SC : O(height) (stack space)

*****/		

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

bool search(node *nd,int data)		// checks whether element exists in tree
{
	if(!nd)
		return false;

	if(nd->data==data)
		return true;
	else if(nd->data<data)
		return search(nd->right,data);
	else
		return search(nd->left,data);
}	

int comm_anc(node *nd,int data1,int data2)
{
	if(!nd)		// tree has no nodes
		return -1;
	else if(nd->data < data1 && nd->data < data2)	// both elements are in right sub-tree
		return comm_anc(nd->right,data1,data2);
	else if(nd->data > data1 && nd->data > data2)	// both elements are in left sub-tree
		return comm_anc(nd->left,data1,data2);
	else                                            // one element is in left subtree and other in right subtree
		if(search(nd,data1) && search(nd,data2))	// to make sure both elements are in tree
			return nd->data;
		else                                        // one or both elements are not in tree
			return -1;
}




int main()
{
	node *root = NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,7);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	cout << comm_anc(root,9,1) << endl;

	return 0;
}	
